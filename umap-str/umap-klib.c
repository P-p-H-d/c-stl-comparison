#include <stdio.h>
#include <khash.h>

KHASH_INIT(iun, const char*, const char*, 1, kh_str_hash_func, kh_str_hash_equal)

int main(void)
{
  khash_t(iun) *map = kh_init(iun);
  int ret;

  khiter_t k = kh_put(iun, map, "Hello", &ret);
  if (ret < 0) {
    abort();
  }
  kh_value(map, k) = "LIB";

  k = kh_put(iun, map, "Welcome", &ret);
  if (ret < 0) {
    abort();
  }
  kh_value(map, k) = "Program";

  k = kh_put(iun, map, "Sincerely", &ret);
  if (ret < 0) {
    abort();
  }
  kh_value(map, k) = "Your map";

  k = kh_get(iun, map, "Welcome");
  if (kh_exist(map, k)) {
    printf("Value of 'Welcome' is %s\n", kh_value(map, k));
  }

  for (k = kh_begin(map); k != kh_end(map); k++) {
    if (kh_exist(map, k)) {
      printf("%s -> %s\n", kh_key(map, k), kh_value(map, k) );
    }
  }

  kh_destroy(iun, map);
  
  return 0;
}
