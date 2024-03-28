#include "monty.h"

void free_stack(StackNode* stack)
{
    StackNode* tmp;
    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
