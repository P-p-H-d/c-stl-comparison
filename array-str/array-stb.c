#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static inline int my_string_cmp(const void *a, const void *b)
{
  const char * const *pa = a;
  const char * const *pb = b;
  return strcmp(*pa, *pb);
}


int main(void)
{
  const char **vec = NULL;

  arrput(vec, "Hello");
  arrput(vec, "World");
  arrput(vec, "!");

  qsort(vec, arrlen(vec), sizeof(const char *), my_string_cmp);
  for(int i = 0 ; i < arrlen(vec); i++) {
    printf("%s\n", vec[i]);
  }
  arrfree(vec);
  return 0;
}
