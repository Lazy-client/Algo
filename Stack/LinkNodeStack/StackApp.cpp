//
// Created by 15776 on 2021/4/24.
// main方法所在文件
#include <cstdio>
#include "NodeStack.cpp"
int main()
{
    ElemType e;
    NodeStack *s;
    printf("栈s的基本运算如下:\n");
    printf("  (1)初始化栈s\n");
    initStack(s);
    printf("  (2)栈为%s\n",(stackEmpty(s) ? "空" : "非空"));
    printf("  (3)依次进栈元素a,b,c,d,e\n");
    push(s, 'a');
    push(s, 'b');
    push(s, 'c');
    push(s, 'd');
    push(s, 'e');
    printf("  (4)栈为%s\n",(stackEmpty(s) ? "空" : "非空"));
    printf("  (5)出栈序列:");
    while (!stackEmpty(s))
    {
        pop(s, e);
        printf("%c ",e);
    }
    printf("\n");
    printf("  (6)栈为%s\n",(stackEmpty(s) ? "空" : "非空"));
    printf("  (7)释放栈\n");
    destroyStack(s);
    return 0;
}
