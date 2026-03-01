#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define XXH_STATIC_LINKING_ONLY /* access advanced declarations */
#define XXH_IMPLEMENTATION      /* access definitions */

#include "xxhash.h"

#include "common.h"

static unsigned long *g_p;

static void test_hash_prepare(size_t n)
{
  g_p = malloc (n * sizeof(unsigned long));
  if (g_p == NULL) abort();
  for(size_t i = 0; i < n ; i++)
    g_p[i] = ((rand_get()*RAND_MAX + rand_get())*RAND_MAX+rand_get())*RAND_MAX + rand_get();
}


static void test_hash_final(void)
{
  free(g_p);
}

static void test_hash(size_t n)
{
  g_result = XXH64(g_p, sizeof(unsigned long)*n, 0);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 700,         "Hash (xxhash64)", 1000000000,test_hash_prepare, test_hash, test_hash_final}
};

int main(int argc, const char *argv[])
{
  test("XXHASH", numberof(table), table, argc, argv);
  exit(0);
}
