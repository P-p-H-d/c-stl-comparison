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

typedef struct {
  const char* key;
  const char* value;
} pair_t;

int main(void)
{
  pair_t *hash = NULL;

  shput(hash, "Hello", "LIB");
  shput(hash, "Welcome", "Program");
  shput(hash, "Sincerely", "Your map");

  pair_t *it = shgetp_null(hash, "Welcome");
  if (it != NULL) {
    printf("Value of 'Welcome' is %s\n", it->value);
  }

  for(int i = 0; i < shlen(hash); i++) {
    printf("%s --> %s\n", hash[i].key, hash[i].value);
  }
  shfree(hash);
  return 0;
}
