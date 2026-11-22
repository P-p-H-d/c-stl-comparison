#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define V const char *
#define PFX strl
#define SNAME str_list
#define CMC_EXT_ITER
#include "cmc/list.h"

static int cmp_str(const char *a, const char *b)
{
  return strcmp(a, b);
}

int main(void)
{
  struct str_list *list = strl_new(32, &(struct str_list_fval){ .cmp = cmp_str, NULL });
  if (!list) {
    return 1;
  }
  
  if (!strl_push_back(list, "World")) {
    abort();
  }
  if (!strl_push_back(list, "Hello")) {
    abort();
  }
  if (!strl_push_back(list, "!")) {
    abort();
  }

  // Use qsort for sorting
  if (strl_count(list) > 0) {
    qsort(list->buffer, strl_count(list), sizeof(const char *), (int (*)(const void *, const void *))cmp_str);
  }

  struct str_list_iter iter = strl_iter_start(list);
  for (; !strl_iter_at_end(&iter); strl_iter_next(&iter)) {
    printf("%s\n", strl_iter_value(&iter));
  }
  
  strl_free(list);
  return 0;
}
