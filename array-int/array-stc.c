#include <stdio.h>

#define i_type         array_int
#define i_key          int
#define i_cmp(a,b)     (*(a) < *(b) ? -1 : *(a) > *(b))
#include <stc/vec.h>

#include <stc/algorithm.h>

int main(void)
{
  array_int vec = { 0 };
  
  int *p = array_int_push(&vec, 17);
  if (!p) {
    abort();
  }
  p = array_int_push(&vec, 42);
  if (!p) {
    abort();
  }
  p = array_int_push(&vec, 9);
  if (!p) {
    abort();
  }
  array_int_sort(&vec);
  for (c_each(item, array_int, vec)) {
    printf("%d\n", *item.ref);
  }

  array_int_drop(&vec);
  
  return 0;
}
