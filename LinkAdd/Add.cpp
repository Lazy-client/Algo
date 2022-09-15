//
// Created by 15776 on 2021/4/10.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "LinkAdd.h"

/*------------------------��������������--------------------------*/
static void createList(Node *&h, char *a, int n)// ָ�������
{
    Node *p, *r;
    int i = 0;

    // ����ͷ���
    h = (Node *)malloc(sizeof(Node));
    r = h; // rָ���´�����ͷ���

    while(i < n)
    {
        // �����½��p
        p = (Node *)malloc(sizeof(Node));
        p->data = a[n - i - 1] - '0';
        // ���½��p���뵽r���֮��
        r->next = p;
        // rָ���½��p
        r = p;
        i++;
    }

    r->next = NULL;
}

/*------------------------�������������--------------------------*/
static void displayList(Node *h)
{
    Node *p = h->next; // pָ������������ĵ�һ�����ݽ��

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*------------------------�ͷ�����������--------------------------*/
static void destroyList(Node *&h)
{
    Node *pre = h; // preָ�������������ͷ���
    Node *p = pre->next; // pָ������������ĵ�һ�����ݽ��

    while(p != NULL)
    {
        free(pre);
        // pre,pͬ������һ�����
        pre = p;
        p = p->next;
    }
    free(pre);
}

/*------------------------������������h1��h2��ӵõ�h--------------------------*/
static void addList(Node *h1, Node *h2, Node *&h) // ָ�������
{
    Node *p1 = h1->next; // p1ָ������h1�еĵ�һ�����ݽ��
    Node *p2 = h2->next; // p2ָ������h2�еĵ�һ�����ݽ��
    Node *p, *r;
    int carry = 0;

    // ����ͷ���
    h = (Node *)malloc(sizeof(Node));
    // rָ���´���ͷ���
    r = h;

    while(p1 != NULL && p2 != NULL)
    {
        // �����½��p
        p = (Node *)malloc(sizeof(Node));
        p->data = (p1->data + p2->data + carry) % 10; // ����
        // ���½��p���뵽rָ���ͷ���֮��
        r->next = p;
        // r����һ�����
        r = p;
        carry = (p1->data + p2->data + carry) / 10; // ����
        // p1��p2ָ����һ�����
        p1 = p1->next;
        p2 = p2->next;
    }

    if(p1 == NULL)
        p1 = p2;

    while(p1 != NULL)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = (p1->data + carry) % 10; // ������
        // ���½��p���뵽rָ���ͷ���֮��
        r->next = p;
        // r����һ�����
        r = p;
        carry = (p1->data + carry) / 10;
        p1 = p1->next;
    }

    // ���carry��Ϊ0ʱ,����һ���������
    if(carry > 0)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = carry;
        // ���½��p���뵽rָ���ͷ���֮��
        r->next = p;
        // r����һ�����
        r = p;
    }
    r->next = NULL;
}

/*------------------------��������������h--------------------------*/
static void reverseList(Node *&h)
{
    Node *p = h->next, *q;
    h->next = NULL;

    while(p != NULL)
    {
        q = p->next;
        p->next = h->next;
        h->next = p;
        p = q;
    }
}

/*------------------------������������h���м�λ--------------------------*/
/**
*   �㷨���˼·:
*   �����ָ��quick����ָ��slow,��ʼʱ��ָ��ͷ���,����ָ��û��
*   ɨ��������������hʱ,ÿ������ָ��slowǰ��һ�����,��ָ��quickǰ������
*   ���.����ָ�뵽������βʱ,��ָ��slowָ��Ľ������м���.
*/
static int midList(Node *h)
{
    Node *slow = h; // ������ָ��
    Node *quick = h; // �����ָ��

    while(quick != NULL && quick->next != NULL)
    {
        slow = slow->next; // ��ָ��slowǰ��һ�����
        quick = quick->next->next; // ��ָ��quickǰ���������
    }
    return slow->data;
}

