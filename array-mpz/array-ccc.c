#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#include "ccc/flat_buffer.h"
#include "ccc/sort.h"

static void *
my_alloc(CCC_Allocator_arguments const args)
{
    if (!args.input && !args.bytes)
        return NULL;
    if (!args.input)
        return malloc(args.bytes);
    if (!args.bytes) {
        free(args.input);
        return NULL;
    }
    return realloc(args.input, args.bytes);
}

static CCC_Order
mpz_cmp_wrapper(CCC_Comparator_arguments const args)
{
    mpz_t const *a = args.type_left;
    mpz_t const *b = args.type_right;
    return (mpz_cmp(*a, *b) < 0) ? CCC_ORDER_LESSER
         : (mpz_cmp(*a, *b) > 0) ? CCC_ORDER_GREATER
                     : CCC_ORDER_EQUAL;
}

int main(void)
{
    CCC_Allocator const alloc = {.allocate = my_alloc};
    CCC_Flat_buffer buf = CCC_flat_buffer_default(mpz_t);
    mpz_t z1, z2, z3, z0;
    mpz_init_set_ui(z1, 17);
    mpz_init_set_ui(z2, 42);
    mpz_init_set_ui(z3, 9);
    if (!CCC_flat_buffer_push_back(&buf, &z1, &alloc))
        abort();
    if (!CCC_flat_buffer_push_back(&buf, &z2, &alloc))
        abort();
    if (!CCC_flat_buffer_push_back(&buf, &z3, &alloc))
        abort();

    CCC_sort_heapsort(&buf, &z0, CCC_ORDER_LESSER, &(CCC_Comparator){.compare = mpz_cmp_wrapper});

    for (mpz_t *i = CCC_flat_buffer_begin(&buf);
         i != CCC_flat_buffer_end(&buf);
         i = CCC_flat_buffer_next(&buf, i))
    {
        gmp_printf("%Zd\n", *i);
    }

    CCC_flat_buffer_clear_and_free(&buf, &(CCC_Destructor){}, &alloc);
    mpz_clear(z1);
    mpz_clear(z2);
    mpz_clear(z3);
    return 0;
}
