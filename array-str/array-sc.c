#include <stdio.h>
#include <string.h>
#include "array/sc_array.h"
#include "string/sc_str.h"

sc_array_def(char *, scstr);

static inline int int_str(const void *a, const void *b)
{
  const char *const*pa = a;
  const char *const*pb = b;
  return strcmp(*pa, *pb);
}

int main(void)
{
  struct sc_array_scstr arr;
  char* s1;

  sc_array_init(&arr);
  s1 = sc_str_create("World");
  sc_array_add(&arr, s1); //WORKAROUND: Move semantic!
  s1 = sc_str_create("Hello");
  sc_array_add(&arr, s1);
  s1 = sc_str_create("!");
  sc_array_add(&arr, s1);
  if (sc_array_oom(&arr)) {
    abort();
  }
  //WORKAROUND: Cannot call sc_str_destroy on s1
  sc_array_sort(&arr, int_str);
  for (size_t i = 0; i < sc_array_size(&arr); i++) {
    printf("%s\n", arr.elems[i]);
  }
  // WORKAROUND: Need to iterate to clear all strings
  for (size_t i = 0; i < sc_array_size(&arr); i++) {
    sc_str_destroy(&arr.elems[i]);
  }  
  sc_array_term(&arr);
  return 0;
}
