//
// Created by 15776 on 2022/5/2.
//
#include<bits/stdc++.h>

using namespace std;

struct node {
    int l, r, w, lazy;//tree��l,r��ʾ��������[l,r],w��ʾ[l,r]�����
} tree[400001];

//lazy!=0�Ǽ�ֵ,lazy!=-1�Ǹ�ֵ

void build(int v, int l, int r)//����,v��ʾtree���v�����,tree����ȫ������
{
    tree[v].l = l;
    tree[v].r = r;
    if (tree[v].l == tree[v].r) {
        scanf("%d", &tree[v].w);
        return;
    }
    int mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    tree[v].w = tree[v * 2].w + tree[v * 2 + 1].w;
}

void downadd(int v)//�����ֵlazy=0 ����´�
{
    tree[v * 2].lazy += tree[v].lazy;
    tree[v * 2 + 1].lazy += tree[v].lazy;
    tree[v * 2].w += tree[v].lazy * (tree[v * 2].r - tree[v * 2].l + 1);
    tree[v * 2 + 1].w += tree[v].lazy * (tree[v * 2 + 1].r - tree[v * 2 + 1].l + 1);
    tree[v].lazy = 0;
}

void downupdate(int v)//�����ֵlazy=-1 ����´�
{
    tree[v * 2].lazy = tree[v].lazy;
    tree[v * 2 + 1].lazy = tree[v].lazy;
    tree[v * 2].w = tree[v].lazy * (tree[v * 2].r - tree[v * 2].l + 1);
    tree[v * 2 + 1].w = tree[v].lazy * (tree[v * 2 + 1].r - tree[v * 2 + 1].l + 1);
    tree[v].lazy = -1;
}


int ask_point(int v, int x)//�����ѯ
{
    if (tree[v].l == tree[v].r) {
        return tree[v].w;
    }

    if (tree[v].lazy != 0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//�����ֵ��-1

    int mid = (tree[v].l + tree[v].r) / 2;
    if (x <= mid) ask_point(v * 2, x);
    else ask_point(v * 2 + 1, x);
}

void change_point(int v, int x, int y)//�����޸�,a[x]��Ϊy(��Ӽ��Ȳ���)
{
    if (tree[v].l == tree[v].r) {
        //tree[k].w+=y;
        tree[v].w = y; //�ҵ���x�����,a[x]=y,Ҳ�ɽ�����������
        return;
    }
    if (tree[v].lazy != 0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//�����ֵ��-1

    int mid = (tree[v].l + tree[v].r) / 2;
    if (x <= mid) change_point(v * 2, x, y);
    else change_point(v * 2 + 1, x, y);

    tree[v].w = tree[v * 2].w + tree[v * 2 + 1].w;
}

int ask_interval(int v, int a, int b)//�����ѯ[a,b]
{
    if (tree[v].l >= a && tree[v].r <= b) {
        return tree[v].w;
    }

    if (tree[v].lazy != 0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//�����ֵ��-1

    int sum = 0;
    int mid = (tree[v].l + tree[v].r) / 2;
    if (a <= mid) sum += ask_interval(v * 2, a, b);
    if (b > mid) sum += ask_interval(v * 2 + 1, a, b);

    return sum;
}

void changeadd_interval(int v, int a, int b, int y)//�����ֵ,[a,b]��������ͬʱ+y
{
    if (tree[v].l >= a && tree[v].r <= b) {
        tree[v].w += (tree[v].r - tree[v].l + 1) * y;
        tree[v].lazy += y;
        return;
    }
    if (tree[v].lazy != 0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//�����ֵ��-1

    int mid = (tree[v].l + tree[v].r) / 2;
    if (a <= mid) changeadd_interval(v * 2, a, b, y);
    if (b > mid) changeadd_interval(v * 2 + 1, a, b, y);

    tree[v].w = tree[v * 2].w + tree[v * 2 + 1].w;
}

void changeupdate_interval(int v, int a, int b, int y)//�����ֵ,[a,b]��������ͬʱ�޸�Ϊy
{
    if (tree[v].l >= a && tree[v].r <= b) {
        tree[v].w = (tree[v].r - tree[v].l + 1) * y;
        tree[v].lazy = y;
        return;
    }
    if (tree[v].lazy != 0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//�����ֵ��-1

    int mid = (tree[v].l + tree[v].r) / 2;
    if (a <= mid) changeupdate_interval(v * 2, a, b, y);
    if (b > mid) changeupdate_interval(v * 2 + 1, a, b, y);

    tree[v].w = tree[v * 2].w + tree[v * 2 + 1].w;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        memset(tree, 0, sizeof(tree));//����ֵ����������0
        //memset(tree,-1,sizeof(tree));//�����ֵ��-1
        scanf("%d", &n);//n���ڵ�
        build(1, 1, n);//����
        scanf("%d", &m);//m�ֲ���
        for (int i = 1; i <= m; i++) {
            int p, x, y, a, b;
            scanf("%d", &p);
            if (p == 1) {
                printf("**************�����ѯ����**************\n");
                scanf("%d", &x);
                printf("%d\n", ask_point(1, x));//�����ѯ,�����x����
            } else if (p == 2) {
                printf("**************�����޸Ĳ���**************\n");
                scanf("%d%d", &x, &y);
                change_point(1, x, y);//�����޸�
            } else if (p == 3) {
                printf("**************�����ѯ����**************\n");
                scanf("%d%d\n", &a, &b);//�����ѯ
                printf("%d\n", ask_interval(1, a, b));//�ӵ�1����㿪ʼ��[a,b]����
            } else if (p == 4) {
                printf("**************�����ֵ����**************\n");
                scanf("%d%d%d", &a, &b, &y);//�����ֵ,[a,b]������y
                changeadd_interval(1, a, b, y);
            } else {
                printf("**************�����ֵ����**************");
                scanf("%d%d%d", &a, &b, &y);//�������,[a,b]��ֵ����Ϊy
                changeupdate_interval(1, a, b, y);
            }
        }
    }
    return 0;
}
