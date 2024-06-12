#include "../Global.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAX_QUEUE];
} Queue;

void createQueue(Queue *);
int append(QueueEntry, Queue *);   // enQueue
int serve(QueueEntry *, Queue *);  // deQueue
int queueFull(Queue *);
int queueEmpty(Queue *);
int queueSize(Queue *);
int front(QueueEntry *, Queue *);
void clearQueue(Queue *);
void traverseQueue(Queue *, void (*ptr_f)(QueueEntry));
void display(QueueEntry);

#endif
