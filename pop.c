#include "monty.h"

int pop(StackNode** stack)
{
	int value;
	StackNode* temp;
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    value = (*stack)->data;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return (value);
}
