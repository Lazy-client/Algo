//
// Created by 15776 on 2022/5/5.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int g[N][N];//�洢ͼ
int dt[N];//�洢�����ڵ㵽�������ľ���
int st[N];//�ڵ��Ƿ񱻼��뵽��������
int pre[N];//�ڵ��ǰȥ�ڵ�
int n, m;//n ���ڵ㣬m ����

void prim()
{
    memset(dt,0x3f, sizeof(dt));//��ʼ����������Ϊһ���ܴ������10�����ң�
    int res= 0;
    dt[1] = 0;//�� 1 �Žڵ㿪ʼ����
    for(int i = 0; i < n; i++)//ÿ��ѭ��ѡ��һ������뵽������
    {
        int t = -1;
        for(int j = 1; j <= n; j++)//ÿ���ڵ�һ���ж�
        {
            if(!st[j] && (t == -1 || dt[j] < dt[t]))//���û�������У��ҵ����ľ�����̣���ѡ��õ�
                t = j;
        }

        st[t] = 1;// ѡ��õ�
        res += dt[t];
        for(int i = 1; i <= n; i++)//������������ĵ㵽�������ľ���
        {
            if(dt[i] > g[t][i] && !st[i])//�� t ���ڵ� i �ľ���С��ԭ�����룬����¡�
            {
                dt[i] = g[t][i];//���¾���
                pre[i] = t;//�� t �� i �ľ�����̣�i ��ǰ����Ϊ t.
            }
        }
    }
}

void getPath()//���������
{
    for(int i = n; i > 1; i--)//n ���ڵ㣬������ n-1 ���ߡ�

    {
        cout << i <<" " << pre[i] << " "<< endl;// i �ǽڵ��ţ�pre[i] �� i �ڵ��ǰ���ڵ㡣���ǹ���һ���ߡ�
    }
}

int main()
{
    memset(g, 0x3f, sizeof(g));//������֮��ľ����ʼ���ɺܴ����
    cin >> n >> m;//����ڵ����ͱ���
    while(m --)
    {
        int a, b, w;
        cin >> a >> b >> w;//����ߵ����������Ȩ��
        g[a][b] = g[b][a] = min(g[a][b],w);//�洢Ȩ��
    }

    prim();//������������
    //getPath();//���·��
    return 0;
}

