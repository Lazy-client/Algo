//
// Created by zsc on 2021/4/24.
//
// Stack.h 栈结构体所在文件
#include <iostream>
#define MAX_SIZE 100
typedef char ElemType;
typedef struct
{
    ElemType data[MAX_SIZE];
    int top;           //栈顶指针
}Stack;

