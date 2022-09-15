//
// Created by 15776 on 2021/4/10.
//
//LinkAdd.h 结构体所在文件
#define MAX_SIZE 50
typedef struct Node
{
    int data; // 数据域
    struct Node *next; // 指针域
}Node;