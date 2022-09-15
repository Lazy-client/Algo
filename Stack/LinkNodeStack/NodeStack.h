//
// Created by 15776 on 2021/4/24.
//
// NodeStack.h    栈所在的结构体
typedef char ElemType;
using namespace std;
typedef struct NodeStack
{
    ElemType data;
    NodeStack *next;
} NodeStack;