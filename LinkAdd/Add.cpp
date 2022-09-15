//
// Created by 15776 on 2021/4/10.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "LinkAdd.h"

/*------------------------创建整数单链表--------------------------*/
static void createList(Node *&h, char *a, int n)// 指针的引用
{
    Node *p, *r;
    int i = 0;

    // 创建头结点
    h = (Node *)malloc(sizeof(Node));
    r = h; // r指向新创建的头结点

    while(i < n)
    {
        // 创建新结点p
        p = (Node *)malloc(sizeof(Node));
        p->data = a[n - i - 1] - '0';
        // 将新结点p插入到r结点之后
        r->next = p;
        // r指向新结点p
        r = p;
        i++;
    }

    r->next = NULL;
}

/*------------------------输出整数单链表--------------------------*/
static void displayList(Node *h)
{
    Node *p = h->next; // p指向整数单链表的第一个数据结点

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*------------------------释放整数单链表--------------------------*/
static void destroyList(Node *&h)
{
    Node *pre = h; // pre指向整数单链表的头结点
    Node *p = pre->next; // p指向整数单链表的第一个数据结点

    while(p != NULL)
    {
        free(pre);
        // pre,p同步后移一个结点
        pre = p;
        p = p->next;
    }
    free(pre);
}

/*------------------------两整数单链表h1和h2相加得到h--------------------------*/
static void addList(Node *h1, Node *h2, Node *&h) // 指针的引用
{
    Node *p1 = h1->next; // p1指向单链表h1中的第一个数据结点
    Node *p2 = h2->next; // p2指向单链表h2中的第一个数据结点
    Node *p, *r;
    int carry = 0;

    // 创建头结点
    h = (Node *)malloc(sizeof(Node));
    // r指向新创建头结点
    r = h;

    while(p1 != NULL && p2 != NULL)
    {
        // 创建新结点p
        p = (Node *)malloc(sizeof(Node));
        p->data = (p1->data + p2->data + carry) % 10; // 求余
        // 将新结点p插入到r指向的头结点之后
        r->next = p;
        // r后移一个结点
        r = p;
        carry = (p1->data + p2->data + carry) / 10; // 求商
        // p1和p2指向下一个结点
        p1 = p1->next;
        p2 = p2->next;
    }

    if(p1 == NULL)
        p1 = p2;

    while(p1 != NULL)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = (p1->data + carry) % 10; // 数据域
        // 将新结点p插入到r指向的头结点之后
        r->next = p;
        // r后移一个结点
        r = p;
        carry = (p1->data + carry) / 10;
        p1 = p1->next;
    }

    // 最后carry不为0时,创建一个结点存放它
    if(carry > 0)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = carry;
        // 将新结点p插入到r指向的头结点之后
        r->next = p;
        // r后移一个结点
        r = p;
    }
    r->next = NULL;
}

/*------------------------逆置整数单链表h--------------------------*/
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

/*------------------------求整数单链表h的中间位--------------------------*/
/**
*   算法设计思路:
*   定义快指针quick和慢指针slow,初始时都指向头结点,当快指针没有
*   扫描完整数单链表h时,每次让慢指针slow前进一个结点,快指针quick前进两个
*   结点.当快指针到达链表尾时,慢指针slow指向的结点就是中间结点.
*/
static int midList(Node *h)
{
    Node *slow = h; // 定义慢指针
    Node *quick = h; // 定义快指针

    while(quick != NULL && quick->next != NULL)
    {
        slow = slow->next; // 慢指针slow前进一个结点
        quick = quick->next->next; // 快指针quick前进两个结点
    }
    return slow->data;
}

