#define NDEBUG

#include <Misra.h>

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

/********************************************************************************************/

static void
test_array(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Vec(unsigned int) a1 = VecInit();
    Vec(unsigned int) a2 = VecInit();

    for (size_t i = 0; i < n; i++) {
      VecMustPushBackR(&a1, rand_get());
      VecMustPushBackR(&a2, rand_get());
    }

    unsigned int s = 0;
    for (size_t i = 0; i < n; i++) {
      s += VecAt(&a1, i) * VecAt(&a2, i);
    }
    g_result = s;

    VecDeinit(&a1);
    VecDeinit(&a2);
  }
}

/********************************************************************************************/

static void
test_list(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    List(unsigned int) a1 = ListInit();
    List(unsigned int) a2 = ListInit();

    for (size_t i = 0; i < n; i++) {
      ListMustPushBackR(&a1, rand_get());
      ListMustPushBackR(&a2, rand_get());
    }

    unsigned int s = 0;
    GenericListNode *it1 = GENERIC_LIST_NODE(a1.head);
    GenericListNode *it2 = GENERIC_LIST_NODE(a2.head);
    while (it1 != NULL && it2 != NULL) {
      s += *(unsigned int *)it1->data * *(unsigned int *)it2->data;
      it1 = it1->next;
      it2 = it2->next;
    }
    g_result = s;

    ListDeinit(&a1);
    ListDeinit(&a2);
  }
}

/********************************************************************************************/

static u64
ulong_hash(const void *data, u32 size)
{
  const unsigned long *s = (const unsigned long *)data;
  u64 hash = UINT64_C(1469598103934665603);
  hash ^= (u64)(*s);
  hash *= UINT64_C(1099511628211);
  (void)size;

  return hash;
}

static i32
ulong_compare(const void *lhs, const void *rhs)
{
  const unsigned long *a = (const unsigned long *)lhs;
  const unsigned long *b = (const unsigned long *)rhs;
  return (*a > *b) - (*a < *b);
}

static void
test_dict(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Map(unsigned long, unsigned long) dict = MapInit(ulong_hash, ulong_compare);

    for (size_t i = 0; i < n; i++) {
      unsigned long value = (unsigned long)rand_get();
      unsigned long key = (unsigned long)rand_get();
      MapMustInsertR(&dict, key, value);
    }

    rand_init();
    unsigned int s = 0;
    for (size_t i = 0; i < n; i++) {
      unsigned long *val = MapTryGetPtr(&dict, (unsigned long)rand_get());
      if (val != NULL) {
        s += (unsigned int)*val;
      }
    }
    g_result = s;

    MapDeinit(&dict);
  }
}

/********************************************************************************************/

static u64
str_hash(const void *data, u32 size)
{
  const Str *s = (const Str *)data;
  const unsigned char *ptr = (const unsigned char *)StrBegin(s);
  u64 hash = UINT64_C(1469598103934665603);

  (void)size;

  for (u64 i = 0; i < (u64)StrLen(s); i++) {
    hash ^= (u64)ptr[i];
    hash *= UINT64_C(1099511628211);
  }

  return hash;
}

static i32
str_compare(const void *lhs, const void *rhs)
{
  const Str *a = (const Str *)lhs;
  const Str *b = (const Str *)rhs;
  return StrCmp(a, b);
}

static void
test_dict_big(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Map(Str, Str) dict =
        MapInitWithDeepCopy(str_hash, str_compare, str_init_copy, str_deinit, str_init_copy, str_deinit);

    for (size_t i = 0; i < n; i++) {
      Str key = StrInit();
      Str value = StrInit();
      StrAppendf(&key, "%u", rand_get());
      StrAppendf(&value, "%u", rand_get());
      MapMustInsertL(&dict, key, value);
      StrDeinit(&key);
      StrDeinit(&value);
    }

    rand_init();
    unsigned int s = 0;
    for (size_t i = 0; i < n; i++) {
      Str key = StrInit();
      StrAppendf(&key, "%u", rand_get());
      // MapTryGetPtr doesn't currently support non-scalar keys in this version.
      Str *val = (Str *)map_get_value_ptr(
          GENERIC_MAP(&dict),
          &key,
          sizeof(MAP_ENTRY_TYPE(&dict)),
          offsetof(MAP_ENTRY_TYPE(&dict), key),
          sizeof(MAP_KEY_TYPE(&dict)),
          offsetof(MAP_ENTRY_TYPE(&dict), value),
          offsetof(MAP_ENTRY_TYPE(&dict), hash));
      if (val != NULL) {
        s++;
      }
      StrDeinit(&key);
    }
    g_result = s;

    MapDeinit(&dict);
  }
}

static void
test_dict_str(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Map(Str, Str) dict =
        MapInitWithDeepCopy(str_hash, str_compare, str_init_copy, str_deinit, str_init_copy, str_deinit);

    for (size_t i = 0; i < n; i++) {
      Str key = StrInit();
      Str value = StrInit();
      StrAppendf(&key, "%u", rand_get());
      StrAppendf(&value, "%u", rand_get());
      MapMustInsertL(&dict, key, value);
      StrDeinit(&key);
      StrDeinit(&value);
    }

    rand_init();
    unsigned int s = 0;
    for (size_t i = 0; i < n; i++) {
      Str key = StrInit();
      StrAppendf(&key, "%u", rand_get());
      // MapTryGetPtr doesn't currently support non-scalar keys in this version.
      Str *val = (Str *)map_get_value_ptr(
          GENERIC_MAP(&dict),
          &key,
          sizeof(MAP_ENTRY_TYPE(&dict)),
          offsetof(MAP_ENTRY_TYPE(&dict), key),
          sizeof(MAP_KEY_TYPE(&dict)),
          offsetof(MAP_ENTRY_TYPE(&dict), value),
          offsetof(MAP_ENTRY_TYPE(&dict), hash));
      if (val != NULL) {
        s++;
      }
      StrDeinit(&key);
    }
    g_result = s;

    MapDeinit(&dict);
  }
}

/********************************************************************************************/

#define TST_MAX(a, b) ((a) < (b) ? (b) : (a))

static u64
i32_hash(const void *data, u32 size)
{
  uint64_t x = (uint64_t)(uint32_t)(*(const int *)data);
  (void)size;
  x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
  x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
  x = x ^ (x >> 31);
  return (u64)x;
}

static i32
i32_compare(const void *lhs, const void *rhs)
{
  int a = *(const int *)lhs;
  int b = *(const int *)rhs;
  return (a > b) - (a < b);
}

static void
bench_find_longest(size_t n)
{
  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    abort();
  }

  Scope(alloc, DefaultAllocator)
  {
    Map(int, bool) set = MapInit(i32_hash, i32_compare);

    for (size_t i = 0; i < n; i++) {
      arr[i] = (int)rand_get();
      MapMustInsertR(&set, arr[i], true);
    }

    int ans = 0;
    for (size_t i = 0; i < n; i++) {
      if (MapTryGetPtr(&set, arr[i] - 1) == NULL) {
        int j = arr[i] + 1;
        while (MapTryGetPtr(&set, j) != NULL) {
          j++;
        }
        ans = TST_MAX(ans, j - arr[i]);
      }
    }

    g_result = (unsigned long)ans;
    MapDeinit(&set);
  }

  free(arr);
}

/********************************************************************************************/

static i32
bench_float_compare(const void *a, const void *b)
{
  float x = *(const float *)a;
  float y = *(const float *)b;
  return (x > y) - (x < y);
}

static void
test_sort(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Vec(float) a1 = VecInit();

    for (size_t i = 0; i < n; i++) {
      VecMustPushBackR(&a1, (float)rand_get());
    }
    VecSort(&a1, bench_float_compare);
    g_result = (unsigned long)VecAt(&a1, 0);

    VecDeinit(&a1);
  }
}

/********************************************************************************************/

static unsigned *permutation_tab = NULL;

static void
bench_string_replace_init(size_t n)
{
  free(permutation_tab);
  permutation_tab = (unsigned *)malloc(n * sizeof(unsigned));
  if (permutation_tab == NULL) {
    abort();
  }
  for (unsigned i = 0; i < n; i++) {
    permutation_tab[i] = i;
  }
  for (unsigned i = 0; i < n; i++) {
    unsigned j = rand_get() % n;
    unsigned k = rand_get() % n;
    unsigned l = permutation_tab[j];
    permutation_tab[j] = permutation_tab[k];
    permutation_tab[k] = l;
  }
}

static void
bench_string_replace_clear(void)
{
  free(permutation_tab);
  permutation_tab = NULL;
}

static void
bench_string_replace(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Str *tab = (Str *)malloc(n * sizeof(Str));
    if (tab == NULL) {
      abort();
    }

    for (size_t i = 0; i < n; i++) {
      tab[i] = StrInit();
      StrAppendf(&tab[i], "%u", rand_get());
    }

    Str str = StrInit();
    for (size_t i = 0; i < n; i++) {
      StrMustPushBackCstr(&str, StrBegin(&tab[permutation_tab[i]]), StrLen(&tab[permutation_tab[i]]));
    }

    StrReplaceZstr(&str, "1234", "WELL", (size)-1);
    StrReplaceZstr(&str, "56789", "DONE", (size)-1);
    g_result = (unsigned long)StrLen(&str);

    StrDeinit(&str);
    for (size_t i = 0; i < n; i++) {
      StrDeinit(&tab[i]);
    }
    free(tab);
  }
}

static void
bench_string_concat(size_t n)
{
  Scope(alloc, DefaultAllocator)
  {
    Str *tab = (Str *)malloc(n * sizeof(Str));
    if (tab == NULL) {
      abort();
    }

    Str dst = StrInit();
    for (size_t i = 0; i < n; i++) {
      tab[i] = StrInit();
      StrMustPushBackZstr(&tab[i], "THIS IS IT");
    }

    for (size_t i = 0; i < n; i++) {
      StrMustPushBackCstr(&dst, StrBegin(&tab[i]), StrLen(&tab[i]));
    }

    g_result = (unsigned long)StrLen(&dst);

    StrDeinit(&dst);
    for (size_t i = 0; i < n; i++) {
      StrDeinit(&tab[i]);
    }
    free(tab);
  }
}

/********************************************************************************************/

const config_func_t table[] = {
  {100, "Seq(List)", C_N_SEQ_LIST, 0, test_list, 0},
  {110, "Seq(Array)", C_N_SEQ_ARRAY, 0, test_array, 0},
  {300, "UMap U64(Map)", C_N_UMAP_U64, 0, test_dict, 0},
  {320, "UMap Big(Map)", C_N_UMAP_BIG, 0, test_dict_big, 0},
  {330, "UMap Str(Map)", C_N_UMAP_BIG, 0, test_dict_str, 0},
  {340, "USet Longest(Map)", C_N_FIND_SEQ, 0, bench_find_longest, 0},
  {500, "Sort", C_N_SORT, 0, test_sort, 0},
  {900, "String Replace", C_N_STR_REPLACE, bench_string_replace_init, bench_string_replace, bench_string_replace_clear},
  {910, "String Concat", C_N_STR_CONCAT, 0, bench_string_concat, 0},
};

int
main(int argc, const char *argv[])
{
  test("MisraStdC", numberof(table), table, argc, argv);
  exit(0);
}
