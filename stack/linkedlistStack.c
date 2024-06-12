#include <stdio.h>
#include <stdlib.h>
#include "LinkedlistStack.h"

/* Initialization the stack */
void createStack(Stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}

int top(StackEntry *pe, Stack *ps)
{
    *pe = ps->top->entry;
    return pe->data;
}

int stackEmpty(Stack *ps)
{
    return ps->top == NULL;
}

int stackFull(Stack *ps)
{
    return 0;
}

int stackSize(Stack *ps)
{
    return ps->size;
    /*
    int counter;
    StackNode *pn = ps->top;
    for (counter = 0; pn; pn = pn->next)
        counter++;
    return counter;
    */
}

int push(StackEntry e, Stack *ps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    if (!pn)
        return 0;
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
    return 1;
}

int pop(StackEntry *pe, Stack *ps)
{
    /* Implementation level check "pre condition" */
    if (stackEmpty(ps))
        return 0;
    StackNode *pn;
    *pe = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    ps->size--;
    free(pn);
    return 1;
}

int clear(Stack *ps)
{
    /* Implementation level check "pre condition" */
    if (stackEmpty(ps))
        return 0;
    StackNode *pn = ps->top;
    while (pn)
    {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
    return 1;
}

void display(StackEntry e)
{
    printf("Stack Entry is: [ %d ]\n", e.data);
}

int traverseStack(Stack *ps, void (*pf)(StackEntry))
{
    /* Implementation level check "pre condition" */
    if (stackEmpty(ps))
        return 0;
    for (StackNode *pn = ps->top; pn; pn = pn->next)
        (*pf)(pn->entry);
    return 1;
}
