#include <stdio.h>
#include <stdlib.h>

#define V int
#define PFX intl
#define SNAME int_list
#define CMC_EXT_ITER
#include "cmc/list.h"

static int cmp_int(int a, int b)
{
  return (a < b) ? -1 : (a > b);
}

int main(void)
{
  struct int_list *list = intl_new(32, &(struct int_list_fval){ .cmp = cmp_int, NULL });
  if (!list) {
    return 1;
  }
  
  if (!intl_push_back(list, 17)) {
    abort();
  }
  if (!intl_push_back(list, 42)) {
    abort();
  }
  if (!intl_push_back(list, 9)) {
    abort();
  }

  // Use qsort for sorting
  if (intl_count(list) > 0) {
    qsort(list->buffer, intl_count(list), sizeof(int), (int (*)(const void *, const void *))cmp_int);
  }

  struct int_list_iter iter = intl_iter_start(list);
  for (; !intl_iter_at_end(&iter); intl_iter_next(&iter)) {
    printf("%d\n", intl_iter_value(&iter));
  }
  
  intl_free(list);
  return 0;
}
