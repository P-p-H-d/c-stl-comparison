#include <stdio.h>
#include <string.h>

#include "macro_collections.h"

static size_t hash_int(char *x)
{
  size_t r = 0;
  char *ptr = x;
  while (*ptr) {
    r = r * 33 + *ptr;
    ptr++;
  }
  return r;
}

static int cmp_int(char *a, char *b)
{
  return strcmp(a, b);
}

#define MY_DICT_PARAMS (hmap, hmap_s, , char *, char *)
C_MACRO_COLLECTIONS_EXTENDED(CMC, HASHMAP, MY_DICT_PARAMS, (STR))

// WORKAROUDN: Cannot define theses structures as const
static struct hmap_s_fkey hmap_fkey = { .cmp = cmp_int,
                                        .cpy = NULL,
                                        .str = NULL,
                                        .free = NULL,
                                        .hash = hash_int,
                                        .pri = NULL };

static struct hmap_s_fval hmap_fval = { .cmp = NULL,
                                        .cpy = NULL,
                                        .str = NULL,
                                        .free = NULL,
                                        .hash = NULL,
                                        .pri = NULL };

int main(void)
{
  struct hmap_s *dict = hmap_new(16, 0.7, &hmap_fkey, &hmap_fval);
  if (!dict) {
    abort();
  }
  if (!hmap_insert(dict, "Hello", "LIB")) {
    abort();
  }
  if (!hmap_insert(dict, "Welcome", "Program")) {
    abort();
  }
  if (!hmap_insert(dict, "Sincerely", "Your map")) {
    abort();
  }
  char * *it = hmap_get_ref(dict, "Hello");
  if (it != NULL) {
    printf("Value of Hello is %s\n", *it);
  }
  // WORKAROUND: No iterator for hashmap
  // No way to do it!
  hmap_free(dict);
  return 0;
}
