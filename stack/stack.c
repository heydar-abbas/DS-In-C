#include <stdio.h>
#include "../Global.h"
#include "Stack.h"

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
            printf("\nThe Stack is full!\n\n");
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
    traverseStack(&s, &display);

    /*****************  Pop from Stack  *****************/
    if (!pop(&e, &s))
        printf("The Stack is empty!");
    printf("\nAfter Pop:\n");
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    traverseStack(&s, &display);
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
    traverseStack(&s, &display);
}

/* Initialization the stack */
void createStack(Stack *ptr_s)
{
    ptr_s->top = 0;
}

int stackSize(Stack *ptr_s)
{
    return ptr_s->top;
}

int stackFull(Stack *ptr_s)
{
    return (ptr_s->top == MAX_STACK);
}

int stackEmpty(Stack *ptr_s)
{
    return !ptr_s->top;
}

int push(StackEntry e, Stack *ptr_s)
{
    /* Implementation level check */
    if (ptr_s->top == MAX_STACK)
        return 0;
    ptr_s->entry[ptr_s->top++] = e;
    return 1;
}

void display(StackEntry e)
{
    printf("Stack Entry is: %d\n", e);
}

int traverseStack(Stack *ptr_s, void (*ptr_f)(StackEntry))
{
    if (ptr_s->top == 0)
    {
        printf("Stack is Empty!\n");
        return 0;
    }
    for (int i = ptr_s->top; i > 0; i--)
    {
        (*ptr_f)(ptr_s->entry[i - 1]);
    }
    return 1;
}

int pop(StackEntry *ptr_e, Stack *ptr_s)
{
    if (ptr_s->top == 0)
        return 0;
    *ptr_e = ptr_s->entry[--ptr_s->top];
    return 1;
}

int top(StackEntry *ptr_e, Stack *ptr_s)
{
    if (ptr_s->top == 0)
        return 0;
    *ptr_e = ptr_s->entry[ptr_s->top - 1];
    return 1;
}

void clear(Stack *ptr_s)
{
    ptr_s->top = 0;
}
