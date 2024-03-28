#include "monty.h"

void pall(StackNode** stack)
{
    StackNode* Current = *stack;
    while (Current != NULL) {
        printf("%d\n", Current->data);
        Current = Current->next;
    }
}
