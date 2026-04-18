#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ccc/flat_buffer.h"
#include "ccc/flat_hash_map.h"

struct pair {
  char const *key;
  char const *value;
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
hash_str(CCC_Key_arguments const args)
{
  char const *const key = *(char const *const *)args.key;
  uint64_t hash = UINT64_C(1469598103934665603);
  for (unsigned char const *s = (unsigned char const *)key; *s != '\0'; ++s) {
    hash ^= (uint64_t)*s;
    hash *= UINT64_C(1099511628211);
  }
  return hash;
}

static CCC_Order
cmp_str(CCC_Key_comparator_arguments const args)
{
  char const *const left = *(char const *const *)args.key_left;
  struct pair const *const right = args.type_right;
  int const cmp = strcmp(left, right->key);
  return (cmp < 0) ? CCC_ORDER_LESSER
       : (cmp > 0) ? CCC_ORDER_GREATER
                   : CCC_ORDER_EQUAL;
}

static void
insert_or_die(
    CCC_Flat_hash_map *map, CCC_Allocator const *alloc, char const *key,
    char const *value
)
{
  CCC_Entry const res = CCC_flat_hash_map_insert_or_assign(
      map, &(struct pair){.key = key, .value = value}, alloc);
  if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL) {
    abort();
  }
}

int
main(void)
{
  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_hash_map map = CCC_flat_hash_map_default(
      struct pair,
      key,
      ((CCC_Hasher){.hash = hash_str, .compare = cmp_str}));

  insert_or_die(&map, &alloc, "Hello", "LIB");
  insert_or_die(&map, &alloc, "Welcome", "Program");
  insert_or_die(&map, &alloc, "Sincerely", "Your map");

  char const *lookup = "Welcome";
  struct pair const *it = CCC_flat_hash_map_get_key_value(&map, &lookup);
  if (it != NULL) {
    printf("Value of 'Welcome' is %s\n", it->value);
  }

  for (struct pair const *i = CCC_flat_hash_map_begin(&map);
       i != CCC_flat_hash_map_end(&map);
       i = CCC_flat_hash_map_next(&map, i)) {
    printf("%s --> %s\n", i->key, i->value);
  }

  CCC_flat_hash_map_clear_and_free(&map, &(CCC_Destructor){}, &alloc);
  return 0;
}