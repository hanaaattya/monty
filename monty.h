#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1024
typedef struct stack_node {
    int data;
    struct stack_node* next;
} StackNode;

void push(StackNode** stack, int value);
int pop(StackNode** stack);
void pall(StackNode** stack);
void free_stack(StackNode* stack);
void pint(StackNode **stack, unsigned int Line_Num);
void swap(StackNode **stack, unsigned int Line_Num);
void add(StackNode **stack, unsigned int Line_Num);
void nop(StackNode **stack, unsigned int Line_Num);
#endif

