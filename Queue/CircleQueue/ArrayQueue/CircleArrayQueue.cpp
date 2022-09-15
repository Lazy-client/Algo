//
// Created by 15776 on 2021/4/24.
//
//
#include <cstdlib>
#include "CircleArrayQueue.h"
void initQueue(SqQueue *&q)  //初始化队列
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
void destroyQueue(SqQueue *&q)  //销毁队列
{
    free(q);
}
bool queueEmpty(SqQueue *q)     //判断队列是否为空
{
    return (q->front==q->rear);
}
bool enQueue(SqQueue *&q, ElemType e)   //进队
{
    if((q->rear+1) % MAX_SIZE == q->front)  //队满，上溢出
        return false;
    q->rear= (q->rear+1) % MAX_SIZE;
    q->elem[q->rear]=e;
    return true;
}
bool deQueue(SqQueue *&q, ElemType &e)
{
    if(q->front==q->rear)
        return false;
    q->front= (q->front+1) % MAX_SIZE;
    e=q->elem[q->front];
    return true;
}
