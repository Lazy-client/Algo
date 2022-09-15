//
// Created by 15776 on 2021/5/9.
//

#include <cstdio>

int main() {
    char str1[20], str2[20], *p1, *p2;
    int sum = 0;
    printf("请输入二个字符串!\n");
    scanf("%s%s", str1, str2);//字符串输入
    p1 = str1;
    p2 = str2;//指针分别指向两串
    while (*p1 != '\0')//如果没有到结束标记就循环
    {
        if (*p1 == *p2)//如果有相同字符了
        {
            while (*p1 == *p2 && *p2 != '\0')//开始判断
            {
                p1++;
                p2++;
            }
        } else//否则
            p1++;
        if (*p2 == '\0')//如果P2移动到了结束标志
            sum++;//sum加1
        p2 = str2;
    }
    printf("第二个字符串在第一个字符串中出现的次数为%d!", sum);
    getchar();
}
