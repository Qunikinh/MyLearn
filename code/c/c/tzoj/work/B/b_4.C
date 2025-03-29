// 1219:数据结构练习题――括号匹配

// 描述
// 给定一字符串，判断字符串中的括号是否匹配，这里括号分为大括号{}、中括号[]，圆括号()三种类型。每行字符串最大不超过1000个。
// 输入
// 输入数据分多组，第一行输入数据的组数n，接下来的n行，每行为需要判断的字符串。
// 输出
// 输出匹配情况：

// （1）如果字符串中的应匹配的左括号和右括号不是同一类型，输出wrong
// （2）如果不是（1）的情况，假如某个右括号没有应匹配的左括号，输出miss left
// （3）如果不是（1）的情况，假如某个左括号没有应匹配的右括号，输出miss right
// （4）如果完全匹配，输出match
// 注意：如果（2）和（3）情况同时出现，输出从字符串左边到右边最先出现的情况。

// 样例输入
// 3
// (123)
// {[(234}))
// {123
// 样例输出
// match
// wrong
// miss right

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

void push(Stack *s, char c)
{
    if (s->top < s->size - 1)
    {
        s->base[++s->top] = c;
    }
}

char pop(Stack *s)
{
    if (s->top >= 0)
    {
        return s->base[s->top--];
    }
    return '\0';
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int main()
{
    int n, i, j;
    char cmd[1001];
    scanf("%d", &n);
    getchar(); // 消耗换行符

    for (i = 0; i < n; i++)
    {
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0'; // 去除换行符

        Stack s;
        initStack(&s, 1001);

        int wrong = 0, miss_left = 0, miss_right = 0;

        for (j = 0; cmd[j] != '\0'; j++)
        {
            if (cmd[j] == '(' || cmd[j] == '[' || cmd[j] == '{')
            {
                push(&s, cmd[j]);
            }
            else if (cmd[j] == ')' || cmd[j] == ']' || cmd[j] == '}')
            {
                if (isEmpty(&s))
                {
                    miss_left = 1;
                    break;
                }
                else
                {
                    char top = pop(&s);
                    if ((cmd[j] == ')' && top != '(') ||
                        (cmd[j] == ']' && top != '[') ||
                        (cmd[j] == '}' && top != '{'))
                    {
                        wrong = 1;
                        break;
                    }
                }
            }
        }

        if (wrong)
        {
            printf("wrong\n");
        }
        else if (miss_left)
        {
            printf("miss left\n");
        }
        else if (!isEmpty(&s))
        {
            printf("miss right\n");
        }
        else
        {
            printf("match\n");
        }

        free(s.base);
    }

    return 0;
}