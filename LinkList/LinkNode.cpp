//
// Created by 15776 on 2021/3/22.
//
//LinkNode.cpp文件 函数所在文件
#include <iostream>
#include <cstdlib>
#include "LinkNode.h"

using namespace std;

void createLinkedNode(LinkedNode *&node, const char e[], int length) {
    LinkedNode *s, *head;
    node = (LinkedNode *) malloc(sizeof(LinkedNode));

    head = node;
    node->next = nullptr;
    for (int i = 0; i < length; ++i) {
        s = (LinkedNode *) malloc(sizeof(LinkedNode));
        s->e = e[i];

        node->next = s;
        node = s;
    }

    node->next = nullptr;
    node = head->next;
    free(head);

}

void outputLink(LinkedNode *node) {

    if (node == nullptr)
        return;
    while (node->next != nullptr) {
        cout << node->e << " ";
        node = node->next;
    }
    cout << node->e << endl;

}

bool destroyNode(LinkedNode *&node) {

    if (node == nullptr) {
        cout << "链表已为空" << endl;
        return true;
    }
    LinkedNode *pre, *next;
    pre = node;
    next = node->next;
    while (next != nullptr) {
        free(pre);
        pre = next;
        next = next->next;
    }

    free(pre);
    free(node);
    return true;

}

int count(LinkedNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int count = 1;
    while (node->next != nullptr) {
        count++;
        node = node->next;
    }

    return count;
}

bool isEmpty(LinkedNode *node) {
    return count(node) == 0;
}

void printNumberOf(LinkedNode *node, int n) {
    int size = count(node);
    if (size < n)
        return;
    int count = 1;
    while (count < n) {
        count++;
        node = node->next;
    }
    cout << node->e << endl;

}

int find(LinkedNode *node, char data) {

    if (isEmpty(node)) {
        return -1;
    }

    int count = 1;

    bool isFind = false;
    while (true) {
        if (node->e == data) {
            isFind = true;
            break;
        }
        if (node->next == nullptr) {
            break;
        }

        count++;
        node = node->next;

    }
    if (isFind) {
        return count;
    }


    return -1;
}

void insertNumberOf(LinkedNode *&node, LinkedNode *insert, int n) {

    if (count(node) < n || n <= 0)
        return;
    LinkedNode *temp = node;
    int count = 1;
    while (count < n - 1) {

        count++;
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;

}

void removeNumberOf(LinkedNode *&node, int n) {
    if (count(node) < n || n <= 0)
        return;
    LinkedNode *temp = node;
    int count = 1;
    while (count < n - 1) {
        count++;
        temp = temp->next;
    }
    LinkedNode *next = temp->next;
    temp->next=next->next;
    next->next= nullptr;
    free(next);
}