//
// Created by 15776 on 2021/3/22.
//
//main.cpp文件内容 主函数所在文件

#include "LinkNode.cpp"
int main(){

    LinkedNode *node= nullptr;
    char e[]= {'a','b','c','d','e'};

    int len= sizeof(e);

    //初始化链表
    createLinkedNode(node,e,len);
    //顺序打印链表
    outputLink(node);
    //统计链表长度
    cout<<"链表长度为:"<<(count(node))<<endl;
    cout<<"链表是否为空:"<<isEmpty(node)<<endl;
    int n;
    cout<<"输入n=";
    cin>>n;
    cout<<"链表第"<<n<<"个节点数据:";
    printNumberOf(node,n);
    cout<<endl;
    cout<<"a的位置:"<<find(node,'a')<<endl;

    auto *insert = (LinkedNode *) malloc(sizeof(LinkedNode));
    insert->e='f';
    insert->next= nullptr;
    insertNumberOf(node,insert,4);
    cout<<"第四个位置插入f后:"<<endl;
    outputLink(node);

    removeNumberOf(node,3);
    cout<<"移除第三个节点后"<<endl;
    outputLink(node);
    destroyNode(node);
    return 0;
}