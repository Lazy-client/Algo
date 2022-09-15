//
// Created by 15776 on 2021/4/10.
//main.cpp 主函数所在文件
#include "iostream"
#include "Double.cpp"
using namespace std;
int main()
{
    DoubleNode* head;
    char list[]= {'a', 'b', 'c', 'd', 'e'};
    createList(head, list, 5);
    displayList(head);
    cout << "长度为" << listLength(head) << endl;
    ElementType e;
    getElem(head, 3, e);

    cout<<"第3个元素是"<<e<<endl;
    cout << "元素a的位置" << locateElem(head, 'a') << endl;
    listInsert(head, 4, 'f');
    displayList(head);
    listDelete(head, 3);
    displayList(head);
    free(head);
    return 0;
}