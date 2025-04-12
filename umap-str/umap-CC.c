#include <stdio.h>
#include "cc.h"

int main( void )
{
  map(str(char), str(char)) map;
  init( &map );
  if (!insert(&map, "Hello", "LIB")) {
    abort();
  }
  if (!insert(&map, "Welcome", "Program")) {
    abort();
  }
  if (!insert(&map, "Sincerely", "Your map")) {
    abort();
  }
  str(char) *it = get(&map, "Welcome");
  if (it != NULL) {
    printf("Value of Welcome is %s\n", first(it));
  }
  for_each(&map, key, value) {
    printf("%s -> %s\n", first(key), first(value));
  }
  cleanup( &map );
  return 0;
}
