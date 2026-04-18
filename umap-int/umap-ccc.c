#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ccc/flat_buffer.h"
#include "ccc/flat_hash_map.h"

struct pair {
  int key;
  int value;
};

static void *
my_alloc(CCC_Allocator_arguments const args)
{
  if (!args.input && !args.bytes) {
    return NULL;
  }
  if (!args.input) {
    return malloc(args.bytes);
  }
  if (!args.bytes) {
    free(args.input);
    return NULL;
  }
  return realloc(args.input, args.bytes);
}

static uint64_t
hash_int(CCC_Key_arguments const args)
{
  int const key_int = *(int const *)args.key;
  uint64_t x = (uint64_t)key_int;
  x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
  x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
  x = x ^ (x >> 31);
  return x;
}

static CCC_Order
cmp_int(CCC_Key_comparator_arguments const args)
{
  int const left = *(int const *)args.key_left;
  struct pair const *const right = args.type_right;
  return (left < right->key) ? CCC_ORDER_LESSER
       : (left > right->key) ? CCC_ORDER_GREATER
                             : CCC_ORDER_EQUAL;
}

static void
insert_or_die(CCC_Flat_hash_map *map, CCC_Allocator const *alloc, int key, int value)
{
  CCC_Entry const res = CCC_flat_hash_map_insert_or_assign(
      map, &(struct pair){.key = key, .value = value}, alloc);
  if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL) {
    abort();
  }
}

int main(void)
{
  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_hash_map map = CCC_flat_hash_map_default(
      struct pair,
      key,
      ((CCC_Hasher){.hash = hash_int, .compare = cmp_int}));

  insert_or_die(&map, &alloc, 17, 4585);
  insert_or_die(&map, &alloc, 42, 4856);
  insert_or_die(&map, &alloc, -9, 1452);

  struct pair const *it = CCC_flat_hash_map_get_key_value(&map, &(int){42});
  if (it != NULL) {
    printf("Value of 42 is %d\n", it->value);
  }

  for (struct pair const *i = CCC_flat_hash_map_begin(&map);
       i != CCC_flat_hash_map_end(&map);
       i = CCC_flat_hash_map_next(&map, i)) {
    printf("%d -> %d\n", i->key, i->value);
  }

  CCC_flat_hash_map_clear_and_free(&map, &(CCC_Destructor){}, &alloc);
  return 0;
}
