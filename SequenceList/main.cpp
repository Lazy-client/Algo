#include <iostream>
#include "method.cpp"

using namespace std;

int main() {

    SqList *list;
    char arr[] = {'a', 'b', 'c', 'd', 'e'};

    //1��ʼ��˳���L
    initSqList(list);

    //2����Ԫ��
    insert(list, arr, sizeof(arr));

    //3���˳���
    output(list);
    //4���˳�����
    cout<<"˳�����Ϊ : "
        <<getListLength(list)
        <<endl;

    //5�ж��Ƿ�Ϊ��
    isNull(list);

    //6���������Ԫ�ص�ֵ
    outputNumberOf(list, 3);

    //7��� a Ԫ�ص�λ��
    cout << "Ԫ��a������λ�� :"
         << indexOfElement(list, 'a')
         << endl;           //�ҵ�a������λ��

    //8�ڵ��ĸ�λ�ò���f
    insertNumberOf(list, 4, 'f');

    //9���˳���
    output(list);

    //10ɾ��������λ�õ�Ԫ��
    deleteNumberOf(list, 3);

    //11���˳���
    output(list);

    //12�ͷ�˳���
    destroySqList(list);




}
