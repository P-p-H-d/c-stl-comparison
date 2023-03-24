#include <stdio.h>
#include "macro_collections.h"

#define MY_LIST_PARAMS (array_str, array_str_t, , , const char *)
C_MACRO_COLLECTIONS_EXTENDED(CMC, LIST, MY_LIST_PARAMS, (STR))

static int my_strcmp(const void *a, const void *b)
{
  const char *const* ap = a;
  const char *const* bp = b;
  return strcmp(*ap, *bp);
}

int main(void)
{
  struct array_str_t *list = array_str_new(4, &(struct array_str_t_fval){ NULL });
  if (!list) {
    return 1;
  }
  
  int err = array_str_push_back(list, "World");
  if (!err) {
    abort();
  }
  err = array_str_push_back(list, "Hello");
  if (!err) {
    abort();
  }
  err = array_str_push_back(list, "!");
  if (!err) {
    abort();
  }

  //WORKAROUND: Needs to hack in the structure to perform a sort
  qsort( list->buffer, array_str_count(list), sizeof (const char *), my_strcmp);

  //WORKAROUND: No iterator abstraction available
  for(int i = 0; i < array_str_count(list); i++) {
    const char *ptr = *array_str_get_ref(list, i);
    printf("%s\n", ptr);
  }
  
  array_str_free(list);
  return 0;
}
