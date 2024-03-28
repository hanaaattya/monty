#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Ptr to the stack
 * @Line_Num: Current line number
 */
void add(StackNode **stack, unsigned int Line_Num)
{
	int sum;
    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%u: can't add, stack too short\n", Line_Num);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->data + (*stack)->next->data;
    pop(stack);
    (*stack)->data = sum;
}

