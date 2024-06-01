#include <string>
#include <iostream>

#include "common.h"

using namespace std;

#define INIT(x)        (new (&(x)) string())
#define CLEAR(x)       ((&(x))->~string())

void pass1(int n, string tab[])
{
  for(int i = 0; i < n; i++)
    INIT(tab[i]);
}

void pass2(int n, string tab[])
{
  for(int i = 0; i < n; i++)
    tab[i] = "THIS IS IT";
}

void pass3(string &dst, int n, string tab[])
{
  for(int i = 0; i < n; i++)
    dst += tab[i];
}

void pass4(int n, string tab[])
{
  for(int i = 0; i < n; i++)
    CLEAR(tab[i]);
}

int main(int argc, const char *argv[])
{
  int n = argc >= 2 ? atoi(argv[1]): 200000000;
  unsigned long long t0 = cputime();
  string *tab = (string *) malloc (n * sizeof(string)), dst;
  if (!tab) abort(); 
  pass1(n, tab);
  pass2(n, tab);
  pass3(dst, n, tab);
  pass4(n, tab);
  free(tab);
  unsigned long long t1 = cputime();
  cout << "BENCH STRING 3 / STL: TIME=" << t1 - t0 << " ms LENGTH=" << dst.size() << endl;
  exit(0);
}
