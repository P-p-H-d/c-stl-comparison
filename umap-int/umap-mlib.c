#include <stdio.h>
#include "m-dict.h"

DICT_DEF2(umap_int, int, int)
#define M_OPL_umap_int_t() DICT_OPLIST(umap_int, M_BASIC_OPLIST, M_BASIC_OPLIST)
  
int main(void)
{
  M_LET( ( map, (17, 4585), (42, 4856), (-9,1452) ), umap_int_t) {
    int *it = umap_int_get(map, 42);
    if (it != NULL) {
      printf("Value of 42 is %d\n", *it);
    }
    for M_EACH(item, map, umap_int_t) {
	printf("%d --> %d\n", item->key, item->value);
      }
  }
  return 0;
}
