#ifndef _QUEUE_C_
#define _QUEUE_C_
#include <stdbool.h>
typedef struct node {
    void * data;
    struct node * next;
} Node;

typedef struct queue {
    Node * head;
    Node * tail;
    int count;
} Queue;

void QueueInit(Queue * pq);
bool QueueIsempty(const Queue * pq);
int QueueCount(const Queue * pq);
bool QueueAdd(Queue * pq, void * data);
void * QueuePop(Queue * pq);
bool QueueEmpty(const Queue * pq);
bool QueueDelete(const Queue * pq);
#endif
