//
// Created by 15776 on 2021/4/24.
//

#include<stdio.h>
# define M 5 //��������
# define N 5 //��������
# define MaxSize 100 //ջ���Ԫ�ظ���
int mg[M+2][N+2]=//һ���Թ����飨M+2�У�N+2�У�,���ܼ��Ͼ�Ϊ1����߿�0��ʾ������
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
    int i,j;//��ǰ������кź��к�
    int di;//��ʾ��һ�������ڷ�λ�ķ�λ��
}St[MaxSize],Path[MaxSize];//����ջ�ʹ�����·�������飬(�ṹ�������������Ա�ñ�����+��.������)
int top=-1;//ջ��ָ�� ����ʼֵ��Ϊ-1����ʾ��
int count=1;//·��������
int minlen=MaxSize; //���·������

void dispapath()//���һ��·���������·��
{
    int k;
    printf("·��%d:",count++);//�����count��·��
    for(k=0;k<=top;k++)//ѭ�����һ��·��
    {
        printf("(%d,%d)",St[k].i,St[k].j);//��ջ�е�Ԫ�����
        if((k+1)%5==0)//ÿ������黻һ��
            printf("\n      ");
    }
    printf("\n");
    if(top+1<minlen)//�Ƚ��ҳ����·��
    {
        for(k=0;k<=top;k++)
            Path[k]=St[k];//�����·����ŵ�Path��
        minlen=top+1;//�����·����ŵ�minlen��
    }
}
void dispminpath()//�����һ�����·��
{
    printf("���·��:");
    for(int k=0;k<minlen;k++)
    {
        printf("(%d,%d)",St[k].i,St[k].j);
        if((k+1)%5==0) printf("\n \t ");//ÿ������黻һ��
    }
    printf("\n");
    printf("���·�����ȣ�%d\n",minlen);
}
void mgpath( int xi,int yi,int xe,int ye) //(xi,yi)��ʾ���,(xe,ye)��ʾ����
{
    int i,j,i1,j1,di;
    bool find;
    top++;//��ջ
    St[top].i=xi;St[top].j=yi;
    St[top].di=-1;
    mg[xi][yi]=-1;//��ʼ�����ջ ��mg[xi][yi]=-1��Ϊ�˱����ߵ��˷���
    while(top>-1) //ջ����ʱѭ��
    {
        i=St[top].i;
        j=St[top].j;
        di=St[top].di;//ȡջ������
        if(i==xe&&j==ye)//�ҵ��˳��ڣ����·��
        {
            dispapath();//���·��
            mg[i][j]=0;//�ó��ڱ�Ϊ����·�����߷���
            top--;//������ջ��������һ������
            i=St[top].i;
            j=St[top].j;
            di=St[top].di;//��ջ�������Ϊ��ǰ����
        }
        find=false;
        while(di<4&&!find)//�ӵ�ǰ�����������������ڿ��߷���
        {
            di++;
            switch(di)
            {
                case 0:i1=i-1;j1=j;break;
                case 1:i1=i;j1=j+1;break;
                case 2:i1=i+1;j1=j;break;
                case 3:i1=i;j1=j-1;break;
            }
            if(mg[i1][j1]==0) find=true;//�ҵ�һ�����ڿ��ߵķ���
        }
        if(find==true)//�ҵ���һ�����ڵĿ��߷���
        {
            St[top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
            top++;
            St[top].i=i1;
            St[top].j=j1; //��һ�����߷���(i1,j1)��ջ
            St[top].di=-1;
            mg[i][j]=-1;//�Թ�λ��Ϊ-1�����ظ��ߵ��÷���
        }
        else//û��·�����ߣ����ջ
        {
            mg[i][j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
            top--;
        }
    }
    dispminpath();//���㷨���������·��
}

int main()
{
    mgpath(1,1,M,N);
    return 1;
}
