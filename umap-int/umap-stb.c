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

//WORKAROUND: Request C23 for hashmap! Use of compiler extension
#define typeof(x) __typeof(x)

//WORKAROUND: Generate runtime error "left shift of 255 by 24 places cannot be represented in type 'int'"

typedef struct {
  int key;
  int value;
} pair_t;

int main(void)
{
  pair_t *hash = NULL;

  hmput(hash, 17, 4585);
  hmput(hash, 42, 4856);
  hmput(hash, -9, 1452);

  pair_t *it = hmgetp_null(hash, 42);
  if (it != NULL) {
    printf("Value of 42 is %d\n", it->value);
  }

  for(int i = 0; i < hmlen(hash); i++) {
    printf("%d --> %d\n", hash[i].key, hash[i].value);
  }
  hmfree(hash);
  return 0;
}
