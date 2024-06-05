#include <stdio.h>
#include "kvec.h"
#include "ksort.h"

// WORKAROUND: Need to define this function
extern int  drand48(void);

KSORT_INIT_GENERIC(int)


  int main(void)
{
  kvec_t(int) array;
  kv_init(array);
  kv_push(int, array, 17 );
  // LIMITATION: No detection of memory allocation failure / no abort in case of error
  kv_push(int, array, 42 );
  // LIMITATION: No detection of memory allocation failure / no abort in case of error
  kv_push(int, array, 9 );
  // LIMITATION: No detection of memory allocation failure / no abort in case of error
  // WORKAROUND: Hack around the internal array
  ks_introsort_int(kv_size(array), & kv_A(array, 0));
  for(size_t i = 0; i < kv_size(array); i++) {
    printf("%d\n", kv_A(array, i ) );
  }
  kv_destroy(array);
  return 0;
}
