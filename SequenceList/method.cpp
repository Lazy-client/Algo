
#include <iostream>

using namespace std;

#include "SqList.h"

void initSqList(SqList *&L) {
    L = (SqList *) malloc(sizeof(SqList));
    L->length = 0;
}

bool insert(SqList *&L, const char add[], int length) {
    int i = 0;

//    插入的数据长度超过最大容量，就插入失败
    if (length > MAX_LEN)
        return false;


    while (i <= length) {
        L->data[i] = add[i];
        i++;
    }
    L->length = length;
    return true;

}

void output(SqList *L) {
    for (int i = 0; i < L->length; ++i) {
        cout << L->data[i];
    }
    cout << endl;

}

int getListLength(SqList *L) {
    return L->length;
}

bool isNull(SqList *L) {
    if (L == nullptr) {

        cout << "it is NULL" << endl;
        return true;
    }

    cout << "it is not NULL" << endl;
    return false;
}

void outputNumberOf(SqList *L, int n) {

    cout << L->data[n - 1] << endl;
}

int indexOfElement(SqList *L, char e) {
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e)
            return i;
    }

    cout << "not find" << endl;
    return -1;
}

bool insertIndexOf(SqList *&L, int n, char e) {
    int i;
    if (n < 0 || n > L->length)
        return false;

    for (i = L->length - 1; i >= n; i--) {

        L->data[i + 1] = L->data[i];

    }
    L->data[n] = e;
    L->length += 1;
    return true;
}

bool insertNumberOf(SqList *&L, int n, char e) {
    return insertIndexOf(L, n - 1, e);
}

/**
 *
 * @param L
 * @param n 索引位置为n
 * @return  返回是否删除成功
 */
bool deleteIndexOf(SqList *&L, int n) {

    if (n >= L->length || n < 0)
        return false;
    for (int i = n; i <= L->length - 2; i++) {
        L->data[i] = L->data[i + 1];
    }

    L->length -= 1;
    return true;
}

bool deleteNumberOf(SqList *&L, int n) {
    return deleteIndexOf(L, n - 1);
}
/**
 *
 * @param L
 * @return
 */
bool destroySqList(SqList *&L) {
    if (L == nullptr)
        return true;
    free(L);
    return true;
}

/*
void reshapeSqList(SqList *&L){
    int i = 0, j = L->length-1;
    int temp;
    while(i<=j){
        while(L->data[i]<0){
            i++;
        }
        while(L->data[j]>=0){
            j--;
        }
        if(i<j){
            temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = temp;
        }
    }
}*/
