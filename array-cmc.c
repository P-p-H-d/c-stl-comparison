#include <stdio.h>
#include <gmp.h>

#include "macro_collections.h"

// WORKAROUND: Needs to encapsulate mpz_t within a struct
typedef struct { mpz_t Z; } mpz_z;
// WORKAROUND: needs to use functions for encapsulation (no macro)
static mpz_z mpz_z_copy(mpz_z z)
{
  mpz_z Z;
  mpz_init_set(Z.Z, z.Z);
  return Z;
}
static void mpz_z_clear(mpz_z z)
{
  mpz_clear(z.Z);
}
// WORKAROUND: Needs to cast void * to type (lost of type)
static int mpz_z_cmp(const void *a, const void *b)
{
  const mpz_z *ap = a;
  const mpz_z *bp = b;
  return mpz_cmp(ap->Z, bp->Z);
}

#define MY_LIST_PARAMS (array_mpz, array_mpz_t, , , mpz_z)
C_MACRO_COLLECTIONS_EXTENDED(CMC, LIST, MY_LIST_PARAMS, (STR))
  
int main(void)
{
  struct array_mpz_t *list = array_mpz_new(4, &(struct array_mpz_t_fval){ .free = mpz_z_clear, .cpy = mpz_z_copy, NULL });
  if (!list) {
    return 1;
  }
  
  mpz_z z;                                         //WORKAROUND: we shall not clear the z object, as its ownership has been lost.
  mpz_init_set_ui(z.Z, 17);
  int err = array_mpz_push_back(list, z);          //WORKAROUND: We need to provide a fresh new initialized object for each push
  if (!err) {
    abort();
  }
  mpz_init_set_ui(z.Z, 42);
  err = array_mpz_push_back(list, z);
  if (!err) {
    abort();
  }
  mpz_init_set_ui(z.Z, 9);
  err = array_mpz_push_back(list, z);
  if (!err) {
    abort();
  }

  //WORKAROUND: Needs to hack in the structure to perform a sort
  qsort( list->buffer, array_mpz_count(list), sizeof (mpz_z), mpz_z_cmp);

  //WORKAROUND: No iterator abstraction available
  for(int i = 0; i < array_mpz_count(list); i++) {
    mpz_z *ptr = array_mpz_get_ref(list, i);
    gmp_printf("%Zd\n", ptr->Z);
  }
  
  array_mpz_free(list);
  return 0;
}
