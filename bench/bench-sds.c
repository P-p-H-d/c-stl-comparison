#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "common.h"
#include "sds.h"

/********************************************************************************************/

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

sds SDS_replace_at(sds str, size_t pos, size_t len, const char str2[])
{
  // simple implementation as replace is not available
  sds a = sdsnewlen((const void*) str, pos);
  a = sdscat(a, str2);
  a = sdscat(a, &str[pos+len]);
  sdsfree(str);
  return a;
}

sds replace_all_sds(sds str, const char pattern[], const char replace[])
{
  size_t pos = 0;
  do {
    char *p = strstr(&str[pos], pattern);
    pos = p == NULL ? -1U : (p - str);
    if (pos != -1U) {
      str = SDS_replace_at(str, pos, strlen(pattern), replace);
    }
  } while (pos != -1U);
  return str;
}

static void bench_string_replace(size_t n)
{
  sds *tab = (sds*) malloc (n * sizeof (sds));
  assert (tab != 0);
  // P1
  for(unsigned i = 0; i < n; i++) {
    tab[i] =  sdsfromlonglong(rand_get());
  }
  // P2
  sds str = sdsempty();
  for(unsigned i = 0; i < n; i++) {
    str = sdscat(str, tab[permutation_tab[i]]);
  }
  // P3
  str = replace_all_sds(str, "1234", "WELL");
  str = replace_all_sds(str, "56789", "DONE");
  // Clean
  size_t length = sdslen(str);
  sdsfree(str);
  for(unsigned i = 0; i < n; i++) {
    sdsfree(tab[i]);
  }
  free(tab);
  g_result = length;
}

/********************************************************************************************/

const config_func_t table[] = {
  { 900, "String Replace", C_N_STR_REPLACE, bench_string_replace_init, bench_string_replace, bench_string_replace_clear}
};

int main(int argc, const char *argv[])
{
  test("SDS", numberof(table), table, argc, argv);
  exit(0);
}

