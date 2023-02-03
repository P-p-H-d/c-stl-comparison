#include <stdio.h>
#include "m-array.h"
#include "m-algo.h"

ARRAY_DEF(array_int, int)
#define M_OPL_array_int_t() ARRAY_OPLIST(array_int, M_OPL_int())
ALGO_DEF(array_int, array_int_t)
  
int main(void)
{
  M_LET( ( array, 17, 42, 9), array_int_t) {
    array_int_sort(array);
    for M_EACH(item, array, array_int_t) {
	printf("%d\n", *item);
      }
  }
  return 0;
}
