#include <stdio.h>
#include <stdlib.h>
/******** Non Linear Structuer ********/

#ifndef _INC_LINKEDLIST_STACK
#define _INC_LINKEDLIST_STACK

typedef struct entry
{
    int data;
} StackEntry;

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
void clear(Stack *);
void display(StackEntry);
int traverseStack(Stack *, void (*ptr_f)(StackEntry));
int stackFull(Stack *);
int stackEmpty(Stack *);
int stackSize(Stack *);

#endif
