#ifndef STACK_H
#define STACK_H

/*!
 * Defines the type of elements stored in the stack
 */
typedef double val_t;

/*!
 * Defines LIFO data structure
 */
struct Stack;

/*!
 * Allocates a Stack with non-zero capacity
 *
 * @return pointer to a newly allocated Stack
 */
Stack *stack_construct();

/*!
 * Pushes val into stack
 *
 * @param [in, out] stack pointer to Stack
 * @param [in] val value to be pushed
 *
 * @return 0 in case of success, a non-zero value otherwise
 *
 * @note In case of failure doesn't modify stack
 */
int stack_push(Stack *stack, val_t val);

/*!
 * Pops a value from stack
 *
 * @param [in, out] stack pointer to Stack
 *
 * @return the popped value
 *
 * @note Returns 0 in case the stack was empty
 */
val_t stack_pop(Stack *stack);

/*!
 * Shrinks stack to fit
 *
 * @param [in, out] stack pointer to Stack
 *
 * @return 0 in case of success, a non-zero value otherwise
 */
int stack_shrink_to_fit(Stack *stack);

/*!
 * Checks if stack is OK
 *
 * @param [in] stack pointer to Stack
 *
 * @return true if stack is OK, false otherwise
 */
bool stack_ok(const Stack *stack);

/*!
 * Frees the stack and sets in to a NULL pointer
 *
 * @param [in] stack address of pointer to Stack
 */
void stack_destruct(Stack **stack);

#endif /* STACK_H */
