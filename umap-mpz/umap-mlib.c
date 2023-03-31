#include <stdio.h>
#include <gmp.h>
#include "m-dict.h"

static inline size_t mpz_fast_hash(const mpz_t z)
{
  mp_size_t  n = z->_mp_size;
  mp_limb_t *p = z->_mp_d;
  M_HASH_DECL(hash);
  if (n <= 0) {
    M_HASH_UP (hash, 0x7F5C1458);
    if (n == 0) {
      return M_HASH_FINAL (hash);
    }
    n = -n;
  }
  while (n-- > 0) {
    M_HASH_UP (hash, *p++);
  }
  return M_HASH_FINAL (hash);
}

#define M_OPL_mpz_t() M_OPEXTEND(M_CLASSIC_OPLIST(mpz), HASH(mpz_fast_hash), EQUAL(API(mpz_cmp, EQ(0), ARG1, ARG2)), INIT_WITH(mpz_init_set_si), EMPLACE_TYPE(int) )
DICT_DEF2(umap_mpz, mpz_t, mpz_t)
#define M_OPL_umap_mpz_t() DICT_OPLIST(umap_mpz, M_OPL_mpz_t(), M_OPL_mpz_t())
  
int main(void)
{
  M_LET( ( map, ((17), (4585)), ((42), (4856)), ((-9),(1452)) ), umap_mpz_t) {
    mpz_t *it = umap_mpz_get_emplace(map, 42);
    if (it != NULL) {
      gmp_printf("Value of 42 is %Zd\n", *it);
    }
    for M_EACH(item, map, umap_mpz_t) {
	gmp_printf("%Zd --> %Zd\n", item->key, item->value);
      }
  }
  return 0;
}
