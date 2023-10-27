#include <stdio.h>
#define i_static
#include <stc/cstr.h>

#define i_val_str
#define i_cmp(a,b)     strcmp(*a,*b)
#include <stc/cvec.h>

#include <stc/algorithm.h>

int main(void)
{
  c_auto(cvec_str, vec) {
    cstr *p = cvec_str_emplace(&vec, "World");
    if (!p) {
      abort();
    }
    p = cvec_str_emplace(&vec, "Hello");
    if (!p) {
      abort();
    }
    p = cvec_str_emplace(&vec, "!");
    if (!p) {
      abort();
    }
    cvec_str_sort(&vec);
    c_foreach (item, cvec_str, vec) {
      printf("%s\n", cstr_str(item.ref));
    }
  }
  return 0;
}
