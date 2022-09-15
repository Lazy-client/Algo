//
// Created by 15776 on 2021/4/10.
//main.cpp 主函数所在文件
#include "Add.cpp"
int main()
{
    Node *h1, *h2, *head;
    char s[MAX_SIZE], t[MAX_SIZE];

    printf("操作步骤:\n");
    printf("   (1)输入整数1: ");
    scanf("%s", s);
    printf("   (2)输入整数2: ");
    scanf("%s", t);

    createList(h1, s, strlen(s));
    createList(h2, t, strlen(t));

    printf("   (3)整数单链表1: ");
    displayList(h1);
    printf("   (4)整数单链表2: ");
    displayList(h2);

    addList(h1, h2, head);
    printf("   (5)结果单链表: ");
    displayList(head);

    reverseList(head);
    printf("   (6)对应的整数: ");
    displayList(head);
    printf("   (7)中间位: %d", midList(head));

    destroyList(head);
    destroyList(h1);
    destroyList(h2);

    return 0;

}
