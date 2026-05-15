#include <Misra.h>
#include <stdio.h>

static u64 str_hash(const void *data, u32 size)
{
    const Str *s = (const Str *)data;
    const unsigned char *ptr = (const unsigned char *)StrBegin(s);
    u64 hash = 1469598103934665603ULL;
    u64 i;

    (void)size;

    for (i = 0; i < (u64)StrLen(s); i++) {
        hash ^= (u64)ptr[i];
        hash *= 1099511628211ULL;
    }

    return hash;
}

static i32 str_compare(const void *lhs, const void *rhs)
{
    const Str *a = (const Str *)lhs;
    const Str *b = (const Str *)rhs;
    return StrCmp(a, b);
}

int main(void)
{
    Scope(alloc, DefaultAllocator)
    {
        Map(Str, Str) map = MapInitWithDeepCopy(str_hash, str_compare, str_init_copy, str_deinit, str_init_copy, str_deinit);

        MapMustInsertR(&map, StrZ("Hello"), StrZ("LIB"));
        MapMustInsertR(&map, StrZ("Welcome"), StrZ("Program"));
        MapMustInsertR(&map, StrZ("Sincerely"), StrZ("Your map"));

        Str lookup_key = StrZ("Welcome");
        // WORKAROUND: Macro MapTryGetPtr doesn't work with Str because of a compound literal. We need to call map_get_value_ptr directly.
        Str *it = (Str *)map_get_value_ptr(
            GENERIC_MAP(&map),
            &lookup_key,
            sizeof(MAP_ENTRY_TYPE(&map)),
            offsetof(MAP_ENTRY_TYPE(&map), key),
            sizeof(MAP_KEY_TYPE(&map)),
            offsetof(MAP_ENTRY_TYPE(&map), value),
            offsetof(MAP_ENTRY_TYPE(&map), hash)
        );
        if (it != NULL) {
            printf("Value of 'Welcome' is %s\n", StrBegin(it));
        }
        StrDeinit(&lookup_key);

        MapForeachPair(&map, key, value)
        {
            printf("%s -> %s\n", StrBegin(&key), StrBegin(&value));
        }

        MapDeinit(&map);
    }

    return 0;
}
