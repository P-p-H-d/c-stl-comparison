#include <stdio.h>
#include "cc.h"

static int str_cmp(const void *a, const void *b)
{
  const char *const *ap = a;
  const char *const *bp = b;
  return strcmp(*ap, *bp);
}

int main( void )
{
  vec( const char * ) our_vec;
  init( &our_vec );
  const char **p = push( &our_vec, "World" );
  if (!p) {
    abort();
  }
  p = push( &our_vec, "Hello" );
  if (!p) {
    abort();
  }
  p = push( &our_vec, "!" );
  if (!p) {
    abort();
  }

  // LIMITATION: No Sort function
  qsort( get(&our_vec, 0), size(&our_vec), sizeof (const char *), str_cmp);
  
  for_each(&our_vec, ptr) {
    printf("%s\n", *ptr);
  }
  cleanup( &our_vec );
}
