#include "monty.h"

void free_stack(StackNode* stack)
{
    StackNode* temp;
    while (stack != NULL) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
