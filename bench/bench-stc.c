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
#define i_implement
#define STC_CSTR_IO
#include "stc/cstr.h"

unsigned *permutation_tab = NULL;

static void bench_string_replace_init(size_t n)
{
  if (permutation_tab) free(permutation_tab);
  permutation_tab = (unsigned *) malloc(n * sizeof(unsigned));
  if (permutation_tab == NULL) abort();
  for(unsigned i = 0; i < n; i++)
    permutation_tab[i] = i;
  for(unsigned i = 0; i < n; i++) {
    unsigned j = rand_get() % n;
    unsigned k = rand_get() % n;
    unsigned l = permutation_tab[j];
    permutation_tab[j] = permutation_tab[k];
    permutation_tab[k] = l;
  }
}

static void bench_string_replace_clear(void)
{
  free(permutation_tab);
}

static void bench_string_replace(size_t n)
{
  cstr *tab = (cstr*) malloc (n * sizeof (cstr));
  assert (tab != 0);
  // P1
  for(unsigned i = 0; i < n; i++) {
    tab[i] = cstr_from_fmt("%u", rand_get());
  }
  // P2
  cstr str = cstr_init();
  for(unsigned i = 0; i < n; i++) {
    cstr_append_s(&str, tab[permutation_tab[i]]);
  }
  // P3
  cstr_replace(&str, "1234", "WELL");
  cstr_replace(&str, "56789", "DONE");
  size_t length = cstr_size(&str);

  // Clean
  cstr_drop(&str);
  for(unsigned i = 0; i < n; i++) {
    cstr_drop(&tab[i]);
  }
  free(tab);
  g_result = length;
}

static void bench_string_concat(size_t n)
{
  cstr *tab = (cstr *) malloc (n * sizeof(cstr)), dst;
  if (!tab) abort();
  dst = cstr_init();
  for(size_t i = 0; i < n; i++)
    tab[i] = cstr_init();
  for(size_t i = 0; i < n; i++)
    cstr_assign(&tab[i], "THIS IS IT");
  for(size_t i = 0; i < n; i++)
    cstr_append_s(&dst, tab[i]);
  for(size_t i = 0; i < n; i++)
    cstr_drop(&tab[i]);
  g_result = cstr_size(&dst);
  cstr_drop(&dst);
  free(tab);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 100,    "Seq(List)", C_N_SEQ_LIST, 0, test_list, 0},
  { 110,   "Seq(Array)", C_N_SEQ_ARRAY, 0, test_array, 0},
  { 200,  "SSet(sset)", C_N_SSET, 0, test_rbtree, 0},
  { 300,    "UMap U64(hmap)", C_N_UMAP_U64, 0, test_dict, 0},
  { 320, "UMap Big(hmap)", C_N_UMAP_BIG, 0, test_dict_big, 0},
  { 500,    "Sort", C_N_SORT, 0, test_sort, 0},
  { 900, "String Replace", C_N_STR_REPLACE, bench_string_replace_init, bench_string_replace, bench_string_replace_clear},
  { 910, "String Concat", C_N_STR_CONCAT, 0, bench_string_concat, 0},
};

int main(int argc, const char *argv[])
{
  test("STC", numberof(table), table, argc, argv);
  exit(0);
}
