//
// Created by 15776 on 2021/5/9.
//

#include <cstdio>
#include <malloc.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE]; // 串中字符
    int length; // 串长
} SqString; // 声明顺序串类型

/*-----------------将字符串常量赋给串s--------------------*/
static void str_assign(SqString &s, const char cstr[]) {
    int i;

    for (i = 0; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

/*-----------------销毁串--------------------*/
static void destroy_str(SqString &s) {
}

/*-----------------输出串s--------------------*/
static void disp_str(SqString s) {
    int i;

    if (s.length > 0) {
        for (i = 0; i < s.length; i++)
            printf("%c", s.data[i]);
        printf("\n");
    }
}

/**
* ? 采用BF模式匹配(简单模式匹配)算法思路:
* ? ? ? 先给最长重复子串的下标index和长度length均赋值为0。设s="s(下标0)s(下标1)...s(下标n-1)"，
* ? 扫描通过串s，对于当前字符s(下标i)，判断其后是否有相同的字符，若有标记为s(下标j)，再判断
* ? s(下标i+1)是否等于s(下标j+1)，s(下标i+2)是否等于s(下标j+2)，...，依次类推，一直找到一个不同
* ? 的字符为止，也就是查找到了一个重复出现的子串，把其下标index(实际上为i)与长度length1记录下来，
* ? 将length1与length相比较，保留较长的子串index和length。再从s(下标j+length1)之后找重复子串。
* ? 然后对于s(下标i+1)之后的字符采用上述过程，直到s扫描完毕。最后的index与length为记录下最长
* ? 重复子串的下标与长度。
*/
static SqString *max_sub_str(SqString s) {
    SqString *subs;
    int index = 0; // 最长重复子串的下标
    int length = 0; // 最长重复子串的长度
    int i = 0, j, k;
    int length1;

    while (i < s.length) {
        j = i + 1;
        while (j < s.length) {
            if (s.data[i] == s.data[j]) // 找一子串,其序号为i,长度为length1
            {
                length1 = 1;
                for (k = 1; s.data[i + k] == s.data[j + k]; k++)
                    length1++;
                if (length1 > length) // 将较大长度者赋给index与length
                {
                    index = i;
                    length = length1;
                }
                j += length1;
            } else
                j++;
        }
        i++; // 继续扫描第i字符之后的字符
    }

    subs = (SqString *) malloc(sizeof(SqString));
    subs->length = length;
    for (i = 0; i < length; i++) // 将最长重复子串复制到subs中
        subs->data[i] = s.data[index + i];

    return subs;
}

int main() {
    char str[MAX_SIZE];
    SqString s, *subs;

    printf("输入串:");
    gets(str);
    str_assign(s, str); // 创建串s
    subs = max_sub_str(s);
    printf("求最长重复子串:\n");
    printf(" ? ?原串:");
    disp_str(s);
    printf(" ?最长重复子串:"); // 输出最长重复子串
    disp_str(*subs);
    destroy_str(s);
    free(subs);

    return 0;
}