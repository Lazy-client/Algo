//
// Created by 15776 on 2021/4/24.
//
//
#include <cstdlib>
#include "CircleArrayQueue.h"
void initQueue(SqQueue *&q)  //��ʼ������
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
void destroyQueue(SqQueue *&q)  //���ٶ���
{
    free(q);
}
bool queueEmpty(SqQueue *q)     //�ж϶����Ƿ�Ϊ��
{
    return (q->front==q->rear);
}
bool enQueue(SqQueue *&q, ElemType e)   //����
{
    if((q->rear+1) % MAX_SIZE == q->front)  //�����������
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
