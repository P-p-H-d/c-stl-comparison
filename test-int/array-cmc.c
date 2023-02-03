#include <stdio.h>

#include "macro_collections.h"

static int int_cmp(const void *a, const void *b)
{
  const int *ap = a;
  const int *bp = b;
  return (*ap < *bp) ? -1 : *ap > *bp;
}

#define MY_LIST_PARAMS (array_int, array_int_t, , , int)
C_MACRO_COLLECTIONS_EXTENDED(CMC, LIST, MY_LIST_PARAMS, (STR))
  
int main(void)
{
  struct array_int_t *list = array_int_new(4, &(struct array_int_t_fval){ NULL });
  if (!list) {
    return 1;
  }
  
  int err = array_int_push_back(list, 17);
  if (!err) {
    abort();
  }
  err = array_int_push_back(list, 42);
  if (!err) {
    abort();
  }
  err = array_int_push_back(list, 9);
  if (!err) {
    abort();
  }

  //WORKAROUND: Needs to hack in the structure to perform a sort
  qsort( list->buffer, array_int_count(list), sizeof (int), int_cmp);

  //WORKAROUND: No iterator abstraction available
  for(int i = 0; i < array_int_count(list); i++) {
    int *ptr = array_int_get_ref(list, i);
    printf("%d\n", *ptr);
  }
  
  array_int_free(list);
  return 0;
}
