#include <stdio.h>
#include <gmp.h>

#include "cc_hashtable.h"

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

static size_t hash_func (const void *key, int l, uint32_t seed)
{
  const mpz_t *pa = key;
  (void)l;
  return mpz_fast_hash(*pa) ^ seed;
}

static int equal_func(const void *key1, const void *key2)
{
  const mpz_t *pa = key1;
  const mpz_t *pb = key2;
  return mpz_cmp(*pa, *pb);
}

int main(void)
{
  CC_HashTable *map;
  CC_HashTableConf conf;
  cc_hashtable_conf_init(&conf);
  conf.hash = hash_func;
  conf.key_compare = equal_func;
  if (cc_hashtable_new_conf(&conf, &map) != CC_OK) {
    abort();
  }
  mpz_t key1, value1;
  mpz_init_set_si(key1, 17);
  mpz_init_set_si(value1, 4585);
  if (cc_hashtable_add(map, &key1, &value1) != CC_OK) {
    abort();
  }
  mpz_t key2, value2;
  mpz_init_set_si(key2, 42);
  mpz_init_set_si(value2, 4856);
  if (cc_hashtable_add(map, &key2, &value2) != CC_OK) {
    abort();
  }
  mpz_t key3, value3;
  mpz_init_set_si(key3, -9);
  mpz_init_set_si(value3, 1452);
  if (cc_hashtable_add(map, &key3, &value3) != CC_OK) {
    abort();
  }
  void *r;
  mpz_t key4;
  mpz_init_set_si(key4, 42);
  if (cc_hashtable_get(map, &key4, &r) == CC_OK) {
    gmp_printf("Value of 42 is %Zd\n", *(mpz_t *)r);
  }
  CC_HashTableIter it;
  TableEntry *pair;
  cc_hashtable_iter_init(&it, map);
  while (cc_hashtable_iter_next(&it, &pair) != CC_ITER_END) {
    gmp_printf("%Zd -> %Zd\n", *(mpz_t*)pair->key, *(mpz_t*)pair->value);
  }
  cc_hashtable_destroy(map);
  mpz_clear(key1);
  mpz_clear(value1);
  mpz_clear(key2);
  mpz_clear(value2);
  mpz_clear(key3);
  mpz_clear(value3);
  mpz_clear(key4);
  return 0;
}
