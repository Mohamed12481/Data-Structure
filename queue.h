#define MAX_QUEUE 100

typedef int QueueEntry;

typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAX_QUEUE];
}queue;

void creatQueue(queue *pq);
void append(QueueEntry e, queue *pq);
void serve(QueueEntry *pe, queue *pq);
int queueFull(queue *pq);
int queueEmpty(queue *pq);
int queueSize(queue *pq);
void clearQueue(queue *pq);
void traversQueue(queue *pq, void (*pf)(QueueEntry));