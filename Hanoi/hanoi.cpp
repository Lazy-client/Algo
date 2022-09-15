//
// Created by 15776 on 2021/5/9.
//

#include <iostream>

using namespace std;

//递归法
void Hanoi1(int n, char X, char Y, char Z) {


    if (n == 1) {
        printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);//递归出口，当只有一个盘片时
    } else {
        Hanoi1(n - 1, X, Z, Y);//将n-1个盘片，通过z,从x移动到y
        printf("\t把第%d个盘片从%c移动到%c\n", n, X, Z);//将第n个盘片，从x移动到z
        Hanoi1(n - 1, Y, X, Z);//将n-1个盘片，通过x,从y移动到z

    }
}

int main() {
    int n;
    cout << "输入盘子个数:";
    cin >> n;
    char X = 'x', Y = 'y', Z = 'z';
    cout << "递归法过程:" << endl;
    Hanoi1(n, X, Y, Z);
    return 0;
}

