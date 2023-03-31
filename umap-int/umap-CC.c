#include <stdio.h>
#include "cc.h"

int main( void )
{
  map( int, int ) map;
  init( &map );
  if (!insert(&map, 17, 4585)) {
    abort();
  }
  if (!insert(&map, 42,4856)) {
    abort();
  }
  if (!insert(&map, -9, 1452)) {
    abort();
  }
  int *it = get(&map, 42);
  if (it != NULL) {
    printf("Value of 42 is %d\n", *it);
  }
  for_each(&map, key, value) {
    printf("%d -> %d\n", *key, *value);
  }
  cleanup( &map );
  return 0;
}
