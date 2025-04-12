#include <stdio.h>

#define i_static
#include <stc/cstr.h>

#define i_keypro cstr
#define i_cmp(a,b)     strcmp(*a,*b)
#include <stc/vec.h>

#include <stc/algorithm.h>

int main(void)
{
  vec_cstr vec= { 0 };
  
  cstr *p = vec_cstr_emplace(&vec, "World");
  if (!p) {
    abort();
  }
  p = vec_cstr_emplace(&vec, "Hello");
  if (!p) {
    abort();
  }
  p = vec_cstr_emplace(&vec, "!");
  if (!p) {
    abort();
  }
  vec_cstr_sort(&vec);
  for (c_each(item, vec_cstr, vec)) {
    printf("%s\n", cstr_str(item.ref));
  }

  vec_cstr_drop(&vec);
  
  return 0;
}
