#define NDEBUG

#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

#include "common.h"

/********************************************************************************************/

static void test_list(size_t n)
{
  list<unsigned int> a1, a2;
  for(size_t i = 0; i < n; i++) {
    a1.push_back(rand_get() );
    a2.push_back(rand_get() );
  }
  unsigned int s = 0;
  for (list<unsigned int>::const_iterator ci1 = a1.begin(), ci2 = a2.begin (); ci1 != a1.end(); ++ci1, ++ci2) {
    s += *ci1 * *ci2;
  }
  g_result = s;
}

/********************************************************************************************/

static void test_array(size_t n)
{
  vector<unsigned int> a1, a2;
  for(size_t i = 0; i < n; i++) {
    a1.push_back(rand_get() );
    a2.push_back(rand_get() );
  }
  unsigned int s = 0;
  for(unsigned long i = 0; i < n; i++) {
    s += a1[i] * a2[i];
  }
  g_result = s;
}

/********************************************************************************************/

static void test_deque(size_t n)
{
  deque<unsigned int> a1, a2;
  for(size_t i = 0; i < n; i++) {
    a1.push_back(rand_get() );
    a2.push_back(rand_get() );
  }
  unsigned int s = 0;
  for(auto it1 = a1.cbegin(), it2 = a2.cbegin();
      it1 != a1.cend() ;it1++, it2++) {
    s += *it1 * *it2;
  }
  g_result = s;
}

/********************************************************************************************/

static void test_rbtree(size_t n)
{
  set<unsigned long> tree;

  for (size_t i = 0; i < n; i++) {
    tree.insert(rand_get());
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    set<unsigned long>::iterator it = tree.find(rand_get());
    if (it != tree.end())
      s += *it;
  }
  g_result = s;
}

/********************************************************************************************/

static void
test_dict1(size_t  n)
{
  map<unsigned long, unsigned long> dict;

  for (size_t i = 0; i < n; i++) {
    auto v = rand_get(); dict[rand_get()] = v;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    map<unsigned long, unsigned long>::iterator it = dict.find(rand_get());
    if (it != dict.end())
      s += it->second;
  }
  g_result = s;
}

/********************************************************************************************/

static void
test_dict2(size_t  n)
{
  unordered_map<unsigned long, unsigned long> dict;

  for (size_t i = 0; i < n; i++) {
    auto v = rand_get(); dict[rand_get()] = v;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unordered_map<unsigned long, unsigned long>::iterator it = dict.find(rand_get());
    if (it != dict.end())
      s += it->second;
  }
  g_result = s;
}

static void
test_dict2_linear(size_t  n)
{
  unordered_map<unsigned long, unsigned long> dict;

  for (size_t i = 0; i < n; i++) {
    dict[i] = rand_get();
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unordered_map<unsigned long, unsigned long>::iterator it = dict.find(i);
    if (it != dict.end())
      s += it->second;
  }
  g_result = s;
}

/********************************************************************************************/

struct char_array_s {
  char a[256];
  char_array_s () { a[0] = 0 ; }
  char_array_s ( const char_array_s & other) { strcpy(a, other.a); }
  bool operator==(const char_array_s &other) const { return strcmp(a, other.a) == 0; }
};

namespace std {
  template <> struct hash<char_array_s> {
    std::size_t operator()(const char_array_s &k) const {
      size_t hash = 0;
      const char *s = k.a;
      while (*s) hash = hash * 31421 + (*s++) + 6927;
      return hash;
    };
  };
}

static void
test_dict_big(size_t  n)
{
  unordered_map<char_array_s, char_array_s> dict;

  for (size_t i = 0; i < n; i++) {
    char_array_s s1, s2;
    sprintf(s1.a, "%u", rand_get());
    sprintf(s2.a, "%u", rand_get());
    dict[s1] = s2;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    char_array_s s1;
    sprintf(s1.a, "%u", rand_get());
    unordered_map<char_array_s, char_array_s>::iterator it = dict.find(s1);
    if (it != dict.end())
      s ++;
  }
  g_result = s;
}

/********************************************************************************************/
static void
test_dict_str(size_t  n)
{
  unordered_map<string, string> dict;

  for (size_t i = 0; i < n; i++) {
    string s1 = to_string(rand_get());
    string s2 = to_string(rand_get());
    dict[s1] = s2;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    string s1 = to_string (rand_get());
    unordered_map<string, string>::iterator it = dict.find(s1);
    if (it != dict.end())
      s ++;
  }
  g_result = s;
}

static void
test_dict_str2(size_t  n)
{
  map<string, string> dict;

  for (size_t i = 0; i < n; i++) {
    string s1 = to_string(rand_get());
    string s2 = to_string(rand_get());
    dict[s1] = s2;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    string s1 = to_string(rand_get());
    map<string, string>::iterator it = dict.find(s1);
    if (it != dict.end())
      s ++;
  }
  g_result = s;
}

/********************************************************************************************/

// Returns length of the longest contiguous subsequence 
void bench_find_longest(size_t n)
{
  int *arr = (int*) malloc(n * sizeof(int));
  for(size_t i = 0; i < n; i++)
    arr[i] = rand_get();

  unordered_set<int> S; 
  int ans = 0; 
  
  // Hash all the array elements 
  for (size_t i = 0; i < n; i++)
    S.insert(arr[i]);
  
  // check each possible sequence from the start then update optimal length 
  for (size_t i = 0; i < n; i++) {
    // if current element is the starting element of a sequence 
    if (S.find(arr[i] - 1) == S.end()) {
      // Then check for next elements in the sequence 
      int j = arr[i] + 1;
      while (S.find(j) != S.end())
        j++;
      // update  optimal length if this length is more 
      ans = max(ans, j - arr[i]);
    } 
  } 

  free(arr);
  g_result = ans;
} 

/********************************************************************************************/

static void test_sort(size_t n)
{
  vector<float> a1;
  for(size_t i = 0; i < n; i++) {
    a1.push_back(rand_get() );
  }
  sort(a1.begin(), a1.end());
  g_result = a1[0];
}

static void test_stable_sort(size_t n)
{
  vector<float> a1;
  for(size_t i = 0; i < n; i++) {
    a1.push_back(rand_get() );
  }
  stable_sort(a1.begin(), a1.end());
  g_result = a1[0];
}

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

static void replace_all_stl(string &str, const char pattern[], const char replace[])
{
  size_t pos = 0;
  do {
    pos = str.find(pattern, pos);
    if (pos != string::npos) {
      str.replace (pos, strlen(pattern), replace);
    }
  } while (pos != string::npos);
}

static void bench_string_replace(size_t n)
{
  vector<string> tab;
  tab.resize(n);
  for(unsigned i = 0; i < n; i++)
    tab[i] = to_string(rand_get());

  string str;
  for(unsigned i = 0; i < n; i++) {
    str += tab[permutation_tab[i]];
  }

  replace_all_stl(str, "1234", "WELL");
  replace_all_stl(str, "56789", "DONE");

  g_result = str.length();
}

#define INIT(x)        (new (&(x)) string())
#define CLEAR(x)       ((&(x))->~string())

static void bench_string_concat(size_t n)
{
  string *tab = (string *) malloc (n * sizeof(string)), dst;
  if (!tab) abort(); 
  for(size_t i = 0; i < n; i++)
    INIT(tab[i]);
  for(size_t i = 0; i < n; i++)
    tab[i] = "THIS IS IT";
  for(size_t i = 0; i < n; i++)
    dst += tab[i];
  for(size_t i = 0; i < n; i++)
    CLEAR(tab[i]);
  free(tab);
  g_result = dst.size();
}

/********************************************************************************************/

const config_func_t table[] = {
  { 100,    "Seq(List)", C_N_SEQ_LIST, 0, test_list, 0},
  { 110,   "Seq(Array)", C_N_SEQ_ARRAY, 0, test_array, 0},
  { 120,   "Seq(Deque)", C_N_SEQ_ARRAY, 0, test_deque, 0},
  { 200,  "SSet(Rbtree)", C_N_SSET, 0, test_rbtree, 0},
  { 300, "UMap U64(map)", C_N_UMAP_U64, 0, test_dict1, 0},
  { 301, "UMap U64(umap)", C_N_UMAP_U64, 0, test_dict2, 0},
  { 320, "UMap Big(umap)", C_N_UMAP_BIG, 0, test_dict_big, 0},
  { 330, "UMap Str(umap)", C_N_UMAP_BIG, 0, test_dict_str, 0},
  { 331,  "UMap Str(map)", C_N_UMAP_BIG, 0, test_dict_str2, 0},
  { 340, "USet Longest(dict oa)", C_N_FIND_SEQ, 0, bench_find_longest, 0},
  { 310, "UMAP U64 Linear(umap)", C_N_UMAP_U64, 0, test_dict2_linear, 0},
  { 500,          "Sort", C_N_SORT, 0, test_sort, 0},
  { 510,   "Stable Sort", C_N_SORT, 0, test_stable_sort, 0},
  { 900, "String Replace", C_N_STR_REPLACE, bench_string_replace_init, bench_string_replace, bench_string_replace_clear},
  { 910, "String Concat", C_N_STR_CONCAT, 0, bench_string_concat, 0},
};

int main(int argc, const char *argv[])
{
  test("STL", numberof(table), table, argc, argv);
  exit(0);
}
