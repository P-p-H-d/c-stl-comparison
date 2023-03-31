#include <stdio.h>

#define i_type         umap_int
#define i_key          int
#define i_val          int
#include <stc/cmap.h>

int main(void)
{
  c_auto(umap_int, map) {
    umap_int_result res = umap_int_insert_or_assign(&map, 17, 4585);
    if (res.inserted != true) {
      abort();
    }
    res = umap_int_insert_or_assign(&map, 42, 4856);
    if (res.inserted != true) {
      abort();
    }
    res = umap_int_insert_or_assign(&map, -9, 1452);
    if (res.inserted != true) {
      abort();
    }
    const umap_int_value *it = umap_int_get(&map, 42);
    if (it != NULL) {
      printf("Value of 42 is %d\n", it->second);
    }
    c_foreach (item, umap_int, map) {
      printf("%d -> %d\n", item.ref->first, item.ref->second);
    }
  }
  return 0;
}
