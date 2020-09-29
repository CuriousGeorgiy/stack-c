#ifndef STACK_H
#define STACK_H

typedef double val_t;

const size_t CONSTRUCTION_CAPACITY = 32;
const size_t GROW_COEFFICIENT = 2;

struct Stack {
    val_t *data;

    size_t size;
    size_t capacity;
};

/*!
 * @brief
 * @return
 */
Stack *stack_construct();

/*!
 * @brief
 * @param stack
 * @param val
 * @return
 */
int stack_push(Stack *stack, val_t val);

/*!
 * @brief
 * @param stack
 * @return
 */
val_t stack_pop(Stack *stack);

/*!
 * @brief
 * @param stack
 * @return
 */
bool stack_ok(Stack *stack);

/*!
 * @brief
 * @param stack
 * @return
 */
void stack_delete(Stack *stack);

#endif //STACK_H
