// 4770: 栈操作
// 栈元素均为整数。栈的最大元素个数为1000。

// 输入各个命令，它们对应的格式如下：
// 压入堆栈：push a，a代表压入堆栈的元素，这里push和元素之间用空格分隔。
// 清空堆栈：clear
// 获取栈顶元素：top
// 弹出栈顶元素：pop
// 当输入的命令为exit时，程序结束。

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int Elemtype;
typedef struct b_2
{
    Elemtype *base;
    int top = -1;
    int size = 1000;
} b_2;

int main()
{
    b_2 s;
    char cmd[10];
    int a;
    s.base = (Elemtype *)malloc(sizeof(Elemtype) * s.size);
    while (scanf("%s", cmd) != EOF)
    {
        if (strcmp(cmd, "push") == 0)
        {
            scanf("%d", &a);
            if (s.top >= s.size)
                continue;
            s.base[++s.top] = a;
        }
        else if (strcmp(cmd, "clear") == 0)
            s.top = -1;
        else if (strcmp(cmd, "top") == 0)
        {
            if (s.top == -1)
            {
                printf("None\n");
                continue;
            }
            printf("%d\n", s.base[s.top]);
        }
        else if (strcmp(cmd, "pop") == 0)
        {
            if (s.top == -1)
            {
                printf("None\n");
                continue;
            }
            printf("%d\n", s.base[s.top--]);
        }
        else
        {
            free(s.base);
            break;
        }
    }
}