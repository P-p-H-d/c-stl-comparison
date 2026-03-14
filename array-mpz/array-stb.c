#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// WORKAROUND: stb doesn't check for allocation failure.
static void *xrealloc(void *ptr, size_t size)
{
  void * p = realloc(ptr, size);
  if (!p) {
    abort();
  }
  return p;
}
static void xfree(void *ptr)
{
  free(ptr);
}
#define STBDS_REALLOC(context, ptr, size) xrealloc(ptr, size)
#define STBDS_FREE(context, ptr) xfree(ptr)
#define STB_DS_IMPLEMENTATION
#include <stb_ds.h>

// WORKAROUND: Needs to encapsulate mpz_t within a C struct
typedef struct {
  mpz_t Z;
} mpz_z;

static inline int my_mpz_cmp(const void *a, const void *b)
{
  const mpz_z *pa = a;
  const mpz_z *pb = b;
  return mpz_cmp(pa->Z, pb->Z);
}

int main(void)
{
  mpz_z *vec = NULL;
  
  // WORKAROUND: content of z has been stolen by array, no free of z (move semantics)
  mpz_z z;
  mpz_init_set_ui(z.Z, 17);
  arrput(vec, z);
  mpz_init_set_ui(z.Z, 42);
  arrput(vec, z);
  mpz_init_set_ui(z.Z, 9);
  arrput(vec, z);

  qsort(vec, arrlen(vec), sizeof(mpz_z), my_mpz_cmp);

  for (int i = 0; i < arrlen(vec); i++) {
    gmp_printf("%Zd\n", vec[i].Z);
  }

  // WORKAROUND: No destructor registered. Call it by hand
  for (int i = 0; i < arrlen(vec); i++) {
    mpz_clear(vec[i].Z);
  }
  arrfree(vec);

  return 0;
}
