#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MinQueueSize 5 //最小队列元素

typedef int elementType;

typedef struct queueRecord
{
    int capacity;       //队列的最大容量
    int front_sub;          //队首元素下标
    int rear_sub;           //队尾元素下标
    int size;           //队列有多少元素
    elementType *array; //指向动态分配的内存
} QUEUE;

int isEmpty(QUEUE *q);                       //判空
int isFull(QUEUE *q);                        //判满
QUEUE *createQueue(int maxElements);         //创建一个队列
void disposeQueue(QUEUE *q);                 //销毁一个队列
void initQueue(QUEUE *q);                    //构造一个空队列
void enterQueue(elementType element, QUEUE *q); //入队
elementType front(QUEUE *q);                 //返回队首元素但不删除
void outQueue(QUEUE *q);                      //删除队首元素不返回
elementType frontAndDequeue(QUEUE *q);       //出队，返回并删除

#endif
