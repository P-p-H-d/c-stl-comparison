#include <stdio.h>
#include <gmp.h>
#include "kvec.h"
#include "ksort.h"
#include "kstring.h"

// WORKAROUND: Need to define this function
extern int  drand48(void);

// WORKAROUND: Encapsulate mpz_t in a struct
typedef struct mpz { mpz_t z; } mpz;

#define mpz_lt(a, b) (mpz_cmp((a).z, (b).z) < 0)
KSORT_INIT(mpz, mpz, mpz_lt)

int main(void)
{
  kvec_t(mpz) array;

  kv_init(array);
  {
    mpz tmp;
    mpz_init_set_ui(tmp.z, 17);
    kv_push(mpz, array, tmp);
    // LIMITATION: No detection of memory allocation failure / no abort in case of error
    // LIMITATION: content of tmp has been stolen by array, no free of tmp
  }
  
  {
    mpz tmp;
    mpz_init_set_ui(tmp.z, 42);
    kv_push(mpz, array, tmp );
    // LIMITATION: No detection of memory allocation failure / no abort in case of error
    // LIMITATION: content of tmp has been stolen by array, no free of tmp
  }
    
  {
    mpz tmp;
    mpz_init_set_ui(tmp.z, 9);
    kv_push(mpz, array, tmp );
    // LIMITATION: No detection of memory allocation failure / no abort in case of error
    // LIMITATION: content of tmp has been stolen by array, no free of tmp
  }
    
  // WORKAROUND: Hack around the internal array
  ks_introsort_mpz(kv_size(array), & kv_A(array, 0));

  for(size_t i = 0; i < kv_size(array); i++) {
    gmp_printf("%Zd\n", kv_A(array, i).z );
  }

  for(size_t i = 0; i < kv_size(array); i++) {
    mpz_clear( kv_A(array, i).z);
  }
  kv_destroy(array);
  return 0;
}
