//
// Created by 15776 on 2021/4/24.
//

#include <cstdio>
#include "CircleArrayQueue.cpp"
int main()
{
    ElemType e;
    SqQueue *q;
    printf("环形队列基本运算如下:\n");
    printf("  (1)初始化队列q\n");
    initQueue(q);
    printf("  (2)依次进队列元素a,b,c\n");
    if (!enQueue(q,'a')) printf("\t提示:队满,不能进队\n");
    if (!enQueue(q,'b')) printf("\t提示:队满,不能进队\n");
    if (!enQueue(q,'c')) printf("\t提示:队满,不能进队\n");
    printf("  (3)队列为%s\n",(queueEmpty(q) ? "空" : "非空"));
    if (deQueue(q,e)==0)
        printf("队空,不能出队\n");
    else
        printf("  (4)出队一个元素%c\n",e);
    printf("  (5)依次进队列元素d,e,f\n");
    if (!enQueue(q,'d')) printf("\t提示:队满,不能进队\n");
    if (!enQueue(q,'e')) printf("\t提示:队满,不能进队\n");
    if (!enQueue(q,'f')) printf("\t提示:队满,不能进队\n");
    printf("  (6)出队列序列:");
    while (!queueEmpty(q))
    {	deQueue(q,e);
        printf("%c ",e);
    }
    printf("\n");
    printf("  (7)释放队列\n");
    destroyQueue(q);
    return 0;
}
