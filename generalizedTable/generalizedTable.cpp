/**
* 实验题目:
* 实现广义表的基本运算
* 实验目的:
* 领会广义表的链式存储结构及其基本算法设计
* 实验内容:
* 实现广义表的各种运算，设计一个程序，实现如下功能:
* 1、建立广义表g = "(b,(b,a,(#),d),((a,b),c,((#))))"的链式存储结构
* 2、输出广义表g的长度
* 3、输出广义表g的深度
* 4、输出广义表g的最大原子
*/

#include <cstdio>
#include <malloc.h>
typedef struct lnode {
    int tag;
    union {
        char data;
        struct lnode *sublist;
    } val;
    struct lnode *link;
} GLNode;

/*---------------返回由括号表示法表示s的广义表链式存储结构(递归方法)----------------*/
static GLNode *create_gl(char *&s) {
    GLNode *g;
    char ch = *s++;

    if (ch != '\0')
    {
        g = (GLNode *) malloc(sizeof(GLNode));
        if (ch == '(')
        {
            g->tag = 1;
            g->val.sublist = create_gl(s);
        } else if (ch == ')')
        {
            g = nullptr;
        } else if (ch == '#')
        {
            g->val.sublist = nullptr;
        } else // 为原子字符
        {
            g->tag = 0;
            g->val.data = ch;
        }
    } else // 串结束,g设置为空
    {
        g = nullptr;
    }

    ch = *s++;
    if (g != nullptr)
    {
        if (ch == ',')
        {
            g->link = create_gl(s);
        } else
        {
            g->link = nullptr;
        }
    }

    return g;
}

/*---------------输出广义表g----------------*/
static void disp_gl(GLNode *g) {
    if (g != nullptr)
    {
        if (g->tag == 0)
            printf("%c", g->val.data);
        else // g的元素为子表时
        {
            printf("(");
            if (g->val.sublist == nullptr)
                printf("#");
            else // 为非空子表时
                disp_gl(g->val.sublist);
            printf(")");
        }
        if (g->link != nullptr) {
            printf(",");
            disp_gl(g->link);
        }
    }
}

/*---------------求广义表g的长度----------------*/
static int gl_length(GLNode *g) {
    int n = 0;
    g = g->val.sublist;
    while (g != nullptr) {
        n++;/*---------------求广义表g的最大原子----------------*/
        g = g->link;
    }
    return n;
}
/*---------------求广义表g的深度----------------*/
static int gl_depth(GLNode *g) {
    int max_dep = 0;
    int dep;
    if (g->tag == 0)
        return 0;
    g = g->val.sublist;
    if (g == nullptr)
        return 1;
    while (g != nullptr)
    {
        if (g->tag == 1)
        {
            dep = gl_depth(g);
            if (dep > max_dep)
                max_dep = dep;
        }
        g = g->link;
    }
    return (max_dep + 1);
}

/*---------------求广义表g的最大原子----------------*/
static char gl_max_atom(GLNode *g) {
    char max1, max2;

    if (g != nullptr) {
        if (g->tag == 0) {
            max1 = gl_max_atom(g->link);
            return (g->val.data > max1 ? g->val.data : max1);
        } else {
            max1 = gl_max_atom(g->val.sublist);
            max2 = gl_max_atom(g->link);
            return (max1 > max2 ? max1 : max2);
        }
    } else
        return 0;
}

/*---------------销毁广义表g----------------*/
static void destroy_gl(GLNode *&g) {
    GLNode *g1, *g2;

    g1 = g->val.sublist;
    while (g1 != nullptr)
    {
        if (g1->tag == 0)
        {
            g2 = g1->link;
            free(g1);
            g1 = g2;
        } else
        {
            g2 = g1->link;
            destroy_gl(g1);
            g1 = g2;
        }
    }
    free(g); // 释放头结点空间
}

int main() {
    GLNode *g;
    char *str = "(b,(b,a,(#),d),((a,b),c,((#))))";

    g = create_gl(str);
    printf("广义表g:");
    disp_gl(g);
    printf("\n");
    printf("广义表g的长度:%d\n", gl_length(g));
    printf("广义表g的深度:%d\n", gl_depth(g));
    printf("广义表g的最大原子:%c\n", gl_max_atom(g));
    destroy_gl(g);
    return 0;
}