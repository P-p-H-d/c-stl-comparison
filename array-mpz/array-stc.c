#include <stdio.h>
#include <gmp.h>

// WORKAROUND: Needs to encapsulate mpz_t within a C struct
typedef struct {
  mpz_t Z;
} mpz_z;

#define i_type         array_mpz
#define i_key          mpz_z
#define i_cmp(a,b)     (*(a) < *(b) ? -1 : *(a) > *(b))                          // WORKAROUND: i_cmp only works on valraw (not on the base type): the sort cannot therefore handle the full mpz_t range.
#define i_keydrop(z)   mpz_clear((z)->Z)
#define i_keyclone(z)  __extension__ ({ mpz_z Z; mpz_init_set(Z.Z, (z).Z); Z; })  // WORKAROUND: needs to use GNU C extension or static inline functions to match GMP prototype.
#define i_keyraw       unsigned long int
#define i_keyfrom(ui)  __extension__ ({ mpz_z Z; mpz_init_set_ui(Z.Z, (ui)); Z; })
#define i_keytoraw(z)  mpz_get_ui((z)->Z)
#include <stc/vec.h>

#include <stc/algorithm.h>

int main(void)
{
  array_mpz vec = { 0};
  
  mpz_z *p = array_mpz_emplace(&vec, 17);
  if (!p) {
    abort();
  }
  p = array_mpz_emplace(&vec, 42);
  if (!p) {
    abort();
  }
  p = array_mpz_emplace(&vec, 9);
  if (!p) {
    abort();
  }
  array_mpz_sort(&vec);
  for (c_each (item, array_mpz, vec)) {
    gmp_printf("%Zd\n", item.ref->Z);
  }
  array_mpz_drop(&vec);
  
  return 0;
}
