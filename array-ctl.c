#include <stdio.h>
#include <gmp.h>
#include <string.h>  // FIXME: needs to explicit include this header for memmove

// FIXME: Needs to encapsulate mpz_t within a struct
typedef struct { mpz_t Z; } mpz_z_struct;
#define T mpz_z_struct
// FIXME: Needs to provide function and not encapsulation macro
static inline void mpz_z_struct_free(mpz_z_struct *z)
{
  mpz_clear(z->Z);
}
static inline mpz_z_struct mpz_z_struct_copy(mpz_z_struct *z)
{
  mpz_z_struct Z;
  mpz_init_set(Z.Z, z->Z);
  return Z;
}
static inline int mpz_z_struct_compare(mpz_z_struct * a, mpz_z_struct * b)
{
  // FIXME: despite returning an int, it is a 2-way comparison operator
  return mpz_cmp(a->Z, b->Z) <= 0;
}
#include <ctl/vector.h>


int main(void)
{
  mpz_z_struct z;                                     //FIXME: we shall not clear the z object, as its ownership has been lost.
  vec_mpz_z_struct a = vec_mpz_z_struct_init();
  mpz_init_set_ui(z.Z, 17);
  vec_mpz_z_struct_push_back(&a, z);                  // FIXME: We need to provide a fresh new initialized object for each push
  mpz_init_set_ui(z.Z, 42);
  vec_mpz_z_struct_push_back(&a, z);
  mpz_init_set_ui(z.Z, 9);
  vec_mpz_z_struct_push_back(&a, z);
  a.compare = mpz_z_struct_compare;                   // FIXME: Needs to set the compare function directly in the struct?
  vec_mpz_z_struct_sort(&a);
  foreach(vec_mpz_z_struct, &a, it)
    gmp_printf("%Zd\n", it.ref->Z);
  vec_mpz_z_struct_free(&a);
  return 0;
}
