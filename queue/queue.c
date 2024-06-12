#include "arrayqueue.c"
// #include "linkedlistqueue.c"

int main()
{
    Queue q;
    QueueEntry e;

    createQueue(&q);

    /*****************  Append into Queue  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        e.data = i;
        if (!queueFull(&q))
            append(e, &q);
        else
            printf("\nQueue is Full!!\n\n");
    }
    /*****************  Traverse all Queue  *****************/
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);

    /*****************  Serve from Queue  *****************/
    if (!queueEmpty(&q))
        serve(&e, &q);
    else
        printf("The Queue is empty!\n");
    printf("\nAfter Serve:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    printf("Served value: [ %d ]\n", e);
    traverseQueue(&q, &display);
    /*****************  Appeng again  *****************/
    e.data = 100;
    append(e, &q);
    printf("\nAfter append again:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);
    /*****************  Front of Queue  *****************/
    printf("\nThe Front of Queue is [ %d ]\n", front(&e, &q));

    /*****************  Clear Queue  *****************/
    clearQueue(&q);
    printf("\nClear Queue:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);

    return 0;
}
