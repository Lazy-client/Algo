//
// Created by 15776 on 2021/4/10.
//main.cpp �����������ļ�
#include "Add.cpp"
int main()
{
    Node *h1, *h2, *head;
    char s[MAX_SIZE], t[MAX_SIZE];

    printf("��������:\n");
    printf("   (1)��������1: ");
    scanf("%s", s);
    printf("   (2)��������2: ");
    scanf("%s", t);

    createList(h1, s, strlen(s));
    createList(h2, t, strlen(t));

    printf("   (3)����������1: ");
    displayList(h1);
    printf("   (4)����������2: ");
    displayList(h2);

    addList(h1, h2, head);
    printf("   (5)���������: ");
    displayList(head);

    reverseList(head);
    printf("   (6)��Ӧ������: ");
    displayList(head);
    printf("   (7)�м�λ: %d", midList(head));

    destroyList(head);
    destroyList(h1);
    destroyList(h2);

    return 0;

}
