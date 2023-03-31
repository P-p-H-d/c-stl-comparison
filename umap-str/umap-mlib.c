#include <stdio.h>
#include "m-dict.h"
#include "m-string.h"

DICT_DEF2(umap_str, string_t, string_t)
#define M_OPL_umap_str_t() DICT_OPLIST(umap_str, M_STRING_OPLIST, M_STRING_OPLIST)
  
int main(void)
{
  M_LET( ( map, (("Hello"), ("LIB")), (("Welcome"), ("Program")), (("Sincerely"),("Your map")) ), umap_str_t) {
    string_t *it = umap_str_get_emplace(map, "Hello");
    if (it != NULL) {
      printf("Value of 'Hello' is %s\n", string_get_cstr(*it));
    }
    for M_EACH(item, map, umap_str_t) {
	printf("%s --> %s\n", string_get_cstr(item->key), string_get_cstr(item->value));
      }
  }
  return 0;
}
