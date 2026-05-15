#include <Misra.h>
#include <stdio.h>

static int int_cmp(const void *a, const void *b)
{
    const int *ap = a;
    const int *bp = b;
    return (*ap < *bp) ? -1 : (*ap > *bp);
}

int main(void)
{
    Scope(alloc, DefaultAllocator)
    {
        Vec(int) vec = VecInit();

        VecMustPushBackR(&vec, 17);
        VecMustPushBackR(&vec, 42);
        VecMustPushBackR(&vec, 9);

        VecSort(&vec, int_cmp);

        VecForeach(&vec, value)
        {
            printf("%d\n", value);
        }

        VecDeinit(&vec);
    }

    return 0;
}
