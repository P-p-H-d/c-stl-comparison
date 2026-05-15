#include <Misra.h>
#include <gmp.h>

typedef struct {
    mpz_t value;
} MpzBox;

static void MpzBox_init_si(MpzBox *box, long int value)
{
    mpz_init_set_si(box->value, value);
}

static u64 mpz_fast_hash(const mpz_t z)
{
    mp_size_t n = z->_mp_size;
    mp_limb_t *p = z->_mp_d;
    u64 hash = 0;

    if (n <= 0) {
        hash ^= (u64)0x7F5C1458U;
        if (n == 0) {
            return hash;
        }
        n = -n;
    }

    while (n-- > 0) {
        hash ^= (u64)*p++;
    }

    return hash;
}

static u64 MpzBox_hash(const void *data, u32 size)
{
    const MpzBox *box = (const MpzBox *)data;
    (void)size;
    return mpz_fast_hash(box->value);
}

static i32 MpzBox_compare(const void *lhs, const void *rhs)
{
    const MpzBox *a = (const MpzBox *)lhs;
    const MpzBox *b = (const MpzBox *)rhs;
    return mpz_cmp(a->value, b->value);
}

static bool MpzBox_copy(void *dst, const void *src, const Allocator *alloc)
{
    const MpzBox *s = (const MpzBox *)src;
    MpzBox *d = (MpzBox *)dst;
    (void)alloc;
    mpz_init_set(d->value, s->value);
    return true;
}

static void MpzBox_deinit(void *copy, const Allocator *alloc)
{
    MpzBox *box = (MpzBox *)copy;
    (void)alloc;
    mpz_clear(box->value);
}

int main(void)
{
    Scope(alloc, DefaultAllocator)
    {
        Map(MpzBox, MpzBox) map = MapInitWithDeepCopy(
            MpzBox_hash,
            MpzBox_compare,
            MpzBox_copy,
            MpzBox_deinit,
            MpzBox_copy,
            MpzBox_deinit
        );

        MpzBox key1, key2, key3;
        MpzBox value1, value2, value3;
        MpzBox lookup_key;

        MpzBox_init_si(&key1, 17);
        MpzBox_init_si(&value1, 4585);
        MpzBox_init_si(&key2, 42);
        MpzBox_init_si(&value2, 4856);
        MpzBox_init_si(&key3, -9);
        MpzBox_init_si(&value3, 1452);

        MapMustInsertL(&map, key1, value1);
        MapMustInsertL(&map, key2, value2);
        MapMustInsertL(&map, key3, value3);

        mpz_clear(key1.value);
        mpz_clear(value1.value);
        mpz_clear(key2.value);
        mpz_clear(value2.value);
        mpz_clear(key3.value);
        mpz_clear(value3.value);

        MpzBox_init_si(&lookup_key, 42);
        // WORKAROUND: Macro MapTryGetPtr doesn't work with Str because of a compound literal. We need to call map_get_value_ptr directly.
        MpzBox *it = (MpzBox *)map_get_value_ptr(
            GENERIC_MAP(&map),
            &lookup_key,
            sizeof(MAP_ENTRY_TYPE(&map)),
            offsetof(MAP_ENTRY_TYPE(&map), key),
            sizeof(MAP_KEY_TYPE(&map)),
            offsetof(MAP_ENTRY_TYPE(&map), value),
            offsetof(MAP_ENTRY_TYPE(&map), hash)
        );
        if (it != NULL) {
            gmp_printf("Value of 42 is %Zd\n", it->value);
        }
        mpz_clear(lookup_key.value);

        MapForeachPair(&map, key, value)
        {
            gmp_printf("%Zd -> %Zd\n", key.value, value.value);
        }

        MapDeinit(&map);
    }

    return 0;
}
