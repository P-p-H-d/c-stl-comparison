#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

static gint
str_cmp(gconstpointer a, gconstpointer b)
{
  const GString *const *pa = a;
  const GString *const *pb = b;
  return strcmp((*pa)->str, (*pb)->str);
}

int main(void)
{
  GArray *a = g_array_new(FALSE, FALSE, sizeof(GString *));
  if (!a) {
    abort();
  }
  GString *i1 = g_string_new("Hello");
  GString *i2 = g_string_new("World");
  GString *i3 = g_string_new("!");
  a = g_array_append_vals(a, &i1, 1);
  if (!a) {
    abort();
  }
  a = g_array_append_vals(a, &i2, 1);
  if (!a) {
    abort();
  }
  a = g_array_append_vals(a, &i3, 1);
  if (!a) {
    abort();
  }
  g_array_sort(a, str_cmp);
  for(int i = 0 ; i < a->len; i++) {
    printf("%s\n", g_array_index(a, GString *, i)->str);
  }
  g_array_free(a, TRUE);
  g_string_free(i1, TRUE);
  g_string_free(i2, TRUE);
  g_string_free(i3, TRUE);
  return 0;
}
