#include "stack.h"

#include "error.h"
#include "memory_alloc.h"

#include <assert.h>
#include <stdlib.h>

const size_t CONSTRUCTION_CAPACITY = 32;
const size_t GROW_COEFFICIENT = 2;

struct Stack {
    val_t *data;
    size_t size;
    size_t capacity;
};

Stack *stack_construct()
{
    Stack *stack = (Stack *) calloc(1, sizeof(Stack));

    if (stack == NULL) {
        ERROR_OCCURRED_CALLING(calloc, "returned NULL");
        return NULL;
    }

    stack->data = (val_t *) calloc(CONSTRUCTION_CAPACITY, sizeof(val_t));
    stack->capacity = CONSTRUCTION_CAPACITY;
    stack->size = 0;

    return stack;
}

int stack_grow(Stack *stack)
{
//  TODO try to recover from null realloc
    assert(stack != NULL);

    size_t new_capacity = stack->capacity * GROW_COEFFICIENT;
    val_t *tmp = (val_t *) realloc(stack->data, new_capacity * sizeof(val_t));

    if (tmp == NULL) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        return 1;
    }

    stack->data = tmp;
    stack->capacity = new_capacity;

    return 0;
}

int stack_push(Stack *stack, val_t val)
{
    assert(stack != NULL);

    if (stack->size < stack->capacity) {
        stack->data[stack->size++] = val;
        return 0;
    }

    if (stack_grow(stack)) {
        ERROR_OCCURRED_CALLING(stack_grow, "returned non-zero value");
        return 1;
    }

    return stack_push(stack, val);
}

val_t stack_pop(Stack *stack)
{
//  TODO implement shrinking capacity
    assert(stack != NULL);

    if (!stack->size) {

        return 0;
    }

    return stack->data[--stack->size];
}

bool stack_ok(Stack *stack)
{
    assert(stack != NULL);

    return (stack->data != NULL) && (stack->size <= stack->capacity) && (stack->capacity);
}

void stack_delete(Stack **stack)
{
    assert(stack != NULL);

    FREE((*stack)->data);
    FREE(*stack);
}