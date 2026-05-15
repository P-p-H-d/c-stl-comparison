#include <Misra.h>
#include <stdio.h>

static int str_cmp(const void *a, const void *b)
{
    const Str *ap = a;
    const Str *bp = b;
    return StrCmp(ap, bp);
}

int main(void)
{
    Scope(alloc, DefaultAllocator)
    {
        Vec(Str) vec = VecInitWithDeepCopyT(vec, StrInitCopy, StrDeinit);

        VecMustPushBackR(&vec, StrZ("World"));
        VecMustPushBackR(&vec, StrZ("Hello"));
        VecMustPushBackR(&vec, StrZ("!"));

        VecSort(&vec, str_cmp);

        VecForeach(&vec, value)
        {
            printf("%s\n", StrBegin(&value));
        }

        VecDeinit(&vec);
    }

    return 0;
}
