#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "array/sc_array.h"

// WORKAROUND: Needs to encapsulate mpz_t within a C struct
typedef struct {
  mpz_t Z;
} mpz_z;

sc_array_def(mpz_z, mpz);

static inline int int_mpz(const void *a, const void *b)
{
  const mpz_z *pa = a;
  const mpz_z *pb = b;
  return mpz_cmp(pa->Z, pb->Z);
}

int main(void)
{
  struct sc_array_mpz arr;
  mpz_z z;

  sc_array_init(&arr);
  mpz_init_set_ui(z.Z, 17);
  sc_array_add(&arr, z); //WORKAROUND: Move semantic!
  mpz_init_set_ui(z.Z, 42);
  sc_array_add(&arr, z);
  mpz_init_set_ui(z.Z, 9);
  sc_array_add(&arr, z);
  if (sc_array_oom(&arr)) {
    abort();
  }
  //WORKAROUND: Cannot call sc_str_destroy on z
  sc_array_sort(&arr, int_mpz);
  for (size_t i = 0; i < sc_array_size(&arr); i++) {
    gmp_printf("%Zd\n", arr.elems[i].Z);
  }
  // WORKAROUND: Need to iterate to clear all objects
  for (size_t i = 0; i < sc_array_size(&arr); i++) {
    mpz_clear(arr.elems[i].Z);
  }
  sc_array_term(&arr);
  return 0;
}
