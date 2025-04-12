#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "common.h"

/********************************************************************************************/

#define i_key unsigned int
#define i_tag uint
#include <stc/vec.h>

static void test_array(size_t n)
{
  vec_uint a1 = vec_uint_init(), a2 = vec_uint_init();
  
  for(size_t i = 0; i < n; i++) {
    vec_uint_push_back(&a1, rand_get() );
    vec_uint_push_back(&a2, rand_get() );
  }
  unsigned int s = 0;
  for(unsigned long i = 0; i < n; i++) {
    s += *vec_uint_at(&a1, i ) * *vec_uint_at(&a2, i );
  }
  g_result = s;

  vec_uint_drop(&a1);
  vec_uint_drop(&a2);
}

/********************************************************************************************/
#define i_key unsigned int
#define i_tag uint
#include <stc/list.h>

static void test_list(size_t n)
{
  list_uint a1 = list_uint_init(), a2 = list_uint_init();
  
  for(size_t i = 0; i < n; i++) {
    list_uint_push_front(&a1, rand_get() );
    list_uint_push_front(&a2, rand_get() );
  }
  unsigned int s = 0;
  for(list_uint_iter it1 = list_uint_begin(&a1), it2 = list_uint_begin(&a2) ;
      it1.ref != list_uint_end(&a1).ref ;
      list_uint_next(&it1), list_uint_next(&it2) ) {
    s += *it1.ref * *it2.ref;
  }
  g_result = s;

  list_uint_drop(&a1);
  list_uint_drop(&a2);
}

/********************************************************************************************/

#define i_tag ulong
#define i_key unsigned long
#include <stc/sset.h>

static void test_rbtree(size_t n)
{
  sset_ulong tree = sset_ulong_init();
  
  for (size_t i = 0; i < n; i++) {
    sset_ulong_insert(&tree, rand_get() );
  }
    
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long j = rand_get();
    if (sset_ulong_get(&tree, j ) != NULL)
      s+= j;
  }
  g_result = s;
  sset_ulong_drop(&tree);
}

/********************************************************************************************/

#define i_tag ulong
#define i_key unsigned long
#define i_val unsigned long
#include <stc/hmap.h>

static void
test_dict(size_t  n)
{
  hmap_ulong dict = hmap_ulong_init();
  
  for (size_t i = 0; i < n; i++) {
    unsigned long value = rand_get();
    unsigned long key = rand_get();
    hmap_ulong_insert_or_assign(&dict, key, value);
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    const hmap_ulong_value*val = hmap_ulong_get(&dict, rand_get());
    if (val != NULL)
      s += val->second;
  }
  g_result = s;
  
  hmap_ulong_drop(&dict);
}

/********************************************************************************************/

typedef struct {
  char a[256];
} char_array_t;
static inline void char_init (char_array_t *a) { a->a[0] = 0; }
static inline void char_set (char_array_t *a, const char_array_t b) { strcpy(a->a, b.a); }
static inline bool char_equal_p (const char_array_t *a, const char_array_t *b) { return strcmp(a->a,b->a)==0; }
static inline void char_clear (char_array_t *a) { (void)a; }
static inline size_t char_hash(const char_array_t *a) {
  size_t hash = 0;
  const char *s = a->a;
  while (*s) hash = hash * 31421 + (*s++) + 6927;
  return hash;
}

#define i_tag       achar
#define i_key       char_array_t
#define i_val       char_array_t
#define i_hash      char_hash
#define i_eq        char_equal_p
#include <stc/hmap.h>

static void
test_dict_big(size_t  n)
{
  hmap_achar dict = hmap_achar_init();

  for (size_t i = 0; i < n; i++) {
    char_array_t s1, s2;
    sprintf(s1.a, "%u", rand_get());
    sprintf(s2.a, "%u", rand_get());
    hmap_achar_insert_or_assign(&dict, s1, s2);
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    char_array_t s1;
    sprintf(s1.a, "%u", rand_get());
    const hmap_achar_value*val = hmap_achar_get(&dict, s1);
    if (val != NULL)
      s ++;
  }
  g_result = s;

  hmap_achar_drop(&dict);
}

/********************************************************************************************/

#define i_key float
#define i_tag float
#define i_use_cmp
#include <stc/vec.h>

static void test_sort(size_t n)
{
  vec_float a1 = vec_float_init();

  for(size_t i = 0; i < n; i++) {
    vec_float_push_back(&a1, rand_get() );
  }
  vec_float_sort(&a1);
  g_result = *vec_float_at(&a1, 0);
  vec_float_drop(&a1);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 10,    "List", 10000000, 0, test_list, 0},
  { 20,   "Array", 100000000, 0, test_array, 0},
  { 30,  "Rbtree", 1000000, 0, test_rbtree, 0},
  { 40,    "dict", 10000000, 0, test_dict, 0},
  { 41, "dictBig", 1000000, 0, test_dict_big, 0},
  { 50,    "Sort", 10000000, 0, test_sort, 0},
};

int main(int argc, const char *argv[])
{
  test("STC", numberof(table), table, argc, argv);
  exit(0);
}
