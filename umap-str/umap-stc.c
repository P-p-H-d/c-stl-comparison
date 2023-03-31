#include <stdio.h>
#include <stc/cstr.h>

#define i_type         umap_str
#define i_key_str
#define i_val_str
#include <stc/cmap.h>

int main(void)
{
  c_auto(umap_str, map) {
    umap_str_result res = umap_str_emplace_or_assign(&map, "Hello", "LIB");
    if (res.inserted != true) {
      abort();
    }
    res = umap_str_emplace_or_assign(&map, "Welcome", "Program");
    if (res.inserted != true) {
      abort();
    }
    res = umap_str_emplace_or_assign(&map, "Sincerey", "Your map");
    if (res.inserted != true) {
      abort();
    }
    const umap_str_value *it = umap_str_get(&map, "Welcome");
    if (it != NULL) {
      printf("Value of 'Welcome' is %s\n", cstr_str(&it->second));
    }
    c_foreach (item, umap_str, map) {
      printf("%s -> %s\n", cstr_str(&item.ref->first), cstr_str(&item.ref->second));
    }
  }
  return 0;
}
