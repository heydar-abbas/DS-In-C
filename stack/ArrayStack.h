#include "../Global.h"

/******** Linear Structuer ********/

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct stack
{
    int top;
    StackEntry entry[MAX_STACK];
} Stack;

void createStack(Stack *);
int push(StackEntry, Stack *);
int pop(StackEntry *, Stack *);
int top(StackEntry *, Stack *);
int clear(Stack *);
int stackFull(Stack *);
int stackEmpty(Stack *);
int stackSize(Stack *);
void display(StackEntry);
int traverseStack(Stack *, void (*ptr_f)(StackEntry));

#endif
