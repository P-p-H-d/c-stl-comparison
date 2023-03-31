#include <stdio.h>
#include <gmp.h>
#include "cc.h"

static inline size_t mpz_fast_hash(mpz_t z)
{
  mp_size_t  n = z->_mp_size;
  mp_limb_t *p = z->_mp_d;
  size_t hash = 0;
  if (n <= 0) {
    hash ^= 0x7F5C1458;
    if (n == 0) {
      return hash;
    }
    n = -n;
  }
  while (n-- > 0) {
    hash ^= *p++;
  }
  return hash;
}

// WORKAROUND: Needs to encapsulate mpz_t within a struct
// LIMITATION: No copy / init_set function possible.
typedef struct { mpz_t Z; } mpz_z;
#define CC_DTOR mpz_z, { mpz_clear(val.Z); }
#define CC_CMPR mpz_z, { return mpz_cmp( val_1.Z, val_2.Z); }
#define CC_HASH mpz_z, { return mpz_fast_hash(val.Z); }
#include "cc.h"

int main( void )
{
  map( mpz_z, mpz_z ) map;
  init( &map );
  mpz_z z1, z2;                                     //WORKAROUND: we shall not clear the z object, as its ownership has been lost.
  mpz_init_set_si(z1.Z, 17);
  mpz_init_set_si(z2.Z, 4585);
  if (!insert(&map, z1, z2)) {
    abort();
  }
  mpz_init_set_si(z1.Z, 42);
  mpz_init_set_si(z2.Z, 4856);
  if (!insert(&map, z1, z2)) {
    abort();
  }
  mpz_init_set_si(z1.Z, -9);
  mpz_init_set_si(z2.Z, 1452);
  if (!insert(&map, z1, z2)) {
    abort();
  }
  mpz_init_set_ui(z1.Z, 42);
  mpz_z *it = get(&map, z1);
  if (it != NULL) {
    gmp_printf("Value of 42 is %Zd\n", it->Z);
  }
  for_each(&map, key, value) {
    gmp_printf("%Zd -> %Zd\n", key->Z, value->Z);
  }
  cleanup( &map );
  mpz_clear(z1.Z);
  return 0;
}
