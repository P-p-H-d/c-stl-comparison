#include <stdio.h>
#include <gmp.h>

#include "cc_array.h"

// WORKAROUND: needs to cast the type from void*
int str_sort(const void *a, const void *b)
{
  const char *const*ap = a;
  const char *const*bp = b;
  return strcmp(*ap, *bp);
}

int main(void)
{
  CC_Array *array;
  if (cc_array_new(&array) != CC_OK) {
    abort();
  }

  enum cc_stat status = cc_array_add(array, "World");
  if (status != CC_OK) {
    abort();
  }

  status = cc_array_add(array, "Hello");
  if (status != CC_OK) {
    abort();
  }

  status = cc_array_add(array, "!");
  if (status != CC_OK) {
    abort();
  }

  cc_array_sort(array, str_sort);

  CC_ArrayIter ai;
  void *next;
  cc_array_iter_init(&ai, array);
  while (cc_array_iter_next(&ai, &next) != CC_ITER_END) {
    const char *s = next;
    printf("%s\n", s);
  }
  
  cc_array_destroy(array);
}
