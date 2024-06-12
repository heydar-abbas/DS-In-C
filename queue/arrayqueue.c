#include <stdio.h>
#include "ArrayQueue.h"

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

int serve(QueueEntry *ptr_e, Queue *ptr_q)
{
    if (queueEmpty(ptr_q))
        return -1;
    *ptr_e = ptr_q->entry[ptr_q->front];
    ptr_q->front = (ptr_q->front + 1) % MAX_QUEUE;
    ptr_q->size--;
    return 1;
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

int front(QueueEntry *pqe, Queue *pq)
{
    *pqe = pq->entry[pq->front];
    return pqe->data;
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
