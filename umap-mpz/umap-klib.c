#include <stdio.h>
#include <gmp.h>
#include <khash.h>

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

// WORKAROUND: Encapsulate mpz_t in a struct
typedef struct mpz { mpz_t z; } mpz;

#define hash_func(a) mpz_fast_hash(a.z)
#define hash_equal(a,b) mpz_cmp(a.z, b.z) == 0
KHASH_INIT(iun, struct mpz, struct mpz, 1, hash_func, hash_equal)

int main(void)
{
  khash_t(iun) *map = kh_init(iun);
  int ret;
  struct mpz z;

  // WORKAROUND: Move semantic is imposed
  mpz_init_set_si(z.z, 17);
  khiter_t k = kh_put(iun, map, z, &ret);
  if (ret < 0) {
    abort();
  }
  mpz_init_set_si(z.z, 4585);
  kh_value(map, k) = z;

  mpz_init_set_si(z.z, 42);
  k = kh_put(iun, map, z, &ret);
  if (ret < 0) {
    abort();
  }
  mpz_init_set_si(z.z, 4856);
  kh_value(map, k) = z;

  mpz_init_set_si(z.z, -9);
  k = kh_put(iun, map, z, &ret);
  if (ret < 0) {
    abort();
  }
  mpz_init_set_si(z.z, 1452);
  kh_value(map, k) = z;

  mpz_init_set_si(z.z, 42);
  k = kh_get(iun, map, z);
  if (kh_exist(map, k)) {
    gmp_printf("Value of 42 is %Zd\n", kh_value(map, k).z);
  }

  for (k = kh_begin(map); k != kh_end(map); k++) {
    if (kh_exist(map, k)) {
      gmp_printf("%Zd -> %Zd\n", kh_key(map, k).z, kh_value(map, k).z );
    }
  }

  //WORKAROUND: need to destroy each items of the hash by hand
  for (k = kh_begin(map); k != kh_end(map); k++) {
    if (kh_exist(map, k)) {
      mpz_clear(kh_key(map, k).z);
      mpz_clear(kh_value(map, k).z);
    }
  }
  mpz_clear(z.z);
  kh_destroy(iun, map);
  
  return 0;
}
