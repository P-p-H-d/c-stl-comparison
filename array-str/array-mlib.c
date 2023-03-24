#include <stdio.h>
#include "m-array.h"
#include "m-algo.h"
#include "m-string.h"

ARRAY_DEF(array_str, string_t)
#define M_OPL_array_str_t() ARRAY_OPLIST(array_str, M_OPL_string_t())
ALGO_DEF(array_str, array_str_t)
  
int main(void)
{
  M_LET( ( array, ("World"), ("Hello"), ("!") ), array_str_t) {
    array_str_sort(array);
    for M_EACH(item, array, array_str_t) {
	printf("%s\n", string_get_cstr(*item) );
    }
  }
  return 0;
}
