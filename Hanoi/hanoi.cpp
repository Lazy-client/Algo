//
// Created by 15776 on 2021/5/9.
//

#include <iostream>

using namespace std;

//�ݹ鷨
void Hanoi1(int n, char X, char Y, char Z) {


    if (n == 1) {
        printf("\t����%d����Ƭ��%c�ƶ���%c\n", n, X, Z);//�ݹ���ڣ���ֻ��һ����Ƭʱ
    } else {
        Hanoi1(n - 1, X, Z, Y);//��n-1����Ƭ��ͨ��z,��x�ƶ���y
        printf("\t�ѵ�%d����Ƭ��%c�ƶ���%c\n", n, X, Z);//����n����Ƭ����x�ƶ���z
        Hanoi1(n - 1, Y, X, Z);//��n-1����Ƭ��ͨ��x,��y�ƶ���z

    }
}

int main() {
    int n;
    cout << "�������Ӹ���:";
    cin >> n;
    char X = 'x', Y = 'y', Z = 'z';
    cout << "�ݹ鷨����:" << endl;
    Hanoi1(n, X, Y, Z);
    return 0;
}

