#define NDEBUG

#include <stdlib.h>
#include <stdio.h>

#include "opencstl.h"

#include "common.h"

/********************************************************************************************/

static void test_array(size_t n)
{
  VECTOR(unsigned int) a1 = new_vector(unsigned int);
  VECTOR(unsigned int) a2 = new_vector(unsigned int);
  if (!a1 || !a2) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    push_back(a1, rand_get());
    push_back(a2, rand_get());
  }

  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    s += a1[i] * a2[i];
  }
  g_result = s;

  destroy(a1);
  destroy(a2);
}

/********************************************************************************************/

static void test_deque(size_t n)
{
  DEQUE(unsigned int) a1 = new_deque(unsigned int);
  DEQUE(unsigned int) a2 = new_deque(unsigned int);
  if (!a1 || !a2) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    push_back(a1, rand_get());
    push_back(a2, rand_get());
  }

  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    s += a1[i] * a2[i];
  }
  g_result = s;

  destroy(a1);
  destroy(a2);
}

/********************************************************************************************/

static void test_list(size_t n)
{
  LIST(unsigned int) a1 = new_list(unsigned int);
  LIST(unsigned int) a2 = new_list(unsigned int);
  if (!a1 || !a2) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    push_back(a1, rand_get());
    push_back(a2, rand_get());
  }

  unsigned int s = 0;
  unsigned int *it1 = begin(a1);
  unsigned int *it2 = begin(a2);
  while (it1 != end(a1)) {
    s += (*it1) * (*it2);
    it1 = next(it1);
    it2 = next(it2);
  }
  g_result = s;

  destroy(a1);
  destroy(a2);
}

/********************************************************************************************/

static void test_set(size_t n)
{
  SET(unsigned long) tree = new_set(unsigned long);
  if (!tree) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    insert(tree, rand_get());
  }

  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long *p = find(tree, rand_get());
    if (p != NULL) {
      s += *p;
    }
  }
  g_result = s;

  destroy(tree);
}

/********************************************************************************************/

static void test_dict(size_t n)
{
  UNORDERED_MAP(unsigned long) dict = new_unordered_map(unsigned long, unsigned long);
  if (!dict) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    unsigned long value = rand_get();
    unsigned long key = rand_get();
    insert(dict, key, value);
  }

  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long *p = find(dict, rand_get());
    if (p != NULL) {
      s += second(p, unsigned long);
    }
  }
  g_result = s;

  destroy(dict);
}

/********************************************************************************************/

#define TST_MAX(a,b) ((a) < (b) ? (b) : (a))

// Returns length of the longest contiguous subsequence.
static void bench_find_longest(size_t n)
{
  int *arr = (int *) malloc(n * sizeof(int));
  if (!arr) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    arr[i] = (int) rand_get();
  }

  UNORDERED_SET(int) set = new_unordered_set(int);
  if (!set) {
    free(arr);
    abort();
  }

  int ans = 0;
  for (size_t i = 0; i < n; i++) {
    insert(set, arr[i]);
  }

  for (size_t i = 0; i < n; i++) {
    if (find(set, arr[i] - 1) == NULL) {
      int j = arr[i] + 1;
      while (find(set, j) != NULL) {
        j++;
      }
      ans = TST_MAX(ans, j - arr[i]);
    }
  }

  destroy(set);
  free(arr);
  g_result = (unsigned long) ans;
}

/********************************************************************************************/

static int float_cmp(const void *a, const void *b)
{
  const float fa = *(const float *) a;
  const float fb = *(const float *) b;
  return (fa > fb) - (fa < fb);
}

static void test_sort(size_t n)
{
  VECTOR(float) a1 = new_vector(float);
  if (!a1) {
    abort();
  }

  for (size_t i = 0; i < n; i++) {
    push_back(a1, (float) rand_get());
  }

  qsort(a1, size(a1), sizeof(float), float_cmp);
  g_result = (unsigned long) a1[0];

  destroy(a1);
}

/********************************************************************************************/

const config_func_t table[] = {
  { 100, "Seq(List)", C_N_SEQ_LIST, 0, test_list, 0},
  { 110, "Seq(Array)", C_N_SEQ_ARRAY, 0, test_array, 0},
  { 120, "Seq(Deque)", C_N_SEQ_ARRAY, 0, test_deque, 0},
  { 200, "SSet(Set)", C_N_SSET, 0, test_set, 0},
  { 300, "UMap U64", C_N_UMAP_U64, 0, test_dict, 0},
  { 340, "USet Longest", C_N_FIND_SEQ, 0, bench_find_longest, 0},
  { 500, "Sort", C_N_SORT, 0, test_sort, 0},
};

int main(int argc, const char *argv[])
{
  test("OpenCSTL", numberof(table), table, argc, argv);
  return 0;
}