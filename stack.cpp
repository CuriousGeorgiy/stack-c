#include "stack.h"

#include "error.h"
#include "memory_alloc.h"
#include "utility.h"

#include <assert.h>
#include <math.h>
#include <stdlib.h>

const size_t CONSTRUCTION_CAPACITY = 1;

const double GROW_COEFFICIENT = 2.5;

const double GROW_COEFFICIENT_IF_FAILURE = 1.5;

enum Error {
    VALID,
    NULL_POINTER_TO_DATA,
    SIZE_GR_THAN_CAPACITY,
    CAPACITY_EQ_ZERO
};

struct Stack {
    val_t *data;
    size_t size;
    size_t capacity;
    Error error;
};

#ifndef NDEBUG
#define VERIFY_STACK(stack) do {                         \
                                if (stack_error(stack)) {\
                                    stack_dump(stack);   \
                                    abort();             \
                                }                        \
                            } while (0)

#define VERIFY_STACK_RETURN(stack, val) do {                    \
                                            VERIFY_STACK(stack);\
                                            return val;         \
                                        } while (0)
#else
#define VERIFY_STACK(stack) ;
#define VERIFY_STACK_RETURN(stack, val) return val
#endif

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
    stack->error = VALID;

    return stack;
}

int stack_error(Stack *stack)
{
    if (stack == NULL) {
        return -1;
    }

    if (stack->data == NULL) {
        return stack->error = NULL_POINTER_TO_DATA;
    }

    if (stack->size > stack->capacity) {
        return stack->error = SIZE_GR_THAN_CAPACITY;
    }

    if (!stack->capacity) {
        return stack->error = CAPACITY_EQ_ZERO;
    }

    return stack->error;
}

int stack_dump(Stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "STACK_ERROR: NULL pointer to Stack\n"
                        "%s [%p]\n", PARAM_NAME(stack), stack);
        return 0;
    }

    switch (stack->error) {
        case VALID: {
            fprintf(stderr, "STACK_ERROR: valid\n"
                            "%s [%p]\n"
                            "{\n"
                            "\tsize     = %zu\n"
                            "\tcapacity = %zu\n"
                            "\tdata [%p]\n"
                            "\t{\n", PARAM_NAME(stack), stack, stack->size, stack->capacity, stack->data);
            for (size_t i = 0; i < stack->size; ++i) fprintf(stderr, "\t\t[%zu] = %f\n", i, stack->data[i]);
            fprintf(stderr, "\t}\n"
                            "}\n");
            return 0;
        }
        case NULL_POINTER_TO_DATA: {
            fprintf(stderr, "STACK_ERROR: NULL pointer to data\n"
                            "%s [%p]\n"
                            "{\n"
                            "\tsize     = %zu\n"
                            "\tcapacity = %zu\n"
                            "\tdata []\n"
                            "}\n", PARAM_NAME(stack), stack, stack->size, stack->capacity, stack->data);
            return 0;
        }
        case SIZE_GR_THAN_CAPACITY: {
            fprintf(stderr, "STACK_ERROR: size is greater than capacity\n"
                            "%s [%p]\n"
                            "{\n"
                            "\tsize     = %zu\n"
                            "\tcapacity = %zu\n"
                            "\tdata [%p]\n"
                            "\t{\n", PARAM_NAME(stack), stack, stack->size, stack->capacity, stack->data);
            for (size_t i = 0; i < stack->capacity; ++i) fprintf(stderr, "\t\t[%10zu] = %f\n", i, stack->data[i]);
            fprintf(stderr, "\t}\n"
                            "}\n");
            return 0;
        }
        case CAPACITY_EQ_ZERO: {
            fprintf(stderr, "STACK_ERROR: size is greater than capacity\n"
                            "%s [%p]\n"
                            "{\n"
                            "\tsize     = %zu\n"
                            "\tcapacity = %zu\n"
                            "\tdata [%p]\n"
                            "}\n", PARAM_NAME(stack), stack, stack->size, stack->capacity, stack->data);
            return 0;
        }
    }
}

int stack_grow(Stack *stack, double grow_coefficient)
{
    VERIFY_STACK(stack);
    assert((grow_coefficient == GROW_COEFFICIENT) || (grow_coefficient == GROW_COEFFICIENT_IF_FAILURE) || (grow_coefficient == 1));

    size_t new_capacity = (grow_coefficient > 1) ? stack->capacity * GROW_COEFFICIENT : stack->capacity + 1;
    val_t *tmp = (val_t *) realloc(stack->data, new_capacity * sizeof(val_t));

    if ((tmp == NULL) && (grow_coefficient == 1)) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        return 1;
    }

    if (tmp == NULL) {
        if (grow_coefficient == GROW_COEFFICIENT) {
            VERIFY_STACK_RETURN(stack, stack_grow(stack, GROW_COEFFICIENT_IF_FAILURE));
        } else {
            VERIFY_STACK_RETURN(stack, stack_grow(stack, 1));
        }
    }

    stack->data = tmp;
    stack->capacity = new_capacity;

    VERIFY_STACK_RETURN(stack, 0);
}

int stack_push(Stack *stack, val_t val)
{
    VERIFY_STACK(stack);
    assert(isfinite(val));

    if (stack->size < stack->capacity) {
        stack->data[stack->size++] = val;
        VERIFY_STACK_RETURN(stack, 0);
    }

    if (stack_grow(stack, GROW_COEFFICIENT)) {
        ERROR_OCCURRED_CALLING(stack_grow, "returned non-zero value");
        VERIFY_STACK_RETURN(stack, 1);
    }

    VERIFY_STACK_RETURN(stack, stack_push(stack, val));
}

int stack_shrink(Stack *stack)
{
    VERIFY_STACK(stack);

    const size_t shrinked_capacity = stack->capacity / (GROW_COEFFICIENT * GROW_COEFFICIENT);

    if (((stack->size) > shrinked_capacity) || (shrinked_capacity == 0)) {
        VERIFY_STACK_RETURN(stack, 0);
    }

    val_t *tmp = (val_t *) realloc(stack->data, shrinked_capacity * sizeof(val_t));

    if (tmp == NULL) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        VERIFY_STACK_RETURN(stack, 1);
    }

    printf("stack was shrinked: capacity changed from %zu to %zu\n", stack->capacity, shrinked_capacity);

    stack->data = tmp;
    stack->capacity = shrinked_capacity;

    VERIFY_STACK_RETURN(stack, 0);
}

val_t stack_pop(Stack *stack)
{
    VERIFY_STACK(stack);

    if (!stack->size) {
        ERROR_OCCURRED("attempt to pop empty stack");
        VERIFY_STACK_RETURN(stack, NAN);
    }

    val_t top = stack->data[--stack->size];

    if (stack_shrink(stack)) {
        ERROR_OCCURRED_CALLING(stack_shrink_to_fit, "returned non-zero value");
    }

    VERIFY_STACK_RETURN(stack, top);
}

int stack_shrink_to_fit(Stack *stack)
{
    VERIFY_STACK(stack);

    val_t *tmp = (val_t *) realloc(stack->data, stack->size * sizeof(val_t));

    if (tmp == NULL) {
        ERROR_OCCURRED_CALLING(realloc, "returned NULL");
        VERIFY_STACK_RETURN(stack, 1);
    }

    stack->data = tmp;
    stack->capacity = stack->size;

    VERIFY_STACK_RETURN(stack, 0);
}

void stack_destruct(Stack **stack)
{
    VERIFY_STACK(*stack);

    FREE((*stack)->data);
    FREE(*stack);
}