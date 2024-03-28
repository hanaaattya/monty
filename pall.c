#include "monty.h"

void pall(StackNode** stack)
{
    StackNode* current = *stack;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
