//
// Created by 15776 on 2021/4/24.
//

#include <cstdio>
#include "CircleArrayQueue.cpp"
int main()
{
    ElemType e;
    SqQueue *q;
    printf("���ζ��л�����������:\n");
    printf("  (1)��ʼ������q\n");
    initQueue(q);
    printf("  (2)���ν�����Ԫ��a,b,c\n");
    if (!enQueue(q,'a')) printf("\t��ʾ:����,���ܽ���\n");
    if (!enQueue(q,'b')) printf("\t��ʾ:����,���ܽ���\n");
    if (!enQueue(q,'c')) printf("\t��ʾ:����,���ܽ���\n");
    printf("  (3)����Ϊ%s\n",(queueEmpty(q) ? "��" : "�ǿ�"));
    if (deQueue(q,e)==0)
        printf("�ӿ�,���ܳ���\n");
    else
        printf("  (4)����һ��Ԫ��%c\n",e);
    printf("  (5)���ν�����Ԫ��d,e,f\n");
    if (!enQueue(q,'d')) printf("\t��ʾ:����,���ܽ���\n");
    if (!enQueue(q,'e')) printf("\t��ʾ:����,���ܽ���\n");
    if (!enQueue(q,'f')) printf("\t��ʾ:����,���ܽ���\n");
    printf("  (6)����������:");
    while (!queueEmpty(q))
    {	deQueue(q,e);
        printf("%c ",e);
    }
    printf("\n");
    printf("  (7)�ͷŶ���\n");
    destroyQueue(q);
    return 0;
}
