#define NDEBUG

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ccc/flat_buffer.h"
#include "ccc/flat_hash_map.h"
#include "ccc/sort.h"
#include "ccc/tree_map.h"

#include "common.h"

/********************************************************************************************/

static void *
my_alloc(CCC_Allocator_arguments const args)
{
  if (!args.input && !args.bytes)
    return NULL;
  if (!args.input)
    return malloc(args.bytes);
  if (!args.bytes) {
    free(args.input);
    return NULL;
  }
  return realloc(args.input, args.bytes);
}

static void
test_array(size_t n)
{
  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_buffer a1 = CCC_flat_buffer_default(unsigned int);
  CCC_Flat_buffer a2 = CCC_flat_buffer_default(unsigned int);

  for (size_t i = 0; i < n; i++) {
    unsigned int v1 = rand_get();
    unsigned int v2 = rand_get();
    if (!CCC_flat_buffer_push_back(&a1, &v1, &alloc))
      abort();
    if (!CCC_flat_buffer_push_back(&a2, &v2, &alloc))
      abort();
  }

  unsigned int s = 0;
  unsigned int const *it1 = CCC_flat_buffer_begin(&a1);
  unsigned int const *it2 = CCC_flat_buffer_begin(&a2);
  unsigned int const *const end1 = CCC_flat_buffer_end(&a1);
  for (; it1 != end1; it1 = CCC_flat_buffer_next(&a1, it1), it2 = CCC_flat_buffer_next(&a2, it2)) {
    s += (*it1) * (*it2);
  }
  g_result = s;

  (void)CCC_flat_buffer_clear_and_free(&a1, &(CCC_Destructor){}, &alloc);
  (void)CCC_flat_buffer_clear_and_free(&a2, &(CCC_Destructor){}, &alloc);
}

/********************************************************************************************/

struct tree_item {
  unsigned long key;
  bool value;
  CCC_Tree_map_node node;
};

static CCC_Order
cmp_ulong_key(CCC_Key_comparator_arguments const args)
{
  unsigned long const left = *(unsigned long const *)args.key_left;
  struct tree_item const *const right = args.type_right;
  return (left < right->key) ? CCC_ORDER_LESSER
       : (left > right->key) ? CCC_ORDER_GREATER
                             : CCC_ORDER_EQUAL;
}

static void
test_rbtree(size_t n)
{
  CCC_Tree_map tree = CCC_tree_map_default(
      struct tree_item, node, key, ((CCC_Key_comparator){.compare = cmp_ulong_key}));
  struct tree_item *items = malloc(n * sizeof(*items));
  if (!items)
    abort();

  for (size_t i = 0; i < n; i++) {
    items[i].key = rand_get();
    items[i].value = true;
    CCC_Entry const res =
        CCC_tree_map_insert_or_assign(&tree, &items[i].node, &(CCC_Allocator){});
    if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL)
      abort();
  }

  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long const key = rand_get();
    struct tree_item const *const p = CCC_tree_map_get_key_value(&tree, &key);
    if (p)
      s += p->key;
  }
  g_result = s;

  (void)CCC_tree_map_clear(&tree, &(CCC_Destructor){}, &(CCC_Allocator){});
  free(items);
}

/********************************************************************************************/

struct pair_ulong {
  unsigned long key;
  unsigned long value;
};

static uint64_t
hash_ulong(CCC_Key_arguments const args)
{
  uint64_t x = *(unsigned long const *)args.key;
  x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
  x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
  x = x ^ (x >> 31);
  return x;
}

static CCC_Order
cmp_ulong_hmap(CCC_Key_comparator_arguments const args)
{
  unsigned long const left = *(unsigned long const *)args.key_left;
  struct pair_ulong const *const right = args.type_right;
  return (left < right->key) ? CCC_ORDER_LESSER
       : (left > right->key) ? CCC_ORDER_GREATER
                             : CCC_ORDER_EQUAL;
}

static inline void
insert_ulong_or_die(
    CCC_Flat_hash_map *map,
    CCC_Allocator const *alloc,
    unsigned long key,
    unsigned long value
)
{
  CCC_Entry const res = CCC_flat_hash_map_insert_or_assign(
      map, &(struct pair_ulong){.key = key, .value = value}, alloc);
  if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL)
    abort();
}

static void
test_dict(size_t n)
{
  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_hash_map dict = CCC_flat_hash_map_default(
      struct pair_ulong,
      key,
      ((CCC_Hasher){.hash = hash_ulong, .compare = cmp_ulong_hmap}));

  for (size_t i = 0; i < n; i++) {
    insert_ulong_or_die(&dict, &alloc, rand_get(), rand_get());
  }

  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    unsigned long const key = rand_get();
    struct pair_ulong const *const p = CCC_flat_hash_map_get_key_value(&dict, &key);
    if (p)
      s += p->value;
  }
  g_result = s;

  (void)CCC_flat_hash_map_clear_and_free(&dict, &(CCC_Destructor){}, &alloc);
}

/********************************************************************************************/

#ifndef CHAR_ARRAY_SIZE
#define CHAR_ARRAY_SIZE 256
#endif

typedef struct {
  char s[CHAR_ARRAY_SIZE];
} ccc_char_array_t;

struct pair_char {
  ccc_char_array_t key;
  ccc_char_array_t value;
};

static uint64_t
hash_char_array(CCC_Key_arguments const args)
{
  ccc_char_array_t const *const k = args.key;
  uint64_t hash = UINT64_C(1469598103934665603);
  for (unsigned char const *p = (unsigned char const *)k->s; *p != '\0'; ++p) {
    hash ^= (uint64_t)*p;
    hash *= UINT64_C(1099511628211);
  }
  return hash;
}

static CCC_Order
cmp_char_array(CCC_Key_comparator_arguments const args)
{
  ccc_char_array_t const *const left = args.key_left;
  struct pair_char const *const right = args.type_right;
  int const cmp = strcmp(left->s, right->key.s);
  return (cmp < 0) ? CCC_ORDER_LESSER
       : (cmp > 0) ? CCC_ORDER_GREATER
                   : CCC_ORDER_EQUAL;
}

static inline void
insert_char_or_die(
    CCC_Flat_hash_map *map,
    CCC_Allocator const *alloc,
    ccc_char_array_t const *key,
    ccc_char_array_t const *value
)
{
  CCC_Entry const res = CCC_flat_hash_map_insert_or_assign(
      map, &(struct pair_char){.key = *key, .value = *value}, alloc);
  if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL)
    abort();
}

static void
test_dict_big(size_t n)
{
  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_hash_map dict = CCC_flat_hash_map_default(
      struct pair_char,
      key,
      ((CCC_Hasher){.hash = hash_char_array, .compare = cmp_char_array}));

  for (size_t i = 0; i < n; i++) {
    ccc_char_array_t s1, s2;
    snprintf(s1.s, sizeof(s1.s), "%u", rand_get());
    snprintf(s2.s, sizeof(s2.s), "%u", rand_get());
    insert_char_or_die(&dict, &alloc, &s1, &s2);
  }

  rand_init();
  unsigned int s = 0;
  for (size_t i = 0; i < n; i++) {
    ccc_char_array_t s1;
    snprintf(s1.s, sizeof(s1.s), "%u", rand_get());
    struct pair_char const *const p = CCC_flat_hash_map_get_key_value(&dict, &s1);
    if (p)
      s++;
  }
  g_result = s;

  (void)CCC_flat_hash_map_clear_and_free(&dict, &(CCC_Destructor){}, &alloc);
}

/********************************************************************************************/

struct set_int {
  int key;
};

static uint64_t
hash_int(CCC_Key_arguments const args)
{
  uint64_t x = (uint64_t)(uint32_t)(*(int const *)args.key);
  x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
  x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
  x = x ^ (x >> 31);
  return x;
}

static CCC_Order
cmp_int_set(CCC_Key_comparator_arguments const args)
{
  int const left = *(int const *)args.key_left;
  struct set_int const *const right = args.type_right;
  return (left < right->key) ? CCC_ORDER_LESSER
       : (left > right->key) ? CCC_ORDER_GREATER
                             : CCC_ORDER_EQUAL;
}

void
bench_find_longest(size_t n)
{
  int *arr = malloc(n * sizeof(*arr));
  if (!arr)
    abort();

  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_hash_map set = CCC_flat_hash_map_default(
      struct set_int, key, ((CCC_Hasher){.hash = hash_int, .compare = cmp_int_set}));

  for (size_t i = 0; i < n; i++) {
    arr[i] = (int)rand_get();
    CCC_Entry const res = CCC_flat_hash_map_insert_or_assign(
        &set, &(struct set_int){.key = arr[i]}, &alloc);
    if (CCC_entry_insert_error(&res) == CCC_TRUE || CCC_entry_unwrap(&res) == NULL)
      abort();
  }

  int ans = 0;
  for (size_t i = 0; i < n; i++) {
    int const prev = arr[i] - 1;
    if (!CCC_flat_hash_map_get_key_value(&set, &prev)) {
      int j = arr[i] + 1;
      while (CCC_flat_hash_map_get_key_value(&set, &j) != NULL)
        j++;
      int const len = j - arr[i];
      ans = (ans < len) ? len : ans;
    }
  }

  g_result = (unsigned long)ans;
  (void)CCC_flat_hash_map_clear_and_free(&set, &(CCC_Destructor){}, &alloc);
  free(arr);
}

/********************************************************************************************/

static CCC_Order
cmp_float(CCC_Comparator_arguments const args)
{
  float const *a = args.type_left;
  float const *b = args.type_right;
  return (*a < *b) ? CCC_ORDER_LESSER
       : (*a > *b) ? CCC_ORDER_GREATER
                   : CCC_ORDER_EQUAL;
}

static void
test_sort(size_t n)
{
  CCC_Allocator const alloc = {.allocate = my_alloc};
  CCC_Flat_buffer a1 = CCC_flat_buffer_default(float);

  for (size_t i = 0; i < n; i++) {
    float v = (float)rand_get();
    if (!CCC_flat_buffer_push_back(&a1, &v, &alloc))
      abort();
  }

  if (CCC_sort_heapsort(
          &a1,
          &(float){0},
          CCC_ORDER_LESSER,
          &(CCC_Comparator){.compare = cmp_float})
      != CCC_RESULT_OK)
    abort();

  float const *const p = CCC_flat_buffer_begin(&a1);
  g_result = (p != NULL) ? (unsigned long)(*p) : 0;

  (void)CCC_flat_buffer_clear_and_free(&a1, &(CCC_Destructor){}, &alloc);
}

/********************************************************************************************/

const config_func_t table[] = {
  {110,         "Seq(Array)", C_N_SEQ_ARRAY, 0, test_array, 0},
  {200,         "SSet(Tree)", C_N_SSET, 0, test_rbtree, 0},
  {300,    "UMap U64(FHash)", C_N_UMAP_U64, 0, test_dict, 0},
  {320,    "UMap Big(FHash)", C_N_UMAP_BIG, 0, test_dict_big, 0},
  {340, "USet Longest(FHash)", C_N_FIND_SEQ, 0, bench_find_longest, 0},
  {500,              "Sort", C_N_SORT, 0, test_sort, 0},
};

int
main(int argc, const char *argv[])
{
  test("CCC", numberof(table), table, argc, argv);
  exit(0);
}
