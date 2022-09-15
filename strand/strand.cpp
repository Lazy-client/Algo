//
// Created by 15776 on 2021/5/9.
//

#include <cstdio>
#include <malloc.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE]; // �����ַ�
    int length; // ����
} SqString; // ����˳������

/*-----------------���ַ�������������s--------------------*/
static void str_assign(SqString &s, const char cstr[]) {
    int i;

    for (i = 0; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

/*-----------------���ٴ�--------------------*/
static void destroy_str(SqString &s) {
}

/*-----------------�����s--------------------*/
static void disp_str(SqString s) {
    int i;

    if (s.length > 0) {
        for (i = 0; i < s.length; i++)
            printf("%c", s.data[i]);
        printf("\n");
    }
}

/**
* ? ����BFģʽƥ��(��ģʽƥ��)�㷨˼·:
* ? ? ? �ȸ���ظ��Ӵ����±�index�ͳ���length����ֵΪ0����s="s(�±�0)s(�±�1)...s(�±�n-1)"��
* ? ɨ��ͨ����s�����ڵ�ǰ�ַ�s(�±�i)���ж�����Ƿ�����ͬ���ַ������б��Ϊs(�±�j)�����ж�
* ? s(�±�i+1)�Ƿ����s(�±�j+1)��s(�±�i+2)�Ƿ����s(�±�j+2)��...���������ƣ�һֱ�ҵ�һ����ͬ
* ? ���ַ�Ϊֹ��Ҳ���ǲ��ҵ���һ���ظ����ֵ��Ӵ��������±�index(ʵ����Ϊi)�볤��length1��¼������
* ? ��length1��length��Ƚϣ������ϳ����Ӵ�index��length���ٴ�s(�±�j+length1)֮�����ظ��Ӵ���
* ? Ȼ�����s(�±�i+1)֮����ַ������������̣�ֱ��sɨ����ϡ�����index��lengthΪ��¼���
* ? �ظ��Ӵ����±��볤�ȡ�
*/
static SqString *max_sub_str(SqString s) {
    SqString *subs;
    int index = 0; // ��ظ��Ӵ����±�
    int length = 0; // ��ظ��Ӵ��ĳ���
    int i = 0, j, k;
    int length1;

    while (i < s.length) {
        j = i + 1;
        while (j < s.length) {
            if (s.data[i] == s.data[j]) // ��һ�Ӵ�,�����Ϊi,����Ϊlength1
            {
                length1 = 1;
                for (k = 1; s.data[i + k] == s.data[j + k]; k++)
                    length1++;
                if (length1 > length) // ���ϴ󳤶��߸���index��length
                {
                    index = i;
                    length = length1;
                }
                j += length1;
            } else
                j++;
        }
        i++; // ����ɨ���i�ַ�֮����ַ�
    }

    subs = (SqString *) malloc(sizeof(SqString));
    subs->length = length;
    for (i = 0; i < length; i++) // ����ظ��Ӵ����Ƶ�subs��
        subs->data[i] = s.data[index + i];

    return subs;
}

int main() {
    char str[MAX_SIZE];
    SqString s, *subs;

    printf("���봮:");
    gets(str);
    str_assign(s, str); // ������s
    subs = max_sub_str(s);
    printf("����ظ��Ӵ�:\n");
    printf(" ? ?ԭ��:");
    disp_str(s);
    printf(" ?��ظ��Ӵ�:"); // �����ظ��Ӵ�
    disp_str(*subs);
    destroy_str(s);
    free(subs);

    return 0;
}