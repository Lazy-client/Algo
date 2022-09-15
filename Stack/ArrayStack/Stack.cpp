//
// Created by 15776 on 2021/4/24.
//
// Stack.cpp 方法所在文件
#include <cstdlib>
#include "Stack.h"

void initStack(Stack *&s)  //初始化栈 s
{
    s=(Stack *)malloc(sizeof(Stack));
    s->top=-1;
}
bool destroyStack(Stack *s) //销毁栈 s
{
    free(s);
}
bool stackEmpty(Stack *s)   //判断栈是否为空
{
    return (s->top==-1);
}
bool push(Stack *&s, ElemType e)  //进栈
{
    if(s->top == MAX_SIZE - 1) //栈满的情况，即栈上溢出
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
bool pop(Stack *&s, ElemType &e)  //出栈
{
    if(s->top==-1)  //栈为空的，即栈下溢出
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
