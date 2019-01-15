#include <cstdio>
#include <cstdlib>
#include "queue.h"
using namespace std;

int isEmpty(QUEUE *q)
{
    return (q->size == 0);
}
int isFull(QUEUE *q)
{
    return (q->size == q->capacity);
}
QUEUE *createQueue(int maxElements)
{
    if(maxElements < MinQueueSize) {
        printf("queue size is too small\n");    
        return NULL;
    } else {
        QUEUE *q = (QUEUE *)malloc(sizeof(struct queueRecord));
        q->array = (elementType *)malloc(sizeof(elementType) * maxElements);
        q->capacity = maxElements;
        initQueue(q);
        return q;
    }
}
void disposeQueue(QUEUE *q)
{
    if(q != NULL) {
        free(q->array); 
        free(q);
    }   
}
void initQueue(QUEUE *q)
{
    if(q != NULL) {
        q->front_sub = 1;   
        q->rear_sub = 0;
        q->size = 0;
    }
}
static int succ(int value, QUEUE *q) 
{
    if(++value == q->capacity) 
        value = 0;
    return value;
}
void enterQueue(elementType element, QUEUE *q)
{
    if(!isFull(q)) {
        q->size++;  
        q->rear_sub = succ(q->rear_sub, q);
        q->array[q->rear_sub] = element;
        printf("enterQueue : %d\n", element);
    } else {
        printf("Full queue\n"); 
    }
}
elementType front_sub(QUEUE *q)
{
    if(!isEmpty(q)) {
        return q->array[q->front_sub];  
    } else {
        printf("empty queue\n");    
    }
}
void outQueue(QUEUE *q)
{
    if(!isEmpty(q)) {
        printf("\nout Queue : %d\n", q->array[q->front_sub]);
        q->size--;
        q->front_sub = succ(q->front_sub, q);
    } else {
        printf("empty queue\n");    
    }
}
elementType front_subAndDequeue(QUEUE *q)
{
    if(!isEmpty(q)) {
        int ret = q->array[q->front_sub];
        q->size--;
        q->front_sub = succ(q->front_sub, q);
        return ret; 
    } else {
        printf("empty queue\n");    
        return 0;
    }
}
void printQueue(QUEUE *q)
{
    int i = 0; 
    if(!isEmpty(q)) {
        printf("\nthe queue:\n\n");
        if(q->rear_sub > q->front_sub)
            for(i = q->front_sub; i <= q->rear_sub; i++)
            {
                printf("|    %d    |\n", q->array[i]);
            }
    }else {
        printf("empty queue!\n");
    }
}

// int main(int argc, char const *argv[])
// {
//     QUEUE *q;
//     int i = 0;
//     int n = 0;
//     printf("please input the capacity:");
//     scanf("%d", &n);
//     q = createQueue(n+1);
//     for(i = 1;i <= n;i++)
//         enterQueue(i, q);
//     printQueue(q);
//     outQueue(q);
//     printQueue(q);
//     disposeQueue(q);
//     system("pause");
//     return 0;
// }