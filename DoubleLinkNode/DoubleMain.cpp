//
// Created by 15776 on 2021/4/10.
//main.cpp �����������ļ�
#include "iostream"
#include "Double.cpp"
using namespace std;
int main()
{
    DoubleNode* head;
    char list[]= {'a', 'b', 'c', 'd', 'e'};
    createList(head, list, 5);
    displayList(head);
    cout << "����Ϊ" << listLength(head) << endl;
    ElementType e;
    getElem(head, 3, e);

    cout<<"��3��Ԫ����"<<e<<endl;
    cout << "Ԫ��a��λ��" << locateElem(head, 'a') << endl;
    listInsert(head, 4, 'f');
    displayList(head);
    listDelete(head, 3);
    displayList(head);
    free(head);
    return 0;
}