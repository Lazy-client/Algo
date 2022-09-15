//
// Created by 15776 on 2021/4/24.
//


#define MAX_SIZE 5

typedef char ElemType;
using namespace std;
typedef struct
{
    ElemType elem[MAX_SIZE];
    int front,rear;
}SqQueue;