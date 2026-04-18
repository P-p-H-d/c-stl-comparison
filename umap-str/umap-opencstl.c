#include <stdio.h>
#include <stdlib.h>

#include "opencstl.h"

int main(void)
{
  char hello[] = "Hello";
  char welcome[] = "Welcome";
  char sincerely[] = "Sincerely";
  char lib[] = "LIB";
  char program[] = "Program";
  char your_map[] = "Your map";

  UNORDERED_MAP(char *) map = new_unordered_map(char *, char *);
  if (!map) {
    abort();
  }

  insert(map, hello, lib);
  insert(map, welcome, program);
  insert(map, sincerely, your_map);

  char **it = find(map, welcome);
  if (it != NULL) {
    printf("Value of 'Welcome' is %s\n", second(it, char *));
  }

  for (char **entry = begin(map); entry != end(map); entry = next(entry)) {
    printf("%s -> %s\n", first(entry), second(entry, char *));
  }

  destroy(map);
  return 0;
}