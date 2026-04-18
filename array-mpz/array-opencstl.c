#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#include "opencstl.h"

static int mpz_ptr_cmp(const void *a, const void *b)
{
  // WORKAROUND: Store mpz_t* pointers in the vector; mpz_t cannot be stored by value.
  mpz_t * const *pa = a;
  mpz_t * const *pb = b;
  return mpz_cmp(**pa, **pb);
}

int main(void)
{
  VECTOR(mpz_t *) array = new_vector(mpz_t *);
  if (!array) {
    abort();
  }

  mpz_t *v;

  v = malloc(sizeof *v); mpz_init_set_ui(*v, 17); push_back(array, v);
  v = malloc(sizeof *v); mpz_init_set_ui(*v, 42); push_back(array, v);
  v = malloc(sizeof *v); mpz_init_set_ui(*v,  9); push_back(array, v);

  // WORKAROUND: Use qsort directly on the underlying contiguous storage.
  qsort(array, size(array), sizeof(mpz_t *), mpz_ptr_cmp);

  for (int i = 0; i < size(array); i++) {
    gmp_printf("%Zd\n", *array[i]);
  }

  // WORKAROUND: No destructor registered. Call it by hand.
  for (int i = 0; i < size(array); i++) {
    mpz_clear(*array[i]);
    free(array[i]);
  }
  destroy(array);
  return 0;
}
