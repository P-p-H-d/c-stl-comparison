#include <stdio.h>
#include <khash.h>

KHASH_INIT(iun, int, int, 1, kh_int_hash_func, kh_int_hash_equal)

int main(void)
{
  khash_t(iun) *map = kh_init(iun);
  int ret;

  khiter_t k = kh_put(iun, map, 17, &ret);
  if (ret < 0) {
    abort();
  }
  kh_value(map, k) = 4585;

  k = kh_put(iun, map, 42, &ret);
  if (ret < 0) {
    abort();
  }
  kh_value(map, k) = 4856;

  k = kh_put(iun, map, -9, &ret);
  if (ret < 0) {
    abort();
  }
  kh_value(map, k) = 1452;

  k = kh_get(iun, map, 42);
  if (kh_exist(map, k)) {
    printf("Value of 42 is %d\n", kh_value(map, k));
  }

  for (k = kh_begin(map); k != kh_end(map); k++) {
    if (kh_exist(map, k)) {
      printf("%d -> %d\n", kh_key(map, k), kh_value(map, k) );
    }
  }

  kh_destroy(iun, map);
  
  return 0;
}
