#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opencstl.h"

static int str_cmp(const void *a, const void *b)
{
  const char * const *pa = a;
  const char * const *pb = b;
  return strcmp(*pa, *pb);
}

int main(void)
{
  VECTOR(char *) array = new_vector(char *);
  if (!array) {
    abort();
  }

  push_back(array, "World");
  push_back(array, "Hello");
  push_back(array, "!");

  // WORKAROUND: Use qsort directly on the underlying contiguous storage.
  qsort(array, size(array), sizeof(char *), str_cmp);

  for (int i = 0; i < size(array); i++) {
    printf("%s\n", array[i]);
  }

  destroy(array);
  return 0;
}
