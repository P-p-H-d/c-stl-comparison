#include <stdio.h>
#include <stdlib.h>

#include "opencstl.h"

static int int_cmp(const void *a, const void *b)
{
  const int *pa = a;
  const int *pb = b;
  return (*pa < *pb) ? -1 : *pa > *pb;
}

int main(void)
{
  VECTOR(int) array = new_vector(int);
  if (!array) {
    abort();
  }

  push_back(array, 17);
  push_back(array, 42);
  push_back(array, 9);

  // WORKAROUND: Use qsort directly on the underlying contiguous storage.
  qsort(array, size(array), sizeof(int), int_cmp);

  for (int i = 0; i < size(array); i++) {
    printf("%d\n", array[i]);
  }

  destroy(array);
  return 0;
}
