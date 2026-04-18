#include <stdio.h>
#include <stdlib.h>

#include "opencstl.h"

int main(void)
{
  UNORDERED_MAP(int) map = new_unordered_map(int, int);
  if (!map) {
    abort();
  }

  insert(map, 17, 4585);
  insert(map, 42, 4856);
  insert(map, -9, 1452);

  int *it = find(map, 42);
  if (it != NULL) {
    printf("Value of 42 is %d\n", second(it, int));
  }

  for (int *entry = begin(map); entry != end(map); entry = next(entry)) {
    printf("%d -> %d\n", first(entry), second(entry, int));
  }

  destroy(map);
  return 0;
}