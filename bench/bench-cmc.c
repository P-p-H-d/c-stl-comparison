#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "common.h"

/********************************************************************************************/

// CMC list is a dynamic array
#define V unsigned int
#define PFX list_uint
#define SNAME list_uint_s
#include "cmc/list.h"

static void test_array(size_t n)
{
  struct list_uint_s *a1 = list_uint_new(1, NULL);
  struct list_uint_s *a2 = list_uint_new(1, NULL);
  
  for(size_t i = 0; i < n; i++) {
    list_uint_push_back(a1, rand_get());
    list_uint_push_back(a2, rand_get());
  }
  
  unsigned int s = 0;
  for(unsigned long i = 0; i < n; i++) {
    s += list_uint_get(a1, i) * list_uint_get(a2, i);
  }
  g_result = s;
  
  list_uint_free(a1);
  list_uint_free(a2);
}

/********************************************************************************************/

#define my_cmp(a,b) ( (a) < (b) ? -1 : (a) > (b) )

#define K unsigned long
#define V bool
#define PFX tree_ulong
#define SNAME tree_ulong_s
#include "cmc/treemap.h"

static int cmp_ulong(unsigned long a, unsigned long b) { return my_cmp(a,b); }

static void test_rbtree(size_t n)
{
  struct tree_ulong_s *tree;
  tree = tree_ulong_new(&(struct tree_ulong_s_fkey){ .cmp = cmp_ulong }, 
                        &(struct tree_ulong_s_fval){ });

  for (size_t i = 0; i < n; i++) {
    unsigned long j = rand_get();
    tree_ulong_insert(tree, j, true);
  }
    
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long j = rand_get();
    if (tree_ulong_get_ref(tree, j) != 0)
      s+= j;
  }
  g_result = s;
  tree_ulong_free(tree);
}

/********************************************************************************************/

static size_t hash_ulong(unsigned long a)
{
  return ( (a) >> 33 ) ^ (a) ^ ((a) << 11);
}

#define K unsigned long
#define V unsigned long
#define PFX hmap
#define SNAME hmap_s
#include "cmc/hashmap.h"

static void
test_dict(size_t  n)
{
  struct hmap_s *dict = hmap_new(16, 0.7, 
                                 &(struct hmap_s_fkey){ .cmp = cmp_ulong, .hash = hash_ulong },
                                 &(struct hmap_s_fval){ });
  
  for (size_t i = 0; i < n; i++) {
    hmap_insert(dict, rand_get(), rand_get());
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long *val = hmap_get_ref(dict, rand_get());
    if (val != 0)
      s += *val;
  }
  g_result = s;
  
  hmap_free(dict);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 110,   "Seq(Array)", C_N_SEQ_ARRAY, 0, test_array, 0},
  { 200,  "SSet(tree)", C_N_SSET, 0, test_rbtree, 0},
  { 300,    "UMap U64(hmap)", C_N_UMAP_U64, 0, test_dict, 0},
};

int main(int argc, const char *argv[])
{
  test("CMC", numberof(table), table, argc, argv);
  exit(0);
}


