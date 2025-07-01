#include <stdio.h>
#include "array/sc_array.h"

static inline int int_cmp(const void *a, const void *b)
{
  const int *pa = a;
  const int *pb = b;
  return (*pa < *pb) ? -1 : *pa > *pb;
}

int main(void)
{
  struct sc_array_int arr;
  sc_array_init(&arr);
  sc_array_add(&arr, 17);
  sc_array_add(&arr, 42);
  sc_array_add(&arr, 9);
  if (sc_array_oom(&arr)) {
    abort();
  }
  sc_array_sort(&arr, int_cmp);
  for (size_t i = 0; i < sc_array_size(&arr); i++) {
    printf("%d\n", arr.elems[i]);
  }
  sc_array_term(&arr);
  return 0;
}
