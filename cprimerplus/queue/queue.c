#include <stdlib.h>
#include "queue.h"

void QueueInit(Queue * pq){
    pq->head = NULL;
    pq->tail = NULL;
    pq->count = 0;
}

int QueueCount(const Queue * pq){
    return pq->count;
}

bool QueueIsempty(const Queue * pq){
    return pq->head == NULL ? true : false;
}

bool QueueAdd(Queue * pq, void * data){
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(QueueIsempty(pq)){
        pq->head = node;
        pq->tail = node;
    } else {
        pq->tail->next = node;
        pq->tail = node;
    }
    pq->count += 1;
    return true;
}

void * QueuePop(Queue * pq){
    if(QueueIsempty(pq)){
        return NULL;
    } else {
        Node * node = pq->head;
        void * data = pq->head->data;
        pq->head = pq->head->next;
        pq->count -= 1;
        if(pq->head == NULL){
            pq->tail = NULL;
        }
        free(node);
        return data;
    }
}
