#include <stdio.h>

#include "stack.h"

int main()
{
    Stack *stack = new_stack();

    for (size_t i = 0; i < 100; ++i) {
        stack_push(stack, i);
    }

    for (size_t i = 0; i < 90; ++i) {
        bool err;
        stack_pop(stack, &err);
    }

    delete_stack(&stack);

    return 0;
}
