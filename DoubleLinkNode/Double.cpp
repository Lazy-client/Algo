//
// Created by 15776 on 2021/4/10.
//
//Double.cpp文件  函数所在文件
#include <cstdio>
#include <cstdlib>
#include "DoubleLinkNode.h"

using namespace std;
void createList(DoubleNode *&L, const ElementType *a, int n)
{
    DoubleNode* t;
    L = (DoubleNode*)malloc(sizeof(DoubleNode));
    DoubleNode* s = L;
    for (int i = 0; i < n; ++i)
    {
        t = (DoubleNode*)malloc(sizeof(DoubleNode));
        t->data = a[i];
        s->next = t;
        t->prior = s;
        s = t;
    }
    s->next = nullptr;
}
int listLength(DoubleNode *L)
{
    int i = -1;
    DoubleNode* s = L;
    while (s!=nullptr)
    {
        i++;
        s = s->next;
    }
    return i;
}

bool getElem(DoubleNode *L, int i, ElementType &e)
{
    DoubleNode* s = L;
    int j = 0;
    while (s!=nullptr&&j<i)
    {
        j++;
        s = s->next;
    }
    if (s==nullptr)
    {
        return false;
    }
    else
    {
        e = s->data;
        return true;
    }
}
int locateElem(DoubleNode *L, ElementType e)
{
    int i = 0;
    DoubleNode* s = L;
    while (s!=nullptr&&s->data!=e)
    {
        i++;
        s = s->next;
    }
    if (s==nullptr)
    {
        return 0;
    }else
    {
        return i;
    }
}
bool listInsert(DoubleNode *L, int i, ElementType e)
{
    DoubleNode* s = L;
    DoubleNode* r;
    int j = 0;
    while (s!=nullptr&&j<i-1)
    {
        j++;
        s = s->next;
    }
    if (s==nullptr)
    {
        return false;
    }
    else
    {
        r = (DoubleNode*)malloc(sizeof(DoubleNode));
        r->data = e;
        r->next = s->next;
        if (s->next!=nullptr)
        {
            s->next->prior = r;
        }
        s->next = r;
        r->prior = s;
        return true;
    }
}
bool listDelete(DoubleNode *L, int i)
{
    if (i<1)
    {
        return false;
    }
    int j = 0;
    DoubleNode* p = L, * q;
    while (j<i-1&&p!=nullptr)
    {
        j++;
        p = p->next;
    }
    if (p==nullptr)
    {
        return false;
    }else
    {
        q = p->next;
        if (q==nullptr)
        {
            return false;
        }
        p->next = q->next;
        if (q->next!=nullptr)
        {
            q->next->prior = p;
        }
        free(q);
        return true;
    }
}
void displayList(DoubleNode *L)
{
    DoubleNode* s;
    s = L->next;
    while (s!=nullptr)
    {
        printf("%c", s->data);
        s = s->next;
    }
    printf("\n");
}

