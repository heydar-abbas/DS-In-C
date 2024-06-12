#include "../Global.h"

/******** Non Linear Structuer ********/

#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;
} StackNode;

typedef struct stack
{
    int size;
    StackNode *top;
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
