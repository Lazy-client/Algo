//
// Created by 15776 on 2021/4/10.
//

//DoubleLinkNode.h�ļ�   �ṹ�������ļ�
typedef char ElementType;
typedef struct DoubleNode
{
public:
    ElementType data;
    DoubleNode *prior;
    DoubleNode *next;
}DoubleNode;