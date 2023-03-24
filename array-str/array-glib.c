#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

static gint
str_cmp(gconstpointer a, gconstpointer b)
{
  const char *const*pa = a;
  const char *const*pb = b; 
  return strcmp(*pa, *pb);
}

int main(void)
{
  GArray *a = g_array_new(FALSE, FALSE, sizeof(char *));
  if (!a) {
    abort();
  }
  char * i1 = "Hello", *i2 = "World", *i3 = "!";
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
    printf("%s\n", g_array_index(a, char *, i));
  }
  g_array_free(a, TRUE);
  return 0;
}
