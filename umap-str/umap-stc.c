#include <stdio.h>
#include <string.h>

#define i_implement
#include <stc/cstr.h>
#include <stc/algorithm.h>

#define T umap_str, cstr, cstr, (c_pro_key | c_pro_val)
#define i_keyfrom cstr_from
#define i_keytoraw cstr_str
#define i_eq(x, y) (strcmp(*x, *y) == 0)
#include <stc/hashmap.h>

int main(void)
{
  umap_str map = { 0 };

  umap_str_result res = umap_str_emplace_or_assign(&map, "Hello", "LIB");
  if (res.inserted != true) {
    abort();
  }
  res = umap_str_emplace_or_assign(&map, "Welcome", "Program");
  if (res.inserted != true) {
    abort();
  }
  res = umap_str_emplace_or_assign(&map, "Sincerely", "Your map");
  if (res.inserted != true) {
    abort();
  }
  const umap_str_value *it = umap_str_get(&map, "Welcome");
  if (it != NULL) {
    printf("Value of 'Welcome' is %s\n", cstr_str(&it->second));
  }
  for (c_each(item, umap_str, map)) {
    printf("%s -> %s\n", cstr_str(&item.ref->first), cstr_str(&item.ref->second));
  }

  umap_str_drop(&map);
  
  return 0;
}
