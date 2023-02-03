#include <stdio.h>
#include <gmp.h>

#include "cc_array.h"

// WORKAROUND: needs to cast the type from void*
int mpz_cmp_sort(const void *a, const void *b)
{
  const mpz_t *const*ap = a;
  const mpz_t *const*bp = b;
  return mpz_cmp(**ap, **bp);
}

int main(void)
{
  CC_Array *array;
  if (cc_array_new(&array) != CC_OK) {
    abort();
  }

  mpz_t *mpz_ptr = malloc(sizeof(mpz_t));
  if (!mpz_ptr) {
    abort();
  }
  mpz_init_set_ui(*mpz_ptr, 17);
  enum cc_stat status = cc_array_add(array, mpz_ptr);
  if (status != CC_OK) {
    abort();
  }

  mpz_ptr = malloc(sizeof(mpz_t));
  if (!mpz_ptr) {
    abort();
  }
  mpz_init_set_ui(*mpz_ptr, 42);
  status = cc_array_add(array, mpz_ptr);
  if (status != CC_OK) {
    abort();
  }

  mpz_ptr = malloc(sizeof(mpz_t));
  if (!mpz_ptr) {
    abort();
  }
  mpz_init_set_ui(*mpz_ptr, 9);
  status = cc_array_add(array, mpz_ptr);
  if (status != CC_OK) {
    abort();
  }

  cc_array_sort(array, mpz_cmp_sort);

  CC_ArrayIter ai;
  void *next;
  cc_array_iter_init(&ai, array);
  while (cc_array_iter_next(&ai, &next) != CC_ITER_END) {
    mpz_ptr = next;
    gmp_printf("%Zd\n", *mpz_ptr);
  }
  
  cc_array_iter_init(&ai, array);
  while (cc_array_iter_next(&ai, &next) != CC_ITER_END) {
    mpz_ptr = next;
    mpz_clear(*mpz_ptr);
    free(mpz_ptr);
  }
  cc_array_destroy(array);
}
