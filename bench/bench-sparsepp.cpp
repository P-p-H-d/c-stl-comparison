#define NDEBUG

#include <vector>
#include <list>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <sparsepp/spp.h>

using spp::sparse_hash_map;
using namespace std;

#include "common.h"

/********************************************************************************************/

static void
test_dict2(size_t  n)
{
  sparse_hash_map<unsigned long, unsigned long> dict;

  for (size_t i = 0; i < n; i++) {
    auto v = rand_get(); dict[rand_get()] = v;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    sparse_hash_map<unsigned long, unsigned long>::iterator it = dict.find(rand_get());
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
  sparse_hash_map<char_array_s, char_array_s> dict;

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
    sparse_hash_map<char_array_s, char_array_s>::iterator it = dict.find(s1);
    if (it != dict.end())
      s ++;
  }
  g_result = s;
}

/********************************************************************************************/
static void
test_dict_str(size_t  n)
{
  sparse_hash_map<string, string> dict;

  for (size_t i = 0; i < n; i++) {
    string s1 = static_cast<ostringstream*>( &(ostringstream() << rand_get()) )->str();
    string s2 = static_cast<ostringstream*>( &(ostringstream() << rand_get()) )->str();
    dict[s1] = s2;
  }
  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    string s1 = static_cast<ostringstream*>( &(ostringstream() << rand_get()) )->str();
    sparse_hash_map<string, string>::iterator it = dict.find(s1);
    if (it != dict.end())
      s ++;
  }
  g_result = s;
}

/********************************************************************************************/

const config_func_t table[] = {
  { 41, "dictBig", 1000000, 0, test_dict_big, 0},
  { 42,    "dict", 10000000, 0, test_dict2, 0},
  { 43, "DictStr", 1000000, 0, test_dict_str, 0}
};

int main(int argc, const char *argv[])
{
  test("SPARSEPP", numberof(table), table, argc, argv);
  exit(0);
}
