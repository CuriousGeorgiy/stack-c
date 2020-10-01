#include "stack.h"

#include "error.h"
#include "memory_alloc.h"

#include <assert.h>
#include <stdlib.h>

const size_t CONSTRUCTION_CAPACITY = 1;

const double GROW_COEFFICIENT = 2.5;

const double GROW_COEFFICIENT_IF_FAILURE = 1.5;

struct Stack {
    val_t *data;
    size_t size;
    size_t capacity;
};

Stack *stack_construct()
{
    assert(CONSTRUCTION_CAPACITY > 0);

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

int stack_grow(Stack *stack, double grow_coefficient)
{
    assert(stack != NULL);
    assert((grow_coefficient == GROW_COEFFICIENT) || (grow_coefficient == GROW_COEFFICIENT_IF_FAILURE) || (grow_coefficient == 1));

    size_t new_capacity = (grow_coefficient > 1) ? stack->capacity * GROW_COEFFICIENT : stack->capacity + 1;
    val_t *tmp = (val_t *) realloc(stack->data, new_capacity * sizeof(val_t));

    if ((tmp == NULL) && (grow_coefficient == 1)) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        return 1;
    }

    if (tmp == NULL) {
        if (grow_coefficient == GROW_COEFFICIENT) {
            return stack_grow(stack, GROW_COEFFICIENT_IF_FAILURE);
        } else {
            return stack_grow(stack, 1);
        }
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

    if (stack_grow(stack, GROW_COEFFICIENT)) {
        ERROR_OCCURRED_CALLING(stack_grow, "returned non-zero value");
        return 1;
    }

    return stack_push(stack, val);
}

int stack_shrink(Stack *stack)
{
    assert(stack != NULL);

    const size_t shrinked_capacity = stack->capacity / (GROW_COEFFICIENT * GROW_COEFFICIENT);

    if (((stack->size) > shrinked_capacity) || (shrinked_capacity == 0)) {
        return 0;
    }

    val_t *tmp = (val_t *) realloc(stack->data, shrinked_capacity * sizeof(val_t));

    if (tmp == NULL) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        return 1;
    }

    printf("stack was shrinked: capacity changed from %zu to %zu\n", stack->capacity, shrinked_capacity);

    stack->data = tmp;
    stack->capacity = shrinked_capacity;

    return 0;
}

val_t stack_pop(Stack *stack)
{
//  TODO implement shrinking capacity
    assert(stack != NULL);

    if (!stack->size) {
        ERROR_OCCURRED("attempt to pop empty stack");
        return 0;
    }

    val_t top = stack->data[--stack->size];

    if (stack_shrink(stack)) {
        ERROR_OCCURRED_CALLING(stack_shrink_to_fit, "returned non-zero value");
    }

    return top;
}

int stack_shrink_to_fit(Stack *stack)
{
    assert(stack);

    val_t *tmp = (val_t *) realloc(stack->data, stack->size * sizeof(val_t));

    if (tmp == NULL) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        return 1;
    }

    stack->data = tmp;
    stack->capacity = stack->size;

    return 0;
}

bool stack_ok(const Stack *stack)
{
    assert(stack != NULL);

    return (stack->data != NULL) && (stack->size <= stack->capacity) && (stack->capacity);
}

void stack_destruct(Stack **stack)
{
    assert(stack != NULL);

    FREE((*stack)->data);
    FREE(*stack);
}