//
// Created by 15776 on 2021/4/24.
//

#include<stdio.h>
# define M 5 //定义行数
# define N 5 //定义列数
# define MaxSize 100 //栈最多元素个数
int mg[M+2][N+2]=//一个迷宫数组（M+2行，N+2列）,四周加上均为1的外边框，0表示可以走
        {
                {1,1,1,1,1,1,1},
                {1,0,0,0,0,0,1},
                {1,0,1,1,1,0,1},
                {1,0,1,0,0,0,1},
                {1,0,0,0,1,1,1},
                {1,1,1,0,0,0,1},
                {1,1,1,1,1,1,1}
        };
struct
{
    int i,j;//当前方块的行号和列号
    int di;//表示下一可走相邻方位的方位号
}St[MaxSize],Path[MaxSize];//定义栈和存放最短路径的数组，(结构体变量，变量成员用变量名+“.”引用)
int top=-1;//栈顶指针 ，初始值设为-1，表示空
int count=1;//路径数计数
int minlen=MaxSize; //最短路径长度

void dispapath()//输出一条路径并求最短路径
{
    int k;
    printf("路径%d:",count++);//输出第count条路径
    for(k=0;k<=top;k++)//循环输出一条路径
    {
        printf("(%d,%d)",St[k].i,St[k].j);//将栈中的元素输出
        if((k+1)%5==0)//每五个方块换一行
            printf("\n      ");
    }
    printf("\n");
    if(top+1<minlen)//比较找出最短路径
    {
        for(k=0;k<=top;k++)
            Path[k]=St[k];//将最短路径存放到Path中
        minlen=top+1;//将最短路径存放到minlen中
    }
}
void dispminpath()//输出第一条最短路径
{
    printf("最短路径:");
    for(int k=0;k<minlen;k++)
    {
        printf("(%d,%d)",St[k].i,St[k].j);
        if((k+1)%5==0) printf("\n \t ");//每五个方块换一行
    }
    printf("\n");
    printf("最短路径长度：%d\n",minlen);
}
void mgpath( int xi,int yi,int xe,int ye) //(xi,yi)表示入口,(xe,ye)表示出口
{
    int i,j,i1,j1,di;
    bool find;
    top++;//进栈
    St[top].i=xi;St[top].j=yi;
    St[top].di=-1;
    mg[xi][yi]=-1;//初始方块进栈 ，mg[xi][yi]=-1是为了避免走到此方块
    while(top>-1) //栈不空时循环
    {
        i=St[top].i;
        j=St[top].j;
        di=St[top].di;//取栈顶方块
        if(i==xe&&j==ye)//找到了出口，输出路径
        {
            dispapath();//输出路径
            mg[i][j]=0;//让出口变为其他路径可走方块
            top--;//出口退栈，即回退一个方块
            i=St[top].i;
            j=St[top].j;
            di=St[top].di;//让栈顶方块变为当前方块
        }
        find=false;
        while(di<4&&!find)//从当前方块上下左右找相邻可走方块
        {
            di++;
            switch(di)
            {
                case 0:i1=i-1;j1=j;break;
                case 1:i1=i;j1=j+1;break;
                case 2:i1=i+1;j1=j;break;
                case 3:i1=i;j1=j-1;break;
            }
            if(mg[i1][j1]==0) find=true;//找到一个相邻可走的方块
        }
        if(find==true)//找到了一个相邻的可走方块
        {
            St[top].di=di;//修改原栈顶元素的di值
            top++;
            St[top].i=i1;
            St[top].j=j1; //下一个可走方块(i1,j1)进栈
            St[top].di=-1;
            mg[i][j]=-1;//迷宫位置为-1避免重复走到该方块
        }
        else//没有路径可走，则出栈
        {
            mg[i][j]=0;//让该位置变为其他路径可走方块
            top--;
        }
    }
    dispminpath();//在算法最后输出最短路径
}

int main()
{
    mgpath(1,1,M,N);
    return 1;
}
