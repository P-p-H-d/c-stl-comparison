#include <stdio.h>
#include <stdlib.h>

// WORKAROUND: stb doesn't check for allocation failure.
static void *xrealloc(void *ptr, size_t size)
{
  void * p = realloc(ptr, size);
  if (!p) {
    abort();
  }
  return p;
}
static void xfree(void *ptr)
{
  free(ptr);
}
#define STBDS_REALLOC(context, ptr, size) xrealloc(ptr, size)
#define STBDS_FREE(context, ptr) xfree(ptr)
#define STB_DS_IMPLEMENTATION
#include <stb_ds.h>

static inline int int_cmp(const void *a, const void *b)
{
  const int *pa = a;
  const int *pb = b;
  return (*pa < *pb) ? -1 : *pa > *pb;
}

int main(void)
{
  int* vec = NULL;
  
  arrput(vec, 17);
  arrput(vec, 42);
  arrput(vec, 9);
  qsort(vec, arrlen(vec), sizeof(int), int_cmp);
  for (int i = 0; i < arrlen(vec); i++) {
    printf("%d\n", vec[i]);
  }
  arrfree(vec);
  
  return 0;
}
