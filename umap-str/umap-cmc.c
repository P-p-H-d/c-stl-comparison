#include <stdio.h>
#include <string.h>

#define K char *
#define V char *
#define PFX hmstr
#define SNAME hm_str
#define CMC_EXT_ITER
#include "cmc/hashmap.h"

static size_t hash_str(char *x)
{
  if (x == NULL) return 0;
  size_t r = 0;
  char *ptr = x;
  while (*ptr) {
    r = r * 33 + *ptr;
    ptr++;
  }
  return r;
}

static int cmp_str(char *a, char *b)
{
  if (a == NULL && b == NULL) return 0;
  if (a == NULL) return -1;
  if (b == NULL) return 1;
  return strcmp(a, b);
}

int main(void)
{
  struct hm_str *dict = hmstr_new(16, 0.7, &(struct hm_str_fkey){
    .hash = hash_str,
    .cmp = cmp_str
  }, &(struct hm_str_fval){
  });
  if (!dict) {
    abort();
  }
  
  if (!hmstr_insert(dict, "Hello", "LIB")) {
    abort();
  }
  if (!hmstr_insert(dict, "Welcome", "Program")) {
    abort();
  }
  if (!hmstr_insert(dict, "Sincerely", "Your map")) {
    abort();
  }
  
  char **it = hmstr_get_ref(dict, "Hello");
  if (it != NULL) {
    printf("Value of 'Hello' is %s\n", *it);
  }
  
  struct hm_str_iter iter = hmstr_iter_start(dict);
  for (; !hmstr_iter_at_end(&iter); hmstr_iter_next(&iter)) {
    printf("%s -> %s\n", hmstr_iter_key(&iter), hmstr_iter_value(&iter));
  }
  
  hmstr_free(dict);
  return 0;
}
