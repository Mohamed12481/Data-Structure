#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void creatQueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void append(QueueEntry e, queue *pq)
{
    if (queueFull(pq))
    {
        return; 
    }
    
    pq->rear = ((pq->rear) + 1) % MAX_QUEUE;
    pq->entry[pq->rear] = e;
    (pq->size)++;
}

void serve(QueueEntry *pe, queue *pq)
{
    if (queueEmpty(pq))
    {
        return; 
    }
    
    *pe = pq->entry[pq->front];
    pq->front = ((pq->front) + 1) % MAX_QUEUE;
    (pq->size)--;
}

int queueEmpty(queue *pq)
{
    return !pq->size;
}

int queueFull(queue *pq)
{
    return ((pq->size) == MAX_QUEUE);
}

int queueSize(queue *pq)
{
    return pq->size;
}

void clearQueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void traversQueue(queue *pq, void (*pf)(QueueEntry))
{
    int pos, s;
    for (pos = (pq->front), s = 0; s < (pq->size); s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAX_QUEUE;
    }
    
}