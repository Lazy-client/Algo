//
// Created by 15776 on 2021/4/24.
//
// Stack.cpp ���������ļ�
#include <cstdlib>
#include "Stack.h"

void initStack(Stack *&s)  //��ʼ��ջ s
{
    s=(Stack *)malloc(sizeof(Stack));
    s->top=-1;
}
bool destroyStack(Stack *s) //����ջ s
{
    free(s);
}
bool stackEmpty(Stack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    return (s->top==-1);
}
bool push(Stack *&s, ElemType e)  //��ջ
{
    if(s->top == MAX_SIZE - 1) //ջ�����������ջ�����
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
bool pop(Stack *&s, ElemType &e)  //��ջ
{
    if(s->top==-1)  //ջΪ�յģ���ջ�����
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}
bool getTop(Stack *s, ElemType &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}
