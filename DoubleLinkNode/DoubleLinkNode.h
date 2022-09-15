//
// Created by 15776 on 2021/4/10.
//

//DoubleLinkNode.h文件   结构体所在文件
typedef char ElementType;
typedef struct DoubleNode
{
public:
    ElementType data;
    DoubleNode *prior;
    DoubleNode *next;
}DoubleNode;