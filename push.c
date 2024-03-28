#include "monty.h"

void push(StackNode** stack, int value)
{
    StackNode* New_Node = malloc(sizeof(StackNode));
    if (New_Node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    New_Node->data = value;
    New_Node->next = *stack;
    *stack = New_Node;
}
