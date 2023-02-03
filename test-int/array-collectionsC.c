#include <stdio.h>

#include "cc_array.h"

// WORKAROUND: needs to cast the type from void*
int int_cmp(const void *a, const void *b)
{
  const int *ap = a;
  const int *bp = b;
  return (*ap < *bp) ? - 1 : (*ap > *bp);
}

int main(void)
{
  CC_Array *array;
  if (cc_array_new(&array) != CC_OK) {
    abort();
  }

  // WORKAROUND: Not sure if it works on a big endian cpu
  enum cc_stat status = cc_array_add(array, (void*) 17);
  if (status != CC_OK) {
    abort();
  }

  status = cc_array_add(array, (void*) 42);
  if (status != CC_OK) {
    abort();
  }

  status = cc_array_add(array, (void*) 9);
  if (status != CC_OK) {
    abort();
  }

  cc_array_sort(array, int_cmp);

  CC_ArrayIter ai;
  void *next;
  cc_array_iter_init(&ai, array);
  while (cc_array_iter_next(&ai, &next) != CC_ITER_END) {
    printf("%d\n", (int) next);
  }
  
  cc_array_destroy(array);
}
