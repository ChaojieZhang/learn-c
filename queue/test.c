#include <stdio.h>
#include "queue.h"
struct test {
    int a;
    char b;
};
int main(){
    struct test testData1 = {1, 'a'};
    Queue q;
    Queue * pq = &q;
    QueueInit(pq);
    QueueAdd(pq, &testData1);
    printf("Queue size is %d\n", QueueCount(pq));
    struct test * testPopData = QueuePop(pq);
    printf("Queue pop test a: %d, b: %c\n", testPopData->a, testPopData->b);
    return 0;
}
