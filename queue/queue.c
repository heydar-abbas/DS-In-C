#include <stdio.h>
#include "Queue.h"

void main(void)
{
    Queue q;
    QueueEntry e;

    createQueue(&q);

    /*****************  Push to Queue  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        e.data = i;
        if (!append(e, &q))
            printf("\n Queue is Full!! \n\n");
    }
    /*
    User level check "post condition"
    if (!queueFull(&s))
        append(e, &s);
    else
        printf("The Queue is full!");
    */
    /*****************  Traverse all Queue  *****************/
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);

    /*****************  Serve from Queue  *****************/
    serve(&e, &q);
    printf("\nAfter Serve:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);
    printf("\nServed value: [ %d ]\n", e);
    /*
    User level check "post condition"
    if (!queueEmpty(&q))
        serve(&e, &q);
    else
        printf("The Queue is empty!");
    */
    /*****************  Appeng again  *****************/
    e.data = 100;
    append(e, &q);
    printf("\nAfter append again:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);
    /*****************  Front of Queue  *****************/
    printf("\nThe Front of Queue is [ %d ]\n", q.entry[q.front]);

    /*****************  Clear Queue  *****************/
    clearQueue(&q);
    printf("\nClear Queue:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);
}

void createQueue(Queue *ptr_q)
{
    ptr_q->front = 0;
    ptr_q->rear = -1;
    ptr_q->size = 0;
}

int append(QueueEntry e, Queue *ptr_q)
{
    if (queueFull(ptr_q))
        return 0;
    // (ptr_q->rear == MAX_QUEUE - 1) ? ptr_q->rear = 0 : ptr_q->rear++;
    ptr_q->rear = (ptr_q->rear + 1) % MAX_QUEUE;
    ptr_q->entry[ptr_q->rear] = e;
    ptr_q->size++;
    return 1;
}

void serve(QueueEntry *ptr_e, Queue *ptr_q)
{
    if (queueEmpty(ptr_q))
        return;
    *ptr_e = ptr_q->entry[ptr_q->front];
    ptr_q->front = (ptr_q->front + 1) % MAX_QUEUE;
    ptr_q->size--;
}

int queueFull(Queue *ptr_q)
{
    return (ptr_q->size == MAX_QUEUE);
}

int queueEmpty(Queue *ptr_q)
{
    return !ptr_q->size;
}

int queueSize(Queue *ptr_q)
{
    return ptr_q->size;
}

void clearQueue(Queue *ptr_q)
{
    ptr_q->front = 0;
    ptr_q->rear = -1;
    ptr_q->size = 0;
}

void traverseQueue(Queue *ptr_q, void (*ptr_f)(QueueEntry))
{
    int pos, s;
    for (pos = ptr_q->front, s = 0; s < ptr_q->size; s++)
    {
        (*ptr_f)(ptr_q->entry[pos]);
        pos = (pos + 1) % MAX_QUEUE;
    }
    printf("\n");
}

void display(QueueEntry e)
{
    printf(" %d ", e);
}
