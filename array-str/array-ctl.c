#include <stdio.h>
#include <ctl/string.h>

#define T str
#include <ctl/vector.h>

// WORKAROUND: need to define a string compare
static int my_str_key_compare(str *self, str *other)
{
  return str_key_compare(self, other) <= 0;
}

int main(void)
{
  str s;
  vec_str a = vec_str_init();
  s = str_init("World");
  vec_str_push_back(&a, s);                  //WORKAROUND: We need to provide a fresh new initialized object for each push
  s = str_init("Hello");
  vec_str_push_back(&a, s);
  s = str_init("!");
  vec_str_push_back(&a, s);
  a.compare = my_str_key_compare;              //WORKAROUND: need to set directly the compare function?
  vec_str_sort(&a);
  foreach(vec_str, &a, it)
    printf("%s\n", str_c_str(it.ref));
  vec_str_free(&a);
  return 0;
}
