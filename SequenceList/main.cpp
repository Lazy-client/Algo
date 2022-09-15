#include <iostream>
#include "method.cpp"

using namespace std;

int main() {

    SqList *list;
    char arr[] = {'a', 'b', 'c', 'd', 'e'};

    //1初始化顺序表L
    initSqList(list);

    //2插入元素
    insert(list, arr, sizeof(arr));

    //3输出顺序表
    output(list);
    //4输出顺序表长度
    cout<<"顺序表长度为 : "
        <<getListLength(list)
        <<endl;

    //5判断是否为空
    isNull(list);

    //6输出第三个元素的值
    outputNumberOf(list, 3);

    //7输出 a 元素的位置
    cout << "元素a的索引位置 :"
         << indexOfElement(list, 'a')
         << endl;           //找到a的索引位置

    //8在第四个位置插上f
    insertNumberOf(list, 4, 'f');

    //9输出顺序表
    output(list);

    //10删除第三个位置的元素
    deleteNumberOf(list, 3);

    //11输出顺序表
    output(list);

    //12释放顺序表
    destroySqList(list);




}
