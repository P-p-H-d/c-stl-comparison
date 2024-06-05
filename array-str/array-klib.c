#include <stdio.h>
#include "kvec.h"
#include "ksort.h"
#include "kstring.h"

// WORKAROUND: Need to define this function
extern int  drand48(void);

#define string_lt(a, b) (strcmp(ks_str(&a), ks_str(&b)) < 0)

KSORT_INIT(string, kstring_t, string_lt)

int main(void)
{
  kvec_t(kstring_t) array;

  kv_init(array);
  {
    kstring_t tmp = { 0 };
    kputs("Hello", &tmp);
    kv_push(kstring_t, array, tmp);
    // LIMITATION: No detection of memory allocation failure / no abort in case of error
    // LIMITATION: content of tmp has been stolen by array, no free of tmp
  }
  
  {
    kstring_t tmp = { 0 };
    kputs("World", &tmp);
    kv_push(kstring_t, array, tmp );
    // LIMITATION: No detection of memory allocation failure / no abort in case of error
    // LIMITATION: content of tmp has been stolen by array, no free of tmp
  }
    
  {
    kstring_t tmp = { 0 };
    kputs("!", &tmp);
    kv_push(kstring_t, array, tmp );
    // LIMITATION: No detection of memory allocation failure / no abort in case of error
    // LIMITATION: content of tmp has been stolen by array, no free of tmp
  }
    
  // WORKAROUND: Hack around the internal array
  ks_introsort_string(kv_size(array), & kv_A(array, 0));

  for(size_t i = 0; i < kv_size(array); i++) {
    printf("%s\n", ks_str(&kv_A(array, i )) );
  }

  for(size_t i = 0; i < kv_size(array); i++) {
    free( ks_str(&kv_A(array, i)));
  }
  kv_destroy(array);
  return 0;
}
