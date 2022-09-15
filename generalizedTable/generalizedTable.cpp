/**
* ʵ����Ŀ:
* ʵ�ֹ����Ļ�������
* ʵ��Ŀ��:
* ����������ʽ�洢�ṹ��������㷨���
* ʵ������:
* ʵ�ֹ����ĸ������㣬���һ������ʵ�����¹���:
* 1�����������g = "(b,(b,a,(#),d),((a,b),c,((#))))"����ʽ�洢�ṹ
* 2����������g�ĳ���
* 3����������g�����
* 4����������g�����ԭ��
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

/*---------------���������ű�ʾ����ʾs�Ĺ������ʽ�洢�ṹ(�ݹ鷽��)----------------*/
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
        } else // Ϊԭ���ַ�
        {
            g->tag = 0;
            g->val.data = ch;
        }
    } else // ������,g����Ϊ��
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

/*---------------��������g----------------*/
static void disp_gl(GLNode *g) {
    if (g != nullptr)
    {
        if (g->tag == 0)
            printf("%c", g->val.data);
        else // g��Ԫ��Ϊ�ӱ�ʱ
        {
            printf("(");
            if (g->val.sublist == nullptr)
                printf("#");
            else // Ϊ�ǿ��ӱ�ʱ
                disp_gl(g->val.sublist);
            printf(")");
        }
        if (g->link != nullptr) {
            printf(",");
            disp_gl(g->link);
        }
    }
}

/*---------------������g�ĳ���----------------*/
static int gl_length(GLNode *g) {
    int n = 0;
    g = g->val.sublist;
    while (g != nullptr) {
        n++;/*---------------������g�����ԭ��----------------*/
        g = g->link;
    }
    return n;
}
/*---------------������g�����----------------*/
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

/*---------------������g�����ԭ��----------------*/
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

/*---------------���ٹ����g----------------*/
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
    free(g); // �ͷ�ͷ���ռ�
}

int main() {
    GLNode *g;
    char *str = "(b,(b,a,(#),d),((a,b),c,((#))))";

    g = create_gl(str);
    printf("�����g:");
    disp_gl(g);
    printf("\n");
    printf("�����g�ĳ���:%d\n", gl_length(g));
    printf("�����g�����:%d\n", gl_depth(g));
    printf("�����g�����ԭ��:%c\n", gl_max_atom(g));
    destroy_gl(g);
    return 0;
}