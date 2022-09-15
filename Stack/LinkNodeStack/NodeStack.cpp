// NodeStack.cpp ����ջ���������ļ�
#include <cstdlib>
#include "NodeStack.h"
void initStack(NodeStack *&s)  //��ʼ��ջ s
{
    s=(NodeStack *)malloc(sizeof(NodeStack));
    s->next=nullptr;
}
bool destroyStack(NodeStack *s) //����ջ s
{
    NodeStack *p=s,*q=s->next;
    while(q!=nullptr)
    {
        free(p);
        p=q;
        q=p->next;
    }
    free(p);
    return false;
}
bool stackEmpty(NodeStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    return (s->next==nullptr);
}
bool push(NodeStack *&s, ElemType e)  //��ջ
{
    NodeStack *p;
    p=(NodeStack *)malloc(sizeof(NodeStack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return false;
}
bool pop(NodeStack *&s, ElemType &e)  //��ջ
{
    NodeStack *p;
    if(s->next==nullptr)
        return false;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return true;
}
bool getTop(NodeStack *s, ElemType &e)
{
    if(s->next==nullptr)
        return false;
    e=s->next->data;
    return true;
}

