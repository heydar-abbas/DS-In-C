#include <stdio.h>
#include <stdlib.h>
#include "LinkedlistQueue.h"

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

int serve(QueueEntry *ptr_e, Queue *ptr_q)
{
    if (queueEmpty(ptr_q))
        return -1;
    QueueNode *pn = ptr_q->front;
    *ptr_e = pn->entry;
    ptr_q->front = pn->next;
    free(pn);
    if (!ptr_q->front)
        ptr_q->rear = NULL;
    ptr_q->size--;
    return 1;
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

int front(QueueEntry *pqe, Queue *pq)
{
    *pqe = pq->front->entry;
    return pqe->data;
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
    QueueNode *pn;
    for (pn = ptr_q->front; pn; pn = pn->next)
        (*ptr_f)(pn->entry);
    printf("\n");
}

void display(QueueEntry e)
{
    printf(" %d ", e);
}
