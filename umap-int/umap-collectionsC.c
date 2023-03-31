#include <stdio.h>

#include "cc_hashtable.h"

static size_t hash_func (const void *key, int l, uint32_t seed)
{
  const int *pa = key;
  (void)l;
  return *pa ^ seed;
}

static int equal_func(const void *key1, const void *key2)
{
  const int *pa = key1;
  const int *pb = key2;
  return (*pa < *pb) ? -1 : *pa > *pb;
}

int main(void)
{
  CC_HashTable *map;
  CC_HashTableConf conf;
  cc_hashtable_conf_init(&conf);
  conf.hash = hash_func;
  conf.key_compare = equal_func;
  if (cc_hashtable_new_conf(&conf, &map) != CC_OK) {
    abort();
  }
  int key1 = 17, value1 = 4585;
  if (cc_hashtable_add(map, &key1, &value1) != CC_OK) {
    abort();
  }
  int key2 = 42, value2 = 4856;
  if (cc_hashtable_add(map, &key2, &value2) != CC_OK) {
    abort();
  }
  int key3 = -9, value3 = 1452;
  if (cc_hashtable_add(map, &key3, &value3) != CC_OK) {
    abort();
  }
  void *r;
  int key4 = 42;
  if (cc_hashtable_get(map, &key4, &r) == CC_OK) {
    printf("Value of 42 is %d\n", *(int *)r);
  }
  CC_HashTableIter it;
  TableEntry *pair;
  cc_hashtable_iter_init(&it, map);
  while (cc_hashtable_iter_next(&it, &pair) != CC_ITER_END) {
    printf("%d -> %d\n", *(int*)pair->key, *(int*)pair->value);
  }
  cc_hashtable_destroy(map);
  return 0;
}
