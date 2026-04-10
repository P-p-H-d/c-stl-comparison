#include <stdio.h>
#include <stdlib.h>

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
int_cmp(CCC_Comparator_arguments const args)
{
    int const *a = args.type_left;
    int const *b = args.type_right;
    return (*a < *b) ? CCC_ORDER_LESSER
         : (*a > *b) ? CCC_ORDER_GREATER
                     : CCC_ORDER_EQUAL;
}

int main(void)
{
    CCC_Allocator const alloc = {.allocate = my_alloc};
    CCC_Flat_buffer buf = CCC_flat_buffer_default(int);

    if (!CCC_flat_buffer_push_back(&buf, &(int){17}, &alloc))
        abort();
    if (!CCC_flat_buffer_push_back(&buf, &(int){42}, &alloc))
        abort();
    if (!CCC_flat_buffer_push_back(&buf, &(int){9}, &alloc))
        abort();

    CCC_sort_heapsort(&buf, &(int){0}, CCC_ORDER_LESSER,
                      &(CCC_Comparator){.compare = int_cmp});

    for (int *i = CCC_flat_buffer_begin(&buf);
         i != CCC_flat_buffer_end(&buf);
         i = CCC_flat_buffer_next(&buf, i))
    {
        printf("%d\n", *i);
    }

    CCC_flat_buffer_clear_and_free(&buf, &(CCC_Destructor){}, &alloc);
    return 0;
}
