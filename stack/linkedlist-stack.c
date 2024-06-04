#include <stdio.h>
#include <stdlib.h>
#include "../Global.h"
#include "LinkedlistStack.h"

void main(void)
{
    Stack s;
    StackEntry e;
    /*****************  Initialization Stack  *****************/
    createStack(&s);

    /*****************  Push to Stack  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        e.data = i;
        if (!push(e, &s))
            printf("\nError!!\n\n");
    }
    /*
    User level check "post condition"
    if (!stackFull(&s))
        push(e, &s);
    else
        printf("The Stack is full!");
    */
    /*****************  Traverse all Stack  *****************/
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    if (!traverseStack(&s, &display))
        printf("The Stack is empty!\n");

    /*****************  Pop from Stack  *****************/
    if (!pop(&e, &s))
        printf("The Stack is empty!");
    printf("\nAfter Pop:\n");
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    if (!traverseStack(&s, &display))
        printf("The Stack is empty!\n");
    printf("\nPop value: [ %d ]\n", e);
    /*
    User level check "post condition"
    if (!stackEmpty(&s))
        pop(&e, &s);
    else
        printf("The Stack is empty!");
    */
    /*****************  Top of Stack  *****************/
    top(&e, &s);
    printf("\nThe Top of Stack is [ %d ]\n", e.data);

    /*****************  Clear Stack  *****************/
    clear(&s);
    printf("\nClear Stack:\n");
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    if (!traverseStack(&s, &display))
        printf("The Stack is empty!\n");
}

/* Initialization the stack */
void createStack(Stack *ptr_s)
{
    ptr_s->top = NULL;
    ptr_s->size = 0;
}

int push(StackEntry e, Stack *ptr_s)
{
    StackNode *ptr_n = (StackNode *)malloc(sizeof(StackNode));
    if (!ptr_n)
        return 0;
    ptr_n->entry = e;
    ptr_n->next = ptr_s->top;
    ptr_s->top = ptr_n;
    ptr_s->size++;
    return 1;
}

int pop(StackEntry *ptr_e, Stack *ptr_s)
{
    /* Implementation level check "pre condition" */
    if (ptr_s->top == NULL)
        return 0;
    StackNode *ptr_n;
    *ptr_e = ptr_s->top->entry;
    ptr_n = ptr_s->top;
    ptr_s->top = ptr_s->top->next;
    ptr_s->size--;
    free(ptr_n);
    return 1;
}

int top(StackEntry *ptr_e, Stack *ptr_s)
{
    /* Implementation level check "pre condition" */
    if (ptr_s->top == NULL)
        return 0;
    *ptr_e = ptr_s->top->entry;
    return 1;
}

int stackEmpty(Stack *ptr_s)
{
    return ptr_s->top == NULL;
}

int stackFull(Stack *ptr_s)
{
    return 0;
}

int stackSize(Stack *ptr_s)
{
    return ptr_s->size;
    /*
    int counter;
    StackNode *ptr_n = ptr_s->top;
    for (counter = 0; ptr_n; ptr_n = ptr_n->next)
        counter++;
    return counter;
    */
}

void clear(Stack *ptr_s)
{
    StackNode *ptr_n = ptr_s->top;
    while (ptr_n)
    {
        ptr_n = ptr_n->next;
        free(ptr_s->top);
        ptr_s->top = ptr_n;
    }
    ptr_s->size = 0;
}

void display(StackEntry e)
{
    printf("Stack Entry is: [ %d ]\n", e);
}

int traverseStack(Stack *ptr_s, void (*ptr_f)(StackEntry))
{
    /* Implementation level check "pre condition" */
    if (ptr_s->top == NULL)
        return 0;
    for (StackNode *ptr_n = ptr_s->top; ptr_n; ptr_n = ptr_n->next)
        (*ptr_f)(ptr_n->entry);
    /*
    StackNode * ptr_n = ptr_s->top;
    while (ptr_n)
    {
        (*ptr_f)(ptr_n->entry);
        ptr_n = ptr_n->next;
    }
    */
    return 1;
}
