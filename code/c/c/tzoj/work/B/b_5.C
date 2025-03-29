// 数据结构-表达式转换I
// 时间限制(普通/Java):1000MS/10000MS 内存限制:65536KByte
// 描述

// 算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。日常使用的算术表达式是采用中缀表示法，即二元运算符位于两个运算数中间，如1+2*(3-4)。请设计程序将中缀表达式转换为后缀表达式。

// 输入

// 输入数据有多组，每组一行中给出不含空格的中缀表达式，可包含+、-、*、/以及左右括号（），表达式不超过20个字符。

// 表达式中的操作数均在0~9之间，如不存在11-12这样的表达式，但允许1-2这样的表达式存在。

// 输出

// 每组输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。

// 样例输入
// 1+2
// 1+2*(3-4)

// 样例输出
// 1 2 +
// 1 2 3 4 - * +

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *base;
    int top;
    int size;
} Stack;

void initStack(Stack *s, int size)
{
    s->base = (char *)malloc(sizeof(char) * size);
    s->top = -1;
    s->size = size;
}
void f(Stack *s)
{
}
void Printf();
int main()
{
    Stack s;
    int size = 20, i = -1;
    char c[20];
    initStack(&s, size);
    gets(c);
    while (c[++i] != 0)
    {
        if (c[i] <= '9' && c[i >= '0'])
        {
            printf("%c", c[i]);
        }
        else
        {
            f(&s);
        }
        Printf();
    }
}