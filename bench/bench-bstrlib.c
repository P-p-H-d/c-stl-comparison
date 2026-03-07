#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "common.h"

#include "bstrlib.h"
#include "bstrwrap.h"
#include "bstraux.h"

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

static void bench_string_replace(size_t n)
{
  bstring *tab = (bstring*) malloc (n * sizeof (bstring));
  assert (tab != 0);
  // P1
  for(unsigned i = 0; i < n; i++) {
    char tmp[10];
    sprintf(tmp, "%u", rand_get());
    tab[i] = bfromcstr(tmp);
  }
  // P2
  bstring str = bfromcstr("");
  for(unsigned i = 0; i < n; i++) {
    bconcat(str, tab[permutation_tab[i]]);
  }
  // P3
  bstring c1 = bfromcstr("1234"), c2 = bfromcstr("WELL"), c3 = bfromcstr("56789"), c4 = bfromcstr("DONE");
  bfindreplace(str, c1, c2, 0);
  bfindreplace(str, c3, c4, 0);
  // Clean
  size_t length = blength(str);
  bdestroy(str);
  bdestroy(c1);
  bdestroy(c2);
  bdestroy(c3);
  bdestroy(c4);
  for(unsigned i = 0; i < n; i++) {
    bdestroy(tab[i]);
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

