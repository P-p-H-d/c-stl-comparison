#include <stdio.h>
#include <string.h>
#include <glib.h>

static guint hash_func (gconstpointer key)
{
  const GString *const * pa = key;
  guint r = 0;
  char *ptr = (*pa)->str;
  while (*ptr) {
    r = r * 33 + *ptr;
    ptr++;
  }
  return r;
}

static gboolean equal_func(gconstpointer key1, gconstpointer key2)
{
  const GString *const *pa = key1;
  const GString *const *pb = key2;
  return strcmp((*pa)->str, (*pb)->str) == 0;
}

static void print_them (gpointer key, gpointer value, gpointer user_data)
{
  (void) user_data;
  printf("%s -> %s\n", (*(GString**)key)->str, (*(GString**)value)->str);
}

int main(void)
{
  GHashTable *map;
  GString *k1 = g_string_new("Hello");
  GString *v1 = g_string_new("LIB");
  GString *k2 = g_string_new("Welcome");
  GString *v2 = g_string_new("Program");
  GString *k3 = g_string_new("Sincerely");
  GString *v3 = g_string_new("Your map");
  map = g_hash_table_new_full(hash_func, equal_func, NULL, NULL);
  g_hash_table_insert(map, &k1, &v1);
  g_hash_table_insert(map, &k2, &v2);
  g_hash_table_insert(map, &k3, &v3);
  GString *k4 = g_string_new("Hello");
  void *r = g_hash_table_lookup(map, &k4);
  if (r != NULL) {
    printf("Value of Hello is %s\n", (*(GString **)r)->str);
  }
  g_hash_table_foreach(map, print_them, NULL);
  g_hash_table_destroy(map);
  g_string_free(k1, TRUE);
  g_string_free(v1, TRUE);
  g_string_free(k2, TRUE);
  g_string_free(v2, TRUE);
  g_string_free(k3, TRUE);
  g_string_free(v3, TRUE);
  g_string_free(k4, TRUE);
  return 0;
}
