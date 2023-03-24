#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gmp.h>

static gint
int_cmp(gconstpointer a, gconstpointer b)
{
  const mpz_t *pa = a;
  const mpz_t *pb = b; 
  return mpz_cmp(*pa, *pb);
}

int main(void)
{
  GArray *a = g_array_new(FALSE, FALSE, sizeof(mpz_t));
  if (!a) {
    abort();
  }
  mpz_t i1;
  mpz_init_set_ui(i1, 17);
  a = g_array_append_vals(a, &i1, 1);
  if (!a) {
    abort();
  }
  mpz_t i2;
  mpz_init_set_ui(i2, 42);
  a = g_array_append_vals(a, &i2, 1);
  if (!a) {
    abort();
  }
  mpz_t i3;
  mpz_init_set_ui(i3, 9);
  a = g_array_append_vals(a, &i3, 1);
  if (!a) {
    abort();
  }
  g_array_sort(a, int_cmp);
  for(int i = 0 ; i < a->len; i++) {
    gmp_printf("%Zd\n", g_array_index(a, mpz_t, i));
  }
  mpz_clear(i1);
  mpz_clear(i2);
  mpz_clear(i3);
  g_array_free(a, TRUE);
  return 0;
}
