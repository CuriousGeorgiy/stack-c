#include <stdio.h>
#include <stdlib.h>

#include "log.h"
#include "stack.h"

int main()
{
    if (init_logging()) {
        return EXIT_FAILURE;
    }

    Stack *stack = new_stack();

    for (size_t i = 0; i < 100; ++i) {
        stack_push(stack, i);
    }

    stack_print(stack);

    for (size_t i = 0; i < 90; ++i) {
        bool err;
        stack_pop(stack, &err);
    }

    stack_print(stack);

    delete_stack(&stack);

    return 0;
}