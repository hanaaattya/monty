#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Ptr to the stack
 * @Line_Num: Current line number
 */
void pint(StackNode **stack, unsigned int Line_Num)
{
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", Line_Num);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->data);
}

