//
// Created by 15776 on 2021/4/24.
// main���������ļ�
#include <cstdio>
#include "NodeStack.cpp"
int main()
{
    ElemType e;
    NodeStack *s;
    printf("ջs�Ļ�����������:\n");
    printf("  (1)��ʼ��ջs\n");
    initStack(s);
    printf("  (2)ջΪ%s\n",(stackEmpty(s) ? "��" : "�ǿ�"));
    printf("  (3)���ν�ջԪ��a,b,c,d,e\n");
    push(s, 'a');
    push(s, 'b');
    push(s, 'c');
    push(s, 'd');
    push(s, 'e');
    printf("  (4)ջΪ%s\n",(stackEmpty(s) ? "��" : "�ǿ�"));
    printf("  (5)��ջ����:");
    while (!stackEmpty(s))
    {
        pop(s, e);
        printf("%c ",e);
    }
    printf("\n");
    printf("  (6)ջΪ%s\n",(stackEmpty(s) ? "��" : "�ǿ�"));
    printf("  (7)�ͷ�ջ\n");
    destroyStack(s);
    return 0;
}
