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
str_cmp(CCC_Comparator_arguments const args)
{
    const char * const *a = args.type_left;
    const char * const *b = args.type_right;
    return (strcmp(*a, *b) < 0) ? CCC_ORDER_LESSER
         : (strcmp(*a, *b) > 0) ? CCC_ORDER_GREATER
                     : CCC_ORDER_EQUAL;
}

int main(void)
{
    CCC_Allocator const alloc = {.allocate = my_alloc};
    CCC_Flat_buffer buf = CCC_flat_buffer_default(const char *);

    if (!CCC_flat_buffer_push_back(&buf, &(const char *){"World"}, &alloc))
        abort();
    if (!CCC_flat_buffer_push_back(&buf, &(const char *){"Hello"}, &alloc))
        abort();
    if (!CCC_flat_buffer_push_back(&buf, &(const char *){"!"}, &alloc))
        abort();

    CCC_sort_heapsort(&buf, &(const char *){0}, CCC_ORDER_LESSER, &(CCC_Comparator){.compare = str_cmp});

    for (const char **i = CCC_flat_buffer_begin(&buf);
         i != CCC_flat_buffer_end(&buf);
         i = CCC_flat_buffer_next(&buf, i))
    {
        printf("%s\n", *i);
    }

    CCC_flat_buffer_clear_and_free(&buf, &(CCC_Destructor){}, &alloc);
    return 0;
}
