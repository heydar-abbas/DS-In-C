#include <stdio.h>
#include "ArrayStack.h"

/* Initialization the stack */
void createStack(Stack *ps)
{
    ps->top = 0;
}

int stackSize(Stack *ps)
{
    return ps->top;
}

int stackFull(Stack *ps)
{
    return (ps->top == MAX_STACK);
}

int stackEmpty(Stack *ps)
{
    return !ps->top;
}

int push(StackEntry e, Stack *ps)
{
    /* Implementation level check */
    if (stackFull(ps))
        return 0;
    ps->entry[ps->top++] = e;
    return 1;
}

void display(StackEntry e)
{
    printf("Stack Entry is: [ %d ]\n", e.data);
}

int traverseStack(Stack *ps, void (*pf)(StackEntry))
{
    if (stackEmpty(ps))
        return 0;
    for (int i = ps->top; i > 0; i--)
        (*pf)(ps->entry[i - 1]);
    return 1;
}

int pop(StackEntry *pe, Stack *ps)
{
    if (stackEmpty(ps))
        return 0;
    *pe = ps->entry[--ps->top];
    return 1;
}

int top(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[ps->top - 1];
    return pe->data;
}

int clear(Stack *ps)
{
    /* Implementation level check "pre condition" */
    if (stackEmpty(ps))
        return 0;
    ps->top = 0;
    return 1;
}
