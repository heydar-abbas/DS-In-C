#include <stdio.h>
/******** Linear Structuer ********/

#ifndef _INC_ARRAY_STACK
#define _INC_ARRAY_STACK

#define MAX_STACK 5

typedef struct entry
{
    int data;
} StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAX_STACK];
} Stack;

void createStack(Stack *);
int push(StackEntry, Stack *);
int pop(StackEntry *, Stack *);
int top(StackEntry *, Stack *);
void clear(Stack *);
void display(StackEntry);
int traverseStack(Stack *, void (*ptr_f)(StackEntry));
int stackFull(Stack *);
int stackEmpty(Stack *);
int stackSize(Stack *);

#endif
