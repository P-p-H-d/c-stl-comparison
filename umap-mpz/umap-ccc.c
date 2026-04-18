#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

#include "ccc/flat_buffer.h"
#include "ccc/flat_hash_map.h"

struct pair {
  mpz_t key;
  mpz_t value;
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
hash_mpz(CCC_Key_arguments const args)
{
  mpz_t const *const z = args.key;
  mp_size_t n = (*z)->_mp_size;
  mp_limb_t const *p = (*z)->_mp_d;
  uint64_t hash = UINT64_C(0xcbf29ce484222325);
  if (n <= 0) {
    hash ^= UINT64_C(0x7F5C1458);
    if (n == 0) {
      return hash;
    }
    n = -n;
  }
  while (n-- > 0) {
    hash ^= (uint64_t)*p++;
    hash *= UINT64_C(0x100000001b3);
  }
  return hash;
}

static CCC_Order
cmp_mpz(CCC_Key_comparator_arguments const args)
{
  mpz_t const *const left = args.key_left;
  struct pair const *const right = args.type_right;
  int const cmp = mpz_cmp(*left, right->key);
  return (cmp < 0) ? CCC_ORDER_LESSER
       : (cmp > 0) ? CCC_ORDER_GREATER
                   : CCC_ORDER_EQUAL;
}

static void
insert_or_die(
    CCC_Flat_hash_map *map, CCC_Allocator const *alloc, mpz_srcptr key,
    mpz_srcptr value
)
{
  struct pair p;
  mpz_init_set(p.key, key);
  mpz_init_set(p.value, value);
  // WORKAROUND: p is implicitly moved into the map so we can't free it on exit.
  CCC_Entry const res = CCC_flat_hash_map_insert_or_assign(map, &p, alloc);
  if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL) {
    mpz_clear(p.key);
    mpz_clear(p.value);
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
      ((CCC_Hasher){.hash = hash_mpz, .compare = cmp_mpz}));

  mpz_t key1, key2, key3;
  mpz_t value1, value2, value3;
  mpz_init_set_si(key1, 17);
  mpz_init_set_si(value1, 4585);
  mpz_init_set_si(key2, 42);
  mpz_init_set_si(value2, 4856);
  mpz_init_set_si(key3, -9);
  mpz_init_set_si(value3, 1452);

  insert_or_die(&map, &alloc, key1, value1);
  insert_or_die(&map, &alloc, key2, value2);
  insert_or_die(&map, &alloc, key3, value3);

  mpz_t lookup;
  mpz_init_set_si(lookup, 42);
  struct pair const *it = CCC_flat_hash_map_get_key_value(&map, lookup);
  if (it != NULL) {
    gmp_printf("Value of 42 is %Zd\n", it->value);
  }

  for (struct pair *i = CCC_flat_hash_map_begin(&map);
       i != CCC_flat_hash_map_end(&map);
       i = CCC_flat_hash_map_next(&map, i)) {
    gmp_printf("%Zd -> %Zd\n", i->key, i->value);
  }

  for (struct pair *i = CCC_flat_hash_map_begin(&map);
       i != CCC_flat_hash_map_end(&map);
       i = CCC_flat_hash_map_next(&map, i)) {
    mpz_clear(i->key);
    mpz_clear(i->value);
  }
  CCC_flat_hash_map_clear_and_free(&map, &(CCC_Destructor){}, &alloc);

  mpz_clear(key1);
  mpz_clear(value1);
  mpz_clear(key2);
  mpz_clear(value2);
  mpz_clear(key3);
  mpz_clear(value3);
  mpz_clear(lookup);
  return 0;
}