#include <stdio.h>

#include "macro_collections.h"

static size_t hash_int(int x)
{
  unsigned a = (unsigned) x;
  return (a) ^ ((a) << 11);
}

static int cmp_int(int a, int b)
{
  return ( (a) < (b) ? -1 : (a) > (b) );
}

#define MY_DICT_PARAMS (hmap, hmap_s, , int, int)
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
  if (!hmap_insert(dict, 17, 4585)) {
    abort();
  }
  if (!hmap_insert(dict, 42, 4856)) {
    abort();
  }
  if (!hmap_insert(dict, -9, 1452)) {
    abort();
  }
  int *it = hmap_get_ref(dict, 42);
  if (it != NULL) {
    printf("Value of 42 is %d\n", *it);
  }
  // WORKAROUND: No iterator for hashmap
  for(int i = -50; i <= 50; i++) {
    it = hmap_get_ref(dict, i);
    if (it != NULL) {
      printf("%d --> %d\n", i, *it);
    }
  }
  hmap_free(dict);
  return 0;
}
