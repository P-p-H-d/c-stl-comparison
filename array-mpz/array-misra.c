#include <Misra.h>
#include <gmp.h>

typedef struct {
    mpz_t value;
} MpzBox;

static bool MpzBox_copy(void *dst, const void *src, const Allocator *alloc)
{
    (void)alloc;
    const MpzBox *s = src;
    MpzBox       *d = dst;
    mpz_init_set(d->value, s->value);
    return true;
}

static void MpzBox_deinit(void *copy, const Allocator *alloc)
{
    (void)alloc;
    MpzBox *v = copy;
    mpz_clear(v->value);
}

static int MpzBox_cmp(const void *a, const void *b)
{
    const MpzBox *lhs = a;
    const MpzBox *rhs = b;
    return mpz_cmp(lhs->value, rhs->value);
}

int main(void)
{
    Scope(alloc, DefaultAllocator)
    {
        Vec(MpzBox) vec = VecInitWithDeepCopyT(vec, MpzBox_copy, MpzBox_deinit);

        MpzBox a;
        MpzBox b;
        MpzBox c;
        mpz_init_set_ui(a.value, 17);
        mpz_init_set_ui(b.value, 42);
        mpz_init_set_ui(c.value, 9);

        VecMustPushBackL(&vec, a);
        VecMustPushBackL(&vec, b);
        VecMustPushBackL(&vec, c);
        mpz_clear(a.value);
        mpz_clear(b.value);
        mpz_clear(c.value);

        VecSort(&vec, MpzBox_cmp);

        VecForeachPtr(&vec, value)
        {
            gmp_printf("%Zd\n", value->value);
        }

        VecDeinit(&vec);
    }

    return 0;
}