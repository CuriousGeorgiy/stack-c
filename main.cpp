#include <stdio.h>

#include "stack.h"

int main()
{
    Stack *stack = stack_construct();

    for (size_t i = 0; i < 250; ++i) {
        stack_push(stack, i);
    }

    for (size_t i = 0; i < 240; ++i) {
        stack_pop(stack);
    }

    printf("%d\n", stack_ok(stack));

    stack_shrink_to_fit(stack);

    printf("%d\n", stack_ok(stack));

    stack_destruct(&stack);

    return 0;
}
