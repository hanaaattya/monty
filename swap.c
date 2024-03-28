#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Ptr to the stack
 * @Line_Num: Current line number
 */
void swap(StackNode **stack, unsigned int Line_Num)
{
	int temp;

    if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%u: can't swap, stack too short\n", Line_Num);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = temp;
}

