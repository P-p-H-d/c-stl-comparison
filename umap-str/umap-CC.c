#include <stdio.h>
#include "cc.h"

int main( void )
{
  map(char *, char *) map;
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
  char* *it = get(&map, "Welcome");
  if (it != NULL) {
    printf("Value of Welcome is %s\n", *it);
  }
  for_each(&map, key, value) {
    printf("%s -> %s\n", *key, *value);
  }
  cleanup( &map );
  return 0;
}
