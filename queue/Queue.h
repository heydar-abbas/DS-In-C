#include <stdio.h>

#ifndef _INC_QUEUE
#define _INC_QUEUE

#define MAXQUEUE 5

typedef struct queueentry
{
    int data;
} QueueEntry;

typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
} Queue;

void createQueue(Queue *);
void append(QueueEntry, Queue *);   // enQueue
void serve(QueueEntry *, Queue *);  // deQueue
int queueFull(Queue *);
int queueEmpty(Queue *);
int queueSize(Queue *);
void clearQueue(Queue *);
void traverseQueue(Queue *, void (*ptr_f)(QueueEntry));
void display(QueueEntry);

#endif
