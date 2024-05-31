#include <stdio.h>
#include <stdlib.h>

#ifndef _INC_LINKEDLIST_QUEUE
#define _INC_LINKEDLIST_QUEUE

typedef struct queueentry
{
    int data;
} QueueEntry;

typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
} QueueNode;


typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void createQueue(Queue *);
int append(QueueEntry, Queue *);   // enQueue
void serve(QueueEntry *, Queue *);  // deQueue
int queueFull(Queue *);
int queueEmpty(Queue *);
int queueSize(Queue *);
void clearQueue(Queue *);
void traverseQueue(Queue *, void (*ptr_f)(QueueEntry));
void display(QueueEntry);

#endif
