#include <cstdio>
#include "iostream"

using namespace std;
#define MAX_SIZE 100

typedef struct {
    int i; // 行号
    int j; // 列号
} PathType; // 路径元素类型

int path_count = 0; // 路径编号

/*----------------------------求解从(m,n)到目的地(1,1)的路径条数------------------------*/
/**
*  算法思路:
*  设f(m,n)为从(m,n)到(1,1)的路径条数，其递归模型为:
*  1、当m<1或者n<1时，f(m,n)=0
*  2、当m=1并且n=1时，f(m,n)=1
*  3、当m>1或者n>1时，可从(m,n)向下移动一步，对应的路径条数为f(m-1,n)，也可以向右移动一步
*  对应的路径条数为f(m,n-1)。也就是其他情况:f(m,n)=f(m-1,n)+f(m,n-1)
*/
static int path_num(int m, int n) {
    if (m < 1 || n < 1) // 当m<1或者n<1时，f(m,n)=0
        return 0;
    if (m == 1 && n == 1) // 当m=1并且n=1时，f(m,n)=1
        return 1;
    return path_num(m - 1, n) + path_num(m, n - 1); // f(m,n)=f(m-1,n)+f(m,n-1)
}

/*----------------------------输出从(m,n)到目的地(1,1)的所有路径------------------------*/
static void disp_path(int m, int n, PathType path[], int d) {
    if (m < 1 || n < 1) // 当m<1或者n<1时，f(m,n)=0 无路径
        return;
    if (m == 1 && n == 1) // 当m=1并且n=1时，f(m,n)=1 找到目的地,输出一条路径
    {
        d++; // 将当前位置放入path中
        path[d].i = m;
        path[d].j = n;
        printf("路径%d: ", ++path_count);
        for (int k = 0; k <= d; k++)
            printf("(%d,%d) ", path[k].i, path[k].j);
        printf("\n");
    } else // 其他情况 // f(m,n)=f(m-1,n)+f(m,n-1)
    {
        d++; // 将当前位置放入path中
        path[d].i = m;
        path[d].j = n;
        disp_path(m - 1, n, path, d); // 向下走一步
        disp_path(m, n - 1, path, d); // 退回来,向右走一步
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

    printf("m = %d, n = %d的路径条数:%d\n", m, n, path_num(m, n));
    disp_path(m, n, path, d);

    return 0;
}


