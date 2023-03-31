#include <stdio.h>
#include <gmp.h>

#include "macro_collections.h"

typedef struct {
  mpz_t Z;
} mpz;

static inline size_t mpz_fast_hash(const mpz_t z)
{
  mp_size_t  n = z->_mp_size;
  mp_limb_t *p = z->_mp_d;
  size_t hash = 0;
  if (n <= 0) {
    hash ^= 0x7F5C1458;
    if (n == 0) {
      return hash;
    }
    n = -n;
  }
  while (n-- > 0) {
    hash ^= *p++;
  }
  return hash;
}

static size_t hash_int(mpz x)
{
  return mpz_fast_hash(x.Z);
}

static int cmp_int(mpz a, mpz b)
{
  return mpz_cmp(a.Z, b.Z);
}

static void free_int(mpz a)
{
  mpz_clear(a.Z);
}

#define MY_DICT_PARAMS (hmap, hmap_s, , mpz, mpz)
C_MACRO_COLLECTIONS_EXTENDED(CMC, HASHMAP, MY_DICT_PARAMS, (STR))

// WORKAROUDN: Cannot define theses structures as const
static struct hmap_s_fkey hmap_fkey = { .cmp = cmp_int,
                                        .cpy = NULL,
                                        .str = NULL,
                                        .free = free_int,
                                        .hash = hash_int,
                                        .pri = NULL };

static struct hmap_s_fval hmap_fval = { .cmp = NULL,
                                        .cpy = NULL,
                                        .str = NULL,
                                        .free = free_int,
                                        .hash = NULL,
                                        .pri = NULL };

int main(void)
{
  struct hmap_s *dict = hmap_new(16, 0.7, &hmap_fkey, &hmap_fval);
  if (!dict) {
    abort();
  }
  mpz k1, v1, k2, v2, k3, v3, k4;
  mpz_init_set_si(k1.Z, 17);
  mpz_init_set_si(v1.Z, 4585);
  if (!hmap_insert(dict, k1, v1)) {
    abort();
  }
  mpz_init_set_si(k2.Z, 42);  // WORKAROUND: Needs to reinitialize the variable for each push, and we lost ownership.
  mpz_init_set_si(v2.Z, 4856);
  if (!hmap_insert(dict, k2, v2)) {
    abort();
  }
  mpz_init_set_si(k3.Z, -9);
  mpz_init_set_si(v3.Z, 1452);
  if (!hmap_insert(dict, k3, v3)) {
    abort();
  }
  mpz_init_set_si(k4.Z, 42);
  mpz *it = hmap_get_ref(dict, k4);
  if (it != NULL) {
    gmp_printf("Value of 42 is %Zd\n", it->Z);
  }
  // WORKAROUND: No iterator for hashmap
  for(int i = -50; i <= 50; i++) {
    mpz_set_si(k4.Z, i);
    it = hmap_get_ref(dict, k4);
    if (it != NULL) {
      gmp_printf("%Zd --> %Zd\n", k4.Z, it->Z);
    }
  }
  mpz_clear(k4.Z);
  hmap_free(dict);
  return 0;
}
