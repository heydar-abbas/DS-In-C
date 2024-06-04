#include <stdio.h>
#include <stdlib.h>
#include "../Global.h"
#include "LinkedlistQueue.h"

void main(void)
{
    Queue q;
    QueueEntry e;

    createQueue(&q);

    /*****************  Push to Queue  *****************/
    for (int i = 10; i <= 60; i += 10)
    {
        e.data = i;
        if(!append(e, &q))
            printf("\n Error!! \n\n");
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
    printf("\nThe Front of Queue is [ %d ]\n", q.front->entry);

    /*****************  Clear Queue  *****************/
    clearQueue(&q);
    printf("\nClear Queue:\n");
    printf("Size of Queue: [ %d ]\n", queueSize(&q));
    traverseQueue(&q, &display);
}

void createQueue(Queue *ptr_q)
{
    ptr_q->front = NULL;
    ptr_q->rear = NULL;
    ptr_q->size = 0;
}

int append(QueueEntry e, Queue *ptr_q)
{
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if (!pn)
        return 0;
    pn->next = NULL;
    pn->entry = e;
    if (!ptr_q->rear)
        ptr_q->front = pn;
    else
        ptr_q->rear->next = pn;
    ptr_q->rear = pn;
    ptr_q->size++;
    return 1;
}

void serve(QueueEntry *ptr_e, Queue *ptr_q)
{
    if (queueEmpty(ptr_q))
        return;
    QueueNode *pn = ptr_q->front;
    *ptr_e = pn->entry;
    ptr_q->front = pn->next;
    free(pn);
    if (!ptr_q->front)
        ptr_q->rear = NULL;
    ptr_q->size--;
}

int queueFull(Queue *ptr_q)
{
    return 0;
}

int queueEmpty(Queue *ptr_q)
{
    return !ptr_q->front;
}

int queueSize(Queue *ptr_q)
{
    return ptr_q->size;
}

void clearQueue(Queue *ptr_q)
{
    while (ptr_q->front)
    {
        ptr_q->rear = ptr_q->front->next;
        free(ptr_q->front);
        ptr_q->front = ptr_q->rear;
    }
    ptr_q->size = 0;
}

void traverseQueue(Queue *ptr_q, void (*ptr_f)(QueueEntry))
{
    if (queueEmpty(ptr_q))
        return;
    QueueNode *pn;
    for (pn = ptr_q->front; pn; pn = pn->next)
        (*ptr_f)(pn->entry);
    printf("\n");
}

void display(QueueEntry e)
{
    printf(" %d ", e);
}
