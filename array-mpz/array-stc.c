#include <stdio.h>
#include <gmp.h>

// WORKAROUND: Needs to encapsulate mpz_t within a C struct
typedef struct {
  mpz_t Z;
} mpz_z;

#define i_type         array_mpz
#define i_val          mpz_z
#define i_cmp(a,b)     (*a < *b ? -1 : *a > *b)                          // WORKAROUND: i_cmp only works on valraw (not on the base type): the sort cannot therefore handle the full mpz_t range.
#define i_valdrop(z)   mpz_clear(z->Z)
#define i_valclone(z)  ({ mpz_z Z; mpz_init_set(Z.Z, z.Z); Z; })  // WORKAROUND: needs to use GNU C extension or static inline functions to match GMP prototype.
#define i_valraw       unsigned int
#define i_valfrom(ui)  ({ mpz_z Z; mpz_init_set_ui(Z.Z, ui); Z; })
#define i_valto(z)     mpz_get_ui(z->Z)
#include <stc/cvec.h>

int main(void)
{
  c_auto(array_mpz, vec) {
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
    c_foreach (item, array_mpz, vec) {
      gmp_printf("%Zd\n", item.ref->Z);
    }
  }
  return 0;
}
