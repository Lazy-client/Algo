//
// Created by 15776 on 2021/3/22.
//
//main.cpp�ļ����� �����������ļ�

#include "LinkNode.cpp"
int main(){

    LinkedNode *node= nullptr;
    char e[]= {'a','b','c','d','e'};

    int len= sizeof(e);

    //��ʼ������
    createLinkedNode(node,e,len);
    //˳���ӡ����
    outputLink(node);
    //ͳ��������
    cout<<"������Ϊ:"<<(count(node))<<endl;
    cout<<"�����Ƿ�Ϊ��:"<<isEmpty(node)<<endl;
    int n;
    cout<<"����n=";
    cin>>n;
    cout<<"�����"<<n<<"���ڵ�����:";
    printNumberOf(node,n);
    cout<<endl;
    cout<<"a��λ��:"<<find(node,'a')<<endl;

    auto *insert = (LinkedNode *) malloc(sizeof(LinkedNode));
    insert->e='f';
    insert->next= nullptr;
    insertNumberOf(node,insert,4);
    cout<<"���ĸ�λ�ò���f��:"<<endl;
    outputLink(node);

    removeNumberOf(node,3);
    cout<<"�Ƴ��������ڵ��"<<endl;
    outputLink(node);
    destroyNode(node);
    return 0;
}