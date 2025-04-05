// 简单串模式匹配
// 样例输入
// ababc
// abc

// 样例输出
// 2
#include <stdio.h>

int strstr(char *s, char *t)
{
    int i = 0, j = 0;
    while (s[i] != 0 && t[j] != 0)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (t[j] == 0)
    {
        i = i - j;
        return i;
    }
    else
    {
        return -1;
    }
}
// todo-----------------------------------------

int strstr(char *s, char *t);
int main()
{
    char s[101], t[101];
    scanf("%s%s", s, t);
    printf("%d\n", strstr(s, t));
    return 0;
}