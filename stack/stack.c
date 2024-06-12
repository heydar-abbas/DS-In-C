// #include "arrayStack.c"
#include "linkedlistStack.c"

int main()
{
    Stack s;
    StackEntry e;
    /*****************  Initialization Stack  *****************/
    createStack(&s);

    /*****************  Push to Stack  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        e.data = i;
        if (!stackFull(&s))
            push(e, &s);
        else
            printf("\nThe Stack is full!\n\n");
    }
    /*****************  Traverse all Stack  *****************/
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    traverseStack(&s, &display);

    /*****************  Pop from Stack  *****************/
    if (!stackEmpty(&s))
        pop(&e, &s);
    else
        printf("The Stack is empty!\n");
    printf("\nAfter Pop:\n");
    printf("Pop value: [ %d ]\n", e.data);
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    traverseStack(&s, &display);
    /*****************  Top of Stack  *****************/
    printf("\nThe Top of Stack is [ %d ]\n", top(&e, &s));

    /*****************  Clear Stack  *****************/
    clear(&s);
    printf("\nClear Stack:\n");
    printf("Size of Stack: [ %d ]\n", stackSize(&s));
    traverseStack(&s, &display);

    return 0;
}