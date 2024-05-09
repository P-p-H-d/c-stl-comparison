#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "cc_array.h"
#include "cc_list.h"
#include "cc_treetable.h"
#include "cc_hashtable.h"

#include "common.h"

/********************************************************************************************/

static void test_array(size_t n)
{
  CC_Array *a1, *a2;
  enum cc_stat stat;

  stat = cc_array_new(&a1);
  if (stat != CC_OK) abort();
  stat = cc_array_new(&a2);
  if (stat != CC_OK) abort();
  
  for(size_t i = 0; i < n; i++) {
    stat = cc_array_add(a1, (void*) (uintptr_t)rand_get() );
    if (stat != CC_OK) abort();
    stat = cc_array_add(a2, (void*) (uintptr_t)rand_get() );
    if (stat != CC_OK) abort();
  }
  unsigned int s = 0;
  for(unsigned long i = 0; i < n; i++) {
    void *e, *f;
    stat = cc_array_get_at(a1, i, &e);
    if (stat != CC_OK) abort();
    stat = cc_array_get_at(a2, i, &f);
    if (stat != CC_OK) abort();
    s += ((unsigned int)(uintptr_t) e) * ((unsigned int)(uintptr_t) f);
  }
  g_result = s;

  cc_array_destroy(a1);
  cc_array_destroy(a2);
}

/********************************************************************************************/

static void test_list(size_t n)
{
  CC_List *a1, *a2;
  enum cc_stat stat;

  stat = cc_list_new(&a1);
  if (stat != CC_OK) abort();
  stat = cc_list_new(&a2);
  if (stat != CC_OK) abort();
  
  for(size_t i = 0; i < n; i++) {
    stat = cc_list_add(a1, (void*) (uintptr_t)rand_get() );
    if (stat != CC_OK) abort();
    stat = cc_list_add(a2, (void*) (uintptr_t)rand_get() );
    if (stat != CC_OK) abort();
  }
  unsigned int s = 0;
  CC_ListIter iter1, iter2;
    void *e, *f;
  cc_list_iter_init(&iter1, a1);
  cc_list_iter_init(&iter2, a2);
  while (cc_list_iter_next(&iter1, &e) == CC_OK && cc_list_iter_next(&iter2, &f) == CC_OK) {
    s += ((unsigned int)(uintptr_t) e) * ((unsigned int)(uintptr_t) f);
  }
  g_result = s;

  cc_list_destroy(a1);
  cc_list_destroy(a2);
}

/********************************************************************************************/

static int compare(const void *a, const void *b)
{
  const uintptr_t pa = (uintptr_t) a;
  const uintptr_t pb = (uintptr_t) b;
  return (pa < pb) ? -1 : (pa > pb);
}

static void test_rbtree(size_t n)
{
  CC_TreeTable *tree;
  enum cc_stat stat;

  stat = cc_treetable_new(compare, &tree);
  if (stat != CC_OK) abort();
  for (size_t i = 0; i < n; i++) {
    void *key = (void*)(uintptr_t) rand_get();
    stat = cc_treetable_add(tree, key, key);
    if (stat != CC_OK) abort();
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    void *e;
    void *key = (void*) (uintptr_t) rand_get();
    stat = cc_treetable_get(tree, key, &e);
    if (stat == CC_OK)
      s += (uintptr_t)e;
  }
  g_result = s;
  cc_treetable_destroy(tree);
}

/********************************************************************************************/
static size_t hash_func (const void *key, int l, uint32_t seed)
{
  const unsigned long pa = (uintptr_t) key;
  (void)l;
  return pa ^ seed;
}

static int equal_func(const void *key1, const void *key2)
{
  const unsigned long pa = (uintptr_t) key1;
  const unsigned long pb = (uintptr_t) key2;
  return (pa < pb) ? -1 : pa > pb;
}

static void
test_dict(size_t  n)
{
  CC_HashTable *dict;
  enum cc_stat stat;
  CC_HashTableConf htc;
  cc_hashtable_conf_init(&htc);
  htc.hash = hash_func;
  htc.key_compare = equal_func;
  stat = cc_hashtable_new_conf(&htc, &dict);
  if (stat != CC_OK) abort();
  
  for (size_t i = 0; i < n; i++) {
    void *value = (void*)(uintptr_t) rand_get();
    void *key = (void*)(uintptr_t) rand_get();
    stat = cc_hashtable_add(dict, key, value );
    if (stat != CC_OK) abort();
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    void *key = (void*)(uintptr_t) rand_get();
    void *r;
    stat = cc_hashtable_get(dict, key, &r);
    if (stat == CC_OK)
      s += (uintptr_t) r;
  }
  g_result = s;
  cc_hashtable_destroy(dict);
}

/********************************************************************************************/

typedef char char_array_t[256];

static int char_equal (const void* a, const void * b)
{
  const char_array_t *pa = (const char_array_t *)a;
  const char_array_t *pb = (const char_array_t *)b;
  return strcmp(*pa,*pb);
}

static size_t char_hash(const void *a, int l, uint32_t seed)
{
  const char_array_t *pa = (const char_array_t *)a;
  const char *s = *pa;
  (void)l ;
  size_t hash = seed;
  while (*s) hash = hash * 31421 + (*s++) + 6927;
  return hash;
}

static void
test_dict_big(size_t  n)
{
  CC_HashTable *dict;
  enum cc_stat stat;
  CC_HashTableConf htc;
  cc_hashtable_conf_init(&htc);
  htc.hash = char_hash;
  htc.key_compare = char_equal;
  stat = cc_hashtable_new_conf(&htc, &dict);
  if (stat != CC_OK) abort();

  char_array_t **tab = malloc (sizeof(char_array_t *)*2*n);
  if (!tab) abort();
  size_t cpt = 0;
  for (size_t i = 0; i < n; i++) {
    char_array_t *key = malloc (sizeof (char_array_t));
    char_array_t *value = malloc (sizeof (char_array_t));
    tab[cpt++] = key;
    tab[cpt++] = value;
    sprintf(*key, "%u", rand_get());
    sprintf(*value, "%u", rand_get());
    stat = cc_hashtable_add(dict, key, value );
    if (stat != CC_OK) abort();
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    char_array_t s1;
    void *r;
    sprintf(s1, "%u", rand_get());
    stat = cc_hashtable_get(dict, s1, &r);
    if (stat == CC_OK)
      s ++;
  }
  g_result = s;
  cc_hashtable_destroy(dict);
  if (cpt != 2*n) abort();
  for(size_t i = 0; i < 2*n;i++)
    free(tab[i]);
}

/********************************************************************************************/

static int cmp_float(const void * a, const void *b)
{
  const float *const*pa = a, *const*pb = b;
  return (**pa < **pb) ? -1 : (**pa > **pb);
}

static void test_sort(size_t n)
{
  CC_Array *a1;
  enum cc_stat stat;

  stat = cc_array_new(&a1);
  if (stat != CC_OK) abort();
  for(size_t i = 0; i < n; i++) {
    float *v = malloc(sizeof(float));
    *v = rand_get();
    stat = cc_array_add(a1, v );
    if (stat != CC_OK) abort();
  }
  cc_array_sort(a1, cmp_float);
  void *e;
  stat = cc_array_get_at(a1, 0, &e);
  if (stat != CC_OK) abort();
  g_result = *(float*)e;
  cc_array_destroy(a1);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 10,    "List", 10000000, 0, test_list, 0},
  { 20,   "Array", 100000000, 0, test_array, 0},
  { 30,  "Rbtree", 1000000, 0, test_rbtree, 0},
  { 40,    "dict", 10000000, 0, test_dict, 0},
  { 41, "dictBig", 1000000, 0, test_dict_big, 0},
  { 50,           "Sort",10000000, 0, test_sort, 0},
};

int main(int argc, const char *argv[])
{
  test("CollectionC", numberof(table), table, argc, argv);
  exit(0);
}
