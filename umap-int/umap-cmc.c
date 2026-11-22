#include <stdio.h>

#define K int
#define V int
#define PFX hmint
#define SNAME hm_int
#define CMC_EXT_ITER
#include "cmc/hashmap.h"

static size_t hash_int(int x)
{
  unsigned a = (unsigned)x;
  return (a) ^ ((a) << 11);
}

static int cmp_int(int a, int b)
{
  return (a < b) ? -1 : (a > b);
}

int main(void)
{
  struct hm_int *dict = hmint_new(16, 0.7, &(struct hm_int_fkey){ 
    .hash = hash_int,
    .cmp = cmp_int
  }, &(struct hm_int_fval){
  });
  if (!dict) {
    abort();
  }
  if (!hmint_insert(dict, 17, 4585)) {
    abort();
  }
  if (!hmint_insert(dict, 42, 4856)) {
    abort();
  }
  if (!hmint_insert(dict, -9, 1452)) {
    abort();
  }
  
  int *it = hmint_get_ref(dict, 42);
  if (it != NULL) {
    printf("Value of 42 is %d\n", *it);
  }
  
  struct hm_int_iter iter = hmint_iter_start(dict);
  for (; !hmint_iter_at_end(&iter); hmint_iter_next(&iter)) {
    printf("%d -> %d\n", hmint_iter_key(&iter), hmint_iter_value(&iter));
  }
  
  hmint_free(dict);
  return 0;
}
