#include <cstdio>
#include "iostream"

using namespace std;
#define MAX_SIZE 100

typedef struct {
    int i; // �к�
    int j; // �к�
} PathType; // ·��Ԫ������

int path_count = 0; // ·�����

/*----------------------------����(m,n)��Ŀ�ĵ�(1,1)��·������------------------------*/
/**
*  �㷨˼·:
*  ��f(m,n)Ϊ��(m,n)��(1,1)��·����������ݹ�ģ��Ϊ:
*  1����m<1����n<1ʱ��f(m,n)=0
*  2����m=1����n=1ʱ��f(m,n)=1
*  3����m>1����n>1ʱ���ɴ�(m,n)�����ƶ�һ������Ӧ��·������Ϊf(m-1,n)��Ҳ���������ƶ�һ��
*  ��Ӧ��·������Ϊf(m,n-1)��Ҳ�����������:f(m,n)=f(m-1,n)+f(m,n-1)
*/
static int path_num(int m, int n) {
    if (m < 1 || n < 1) // ��m<1����n<1ʱ��f(m,n)=0
        return 0;
    if (m == 1 && n == 1) // ��m=1����n=1ʱ��f(m,n)=1
        return 1;
    return path_num(m - 1, n) + path_num(m, n - 1); // f(m,n)=f(m-1,n)+f(m,n-1)
}

/*----------------------------�����(m,n)��Ŀ�ĵ�(1,1)������·��------------------------*/
static void disp_path(int m, int n, PathType path[], int d) {
    if (m < 1 || n < 1) // ��m<1����n<1ʱ��f(m,n)=0 ��·��
        return;
    if (m == 1 && n == 1) // ��m=1����n=1ʱ��f(m,n)=1 �ҵ�Ŀ�ĵ�,���һ��·��
    {
        d++; // ����ǰλ�÷���path��
        path[d].i = m;
        path[d].j = n;
        printf("·��%d: ", ++path_count);
        for (int k = 0; k <= d; k++)
            printf("(%d,%d) ", path[k].i, path[k].j);
        printf("\n");
    } else // ������� // f(m,n)=f(m-1,n)+f(m,n-1)
    {
        d++; // ����ǰλ�÷���path��
        path[d].i = m;
        path[d].j = n;
        disp_path(m - 1, n, path, d); // ������һ��
        disp_path(m, n - 1, path, d); // �˻���,������һ��
    }
}

int main() {
    int m;
    int n;
    cout << "m=";
    cin >> m;
    cout << "n=";
    cin >> n;

    int d = -1;
    PathType path[MAX_SIZE];

    printf("m = %d, n = %d��·������:%d\n", m, n, path_num(m, n));
    disp_path(m, n, path, d);

    return 0;
}


