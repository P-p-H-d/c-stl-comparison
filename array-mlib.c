#include <stdio.h>
#include <gmp.h>
#include "m-array.h"
#include "m-algo.h"

#define M_OPL_mpz_t() M_OPEXTEND(M_CLASSIC_OPLIST(mpz), CMP(mpz_cmp), INIT_WITH(mpz_init_set_ui) )
ARRAY_DEF(array_mpz, mpz_t)
#define M_OPL_array_mpz_t() ARRAY_OPLIST(array_mpz, M_OPL_mpz_t())
ALGO_DEF(array_mpz, array_mpz_t)
  
int main(void)
{
  M_LET( ( array, (17), (42), (9) ), array_mpz_t) {
    array_mpz_sort(array);
    for M_EACH(item, array, array_mpz_t) {
	gmp_printf("%Zd\n", *item);
    }
  }
  return 0;
}
