#include <stdio.h>

#include "cc.h"

static inline int int_cmp(const void *a, const void *b)
{
  const int *pa = a;
  const int *pb = b;
  return (*pa < *pb) ? -1 : *pa > *pb;
}

int main( void )
{
  vec( int ) our_vec;
  init( &our_vec );

  int *p = push( &our_vec, 17 );
  if (!p) {
    abort();
  }
  p = push( &our_vec, 42 );
  if (!p) {
    abort();
  }
  p = push( &our_vec, 9 );
  if (!p) {
    abort();
  }

  // LIMITATION: No Sort function
  qsort( get(&our_vec, 0), size(&our_vec), sizeof (int), int_cmp);
  
  for_each(&our_vec, ptr) {
    printf("%d\n", *ptr);
  }
  cleanup( &our_vec );
}
