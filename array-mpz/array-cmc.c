#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// Encapsulate mpz_t within a struct
typedef struct {
  mpz_t Z;
} mpz_z;

// Define comparison and copy functions
static int mpz_z_cmp(mpz_z a, mpz_z b)
{
  return mpz_cmp(a.Z, b.Z);
}

static mpz_z mpz_z_cpy(mpz_z a)
{
  mpz_z result;
  mpz_init_set(result.Z, a.Z);
  return result;
}

static void mpz_z_free(mpz_z a)
{
  mpz_clear(a.Z);
}

#define V mpz_z
#define PFX mpzl
#define SNAME mpz_list
#define CMC_EXT_ITER
#include "cmc/list.h"

int main(void)
{
  struct mpz_list *list = mpzl_new(32, &(struct mpz_list_fval){ 
    .cmp = mpz_z_cmp,
    .cpy = mpz_z_cpy,
    .free = mpz_z_free,
    NULL 
  });
  if (!list) {
    return 1;
  }
  
  mpz_z z;
  mpz_init_set_ui(z.Z, 17);
  if (!mpzl_push_back(list, z)) {
    abort();
  }
  
  mpz_init_set_ui(z.Z, 42);
  if (!mpzl_push_back(list, z)) {
    abort();
  }
  
  mpz_init_set_ui(z.Z, 9);
  if (!mpzl_push_back(list, z)) {
    abort();
  }

  // Use qsort for sorting (convert function pointer)
  if (mpzl_count(list) > 0) {
    qsort(list->buffer, mpzl_count(list), sizeof(mpz_z), 
          (int (*)(const void *, const void *))
          ((int (*)(const void *, const void *))mpz_z_cmp));
  }

  struct mpz_list_iter iter = mpzl_iter_start(list);
  for (; !mpzl_iter_at_end(&iter); mpzl_iter_next(&iter)) {
    mpz_z val = mpzl_iter_value(&iter);
    gmp_printf("%Zd\n", val.Z);
  }
  
  mpzl_free(list);
  return 0;
}
