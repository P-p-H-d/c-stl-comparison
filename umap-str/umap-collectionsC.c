#include <stdio.h>

#include "cc_hashtable.h"

int main(void)
{
  CC_HashTable *map;
  CC_HashTableConf conf;
  cc_hashtable_conf_init(&conf);
  if (cc_hashtable_new_conf(&conf, &map) != CC_OK) {
    abort();
  }
  //M_LET( ( map, (("Hello"), ("LIB")), (("Welcome"), ("Program")), (("Sincerely"),("Your map")) ), umap_str_t) {
  if (cc_hashtable_add(map, "Hello", "LIB") != CC_OK) {
    abort();
  }
  if (cc_hashtable_add(map, "Welcome", "Program") != CC_OK) {
    abort();
  }
  if (cc_hashtable_add(map, "Sincerley", "Your map") != CC_OK) {
    abort();
  }
  void *r;
  if (cc_hashtable_get(map, "Hello", &r) == CC_OK) {
    printf("Value of Hello is %s\n", (char*)r);
  }
  CC_HashTableIter it;
  TableEntry *pair;
  cc_hashtable_iter_init(&it, map);
  while (cc_hashtable_iter_next(&it, &pair) != CC_ITER_END) {
    printf("%s -> %s\n", (char*)pair->key, (char*)pair->value);
  }
  cc_hashtable_destroy(map);
  return 0;
}
