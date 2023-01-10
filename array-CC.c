#include <stdio.h>
#include "gmp.h"

#include "cc.h"

// WORKAROUND: Needs to encapsulate mpz_t within a struct
// LIMITATION: No copy / init_set function possible.
typedef struct { mpz_t Z; } mpz_z;
#define CC_DTOR mpz_z, { mpz_clear(val.Z); }
#define CC_CMPR mpz_z, { return mpz_cmp( val_1.Z, val_2.Z); }
#include "cc.h"

static int mpz_z_cmp(const void *a, const void *b)
{
  const mpz_z *ap = a;
  const mpz_z *bp = b;
  return mpz_cmp(ap->Z, bp->Z);
}

int main( void )
{
  vec( mpz_z ) our_vec;
  init( &our_vec );
  mpz_z z;                                         //WORKAROUND: we shall not clear the z object, as its ownership has been lost.
  mpz_init_set_ui(z.Z, 17);
  mpz_z *p = push( &our_vec, z );
  if (!p) {
    abort();
  }
  mpz_init_set_ui(z.Z, 42);
  p = push( &our_vec, z );
  if (!p) {
    abort();
  }
  mpz_init_set_ui(z.Z, 9);
  p = push( &our_vec, z );
  if (!p) {
    abort();
  }

  // LIMITATION: No Sort function
  qsort( get(&our_vec, 0), size(&our_vec), sizeof (mpz_z), mpz_z_cmp);
  
  for_each(&our_vec, ptr) {
    gmp_printf("%Zd\n", ptr->Z);
  }
  cleanup( &our_vec );
}
