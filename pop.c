#include "monty.h"

int pop(StackNode** stack)
{
	int Value;
	StackNode* tmp;
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Value = (*stack)->data;
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return (Value);
}
