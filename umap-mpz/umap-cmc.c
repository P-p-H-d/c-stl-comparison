#include <stdio.h>
#include <gmp.h>

typedef struct {
  mpz_t Z;
} mpz_z;

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

static size_t hash_mpz(mpz_z x)
{
  return mpz_fast_hash(x.Z);
}

static int cmp_mpz(mpz_z a, mpz_z b)
{
  return mpz_cmp(a.Z, b.Z);
}

static mpz_z cpy_mpz(mpz_z a)
{
  mpz_z result;
  mpz_init_set(result.Z, a.Z);
  return result;
}

static void free_mpz(mpz_z a)
{
  mpz_clear(a.Z);
}

#define K mpz_z
#define V mpz_z
#define PFX hmmpz
#define SNAME hm_mpz
#define CMC_EXT_ITER
#include "cmc/hashmap.h"

int main(void)
{
  struct hm_mpz *dict = hmmpz_new(16, 0.7, &(struct hm_mpz_fkey){
    .hash = hash_mpz,
    .cmp = cmp_mpz,
    .cpy = cpy_mpz,
    .free = free_mpz
  }, &(struct hm_mpz_fval){
    .cpy = cpy_mpz,
    .free = free_mpz
  });
  if (!dict) {
    abort();
  }
  
  mpz_z k1, v1, k2, v2, k3, v3;
  
  mpz_init_set_si(k1.Z, 17);
  mpz_init_set_si(v1.Z, 4585);
  if (!hmmpz_insert(dict, k1, v1)) {
    abort();
  }
  
  mpz_init_set_si(k2.Z, 42);
  mpz_init_set_si(v2.Z, 4856);
  if (!hmmpz_insert(dict, k2, v2)) {
    abort();
  }
  
  mpz_init_set_si(k3.Z, -9);
  mpz_init_set_si(v3.Z, 1452);
  if (!hmmpz_insert(dict, k3, v3)) {
    abort();
  }
  
  mpz_z k_lookup;
  mpz_init_set_si(k_lookup.Z, 42);
  mpz_z *it = hmmpz_get_ref(dict, k_lookup);
  if (it != NULL) {
    gmp_printf("Value of 42 is %Zd\n", it->Z);
  }
  
  for (struct hm_mpz_iter iter = hmmpz_iter_start(dict); !hmmpz_iter_at_end(&iter); hmmpz_iter_next(&iter)) {
    gmp_printf("%Zd -> %Zd\n", hmmpz_iter_key(&iter).Z, hmmpz_iter_value(&iter).Z);
  }
  
  mpz_clear(k_lookup.Z);
  hmmpz_free(dict);
  return 0;
}
