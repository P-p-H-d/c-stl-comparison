#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <glib.h>

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

static guint hash_func (gconstpointer key)
{
  const mpz_t *pa = key;
  return (guint) mpz_fast_hash(*pa);
}

static gboolean equal_func(gconstpointer key1, gconstpointer key2)
{
  const mpz_t *pa = key1;
  const mpz_t *pb = key2;
  return mpz_cmp(*pa, *pb) == 0;
}

static void print_them (gpointer key, gpointer value, gpointer user_data)
{
  (void) user_data;
  gmp_printf("%Zd -> %Zd\n", *(mpz_t*)key, *(mpz_t*)value);
}

int main(void)
{
  GHashTable *map;
  map = g_hash_table_new_full(hash_func, equal_func, NULL, NULL);
  mpz_t key1, value1;
  mpz_init_set_si(key1, 17);
  mpz_init_set_si(value1, 4585);
  g_hash_table_insert(map, &key1, &value1);
  mpz_t key2, value2;
  mpz_init_set_si(key2, 42);
  mpz_init_set_si(value2, 4856);
  g_hash_table_insert(map, &key2, &value2);
  mpz_t key3, value3;
  mpz_init_set_si(key3, -9);
  mpz_init_set_si(value3, 1452);
  g_hash_table_insert(map, &key3, &value3);
  mpz_t key4;
  mpz_init_set_si(key4, 42);
  void *r = g_hash_table_lookup(map, &key4);
  if (r != NULL) {
    gmp_printf("Value of 42 is %Zd\n", *(mpz_t *)r);
  }
  g_hash_table_foreach(map, print_them, NULL);
  g_hash_table_destroy(map);
  mpz_clear(key1);
  mpz_clear(value1);
  mpz_clear(key2);
  mpz_clear(value2);
  mpz_clear(key3);
  mpz_clear(value3);
  mpz_clear(key4);
  return 0;
}
