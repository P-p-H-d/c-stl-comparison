#include "m-string.h"
#include "common.h"

void pass1(int n, string_t tab[n])
{
  for(int i = 0; i < n; i++)
    string_init(tab[i]);
}

void pass2(int n, string_t tab[n])
{
  for(int i = 0; i < n; i++)
    string_set(tab[i], "THIS IS IT");
}

void pass3(string_t dst, int n, string_t tab[n])
{
  for(int i = 0; i < n; i++)
    string_cat(dst, tab[i]);
}

void pass4(int n, string_t tab[n])
{
  for(int i = 0; i < n; i++)
    string_clear(tab[i]);
}

int main(int argc, const char *argv[])
{
  int n = argc >= 2 ? atoi(argv[1]): 200000000;
  unsigned long long t0 = cputime();
  string_t *tab = (string_t *) malloc (n * sizeof(string_t)), dst;
  if (!tab) abort();
  string_init(dst);
  pass1(n, tab);
  pass2(n, tab);
  pass3(dst, n, tab);
  pass4(n, tab);
  size_t s = string_size(dst);
  string_clear(dst);
  free(tab);
  unsigned long long t1 = cputime();
  printf("BENCH STRING 3 / M*LIB: TIME=%llu ms LENGTH=%zu\n", t1-t0, s);
  exit(0);
}
