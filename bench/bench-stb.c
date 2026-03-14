#include <stdio.h>
#include <stdlib.h>
#define STB_DS_IMPLEMENTATION
#include <stb_ds.h>

#include "common.h"

/********************************************************************************************/

static void test_array(size_t n)
{
  unsigned int* a1 = NULL;
  unsigned int* a2 = NULL;
  
  for(size_t i = 0; i < n; i++) {
    unsigned int v = rand_get();
    arrput(a1, v );
    v = rand_get();
    arrput(a2, v );
  }

  unsigned int s = 0;
  for(unsigned long i = 0; i < n; i++) {
    s += a1[i] * a2[i];
  }
  g_result = s;
  arrfree(a1);
  arrfree(a2);
}

/********************************************************************************************/

#define typeof(x) __typeof(x)

typedef struct {
  unsigned long key;
  unsigned long value;
} pair64_t;

static void
test_dict(size_t  n)
{
  pair64_t *dict = NULL;

  for (size_t i = 0; i < n; i++) {
    unsigned long key = rand_get();
    unsigned long value = rand_get();
    hmput(dict, key, value);
  }    
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long key = rand_get();
    pair64_t *p = hmgetp_null(dict, key);
    if (p)
      s += p->value;
  }
  g_result = s;
  hmfree(dict);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 110,   "Seq(DynArray)", C_N_SEQ_ARRAY, 0, test_array, 0},
  { 300,    "UMap U64(DynHas)", C_N_UMAP_U64, 0, test_dict, 0},
};

int main(int argc, const char *argv[])
{
  test("STB-DS", numberof(table), table, argc, argv);
  exit(0);
}
