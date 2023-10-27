#include <stdio.h>

#define i_type         array_int
#define i_key          int
#define i_cmp(a,b)     (*(a) < *(b) ? -1 : *(a) > *(b))
#include <stc/cvec.h>

#include <stc/algorithm.h>

int main(void)
{
  c_auto(array_int, vec) {
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
    c_foreach (item, array_int, vec) {
      printf("%d\n", *item.ref);
    }
  }
  return 0;
}
