#include <stdio.h>
#include "cc.h"

static int str_cmp(const void *a, const void *b)
{
  str(char) const *ap = a;
  str(char) const *bp = b;
  return strcmp(first(ap), first(bp));
}

int main( void )
{
  vec( str( char ) ) our_vec;
  init( &our_vec );
  void *p = push( &our_vec, "World" );
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
  qsort( get(&our_vec, 0), size(&our_vec), sizeof (const char *), str_cmp);   // LIMITATION: No Sort function
  for_each(&our_vec, ptr) {
    printf("%s\n", first(ptr));
  }
  cleanup( &our_vec );
  return 0;
}
