#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

static guint hash_func (gconstpointer key)
{
  const int *pa = key;
  return *pa;
}

static gboolean equal_func(gconstpointer key1, gconstpointer key2)
{
  const int *pa = key1;
  const int *pb = key2;
  return *pa == *pb;
}

static void print_them (gpointer key, gpointer value, gpointer user_data)
{
  (void) user_data;
  printf("%d -> %d\n", *(int*)key, *(int*)value);
}

int main(void)
{
  GHashTable *map;
  map = g_hash_table_new_full(hash_func, equal_func, NULL, NULL);
  int key1 = 17, value1 = 4585;
  g_hash_table_insert(map, &key1, &value1);
  int key2 = 42, value2 = 4856;
  g_hash_table_insert(map, &key2, &value2);
  int key3 = -9, value3 = 1452;
  g_hash_table_insert(map, &key3, &value3);
  int key4 = 42;
  void *r = g_hash_table_lookup(map, &key4);
  if (r != NULL) {
    printf("Value of 42 is %d\n", *(int *)r);
  }
  g_hash_table_foreach(map, print_them, NULL);
  g_hash_table_destroy(map);
  return 0;
}
