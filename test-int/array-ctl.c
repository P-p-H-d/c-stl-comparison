#include <stdio.h>
#include <string.h>   //WORKAROUND: Needs to set the compare function directly in the struct?

#define T int
#define POD
#include <ctl/vector.h>

static inline int int_cmp(int *pa, int *pb)
{
  return (*pa <= *pb);
}

int main(void)
{
  vec_int a = vec_int_init();
  vec_int_push_back(&a, 17);
  vec_int_push_back(&a, 42);
  vec_int_push_back(&a, 9);
  a.compare = int_cmp;                   //WORKAROUND: Needs to set the compare function directly in the struct?
  vec_int_sort(&a);
  foreach(vec_int, &a, it)
    printf("%d\n", *it.ref);
  vec_int_free(&a);
  return 0;
}
