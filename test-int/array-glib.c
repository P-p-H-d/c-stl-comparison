#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

static gint
int_cmp(gconstpointer a, gconstpointer b)
{
  const int *pa = a;
  const int *pb = b; 
  return *pa < *pb ? -1 : *pa > *pb;
}

int main(void)
{
  GArray *a = g_array_new(FALSE, FALSE, sizeof(int));
  if (!a) {
    abort();
  }
  const int i1 = 17, i2 = 42, i3 = 9;
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
  g_array_sort(a, int_cmp);
  for(int i = 0 ; i < a->len; i++) {
    printf("%d\n", g_array_index(a, const int, i));
  }
  g_array_free(a, TRUE);
  return 0;
}
