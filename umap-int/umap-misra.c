#include <Misra.h>
#include <stdio.h>

static u64 i32_hash(const void *data, u32 size)
{
    u64 x = (u64)(u32)(*(const int *)data);
    (void)size;
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    return x;
}

static i32 i32_compare(const void *lhs, const void *rhs)
{
    int a = *(const int *)lhs;
    int b = *(const int *)rhs;
    return (a > b) - (a < b);
}

int main(void)
{
    Scope(alloc, DefaultAllocator)
    {
        Map(int, int) map = MapInit(i32_hash, i32_compare);

        MapMustInsertR(&map, 17, 4585);
        MapMustInsertR(&map, 42, 4856);
        MapMustInsertR(&map, -9, 1452);

        int *it = MapTryGetPtr(&map, 42);
        if (it != NULL) {
            printf("Value of 42 is %d\n", *it);
        }

        MapForeachPair(&map, key, value)
        {
            printf("%d -> %d\n", key, value);
        }

        MapDeinit(&map);
    }

    return 0;
}
