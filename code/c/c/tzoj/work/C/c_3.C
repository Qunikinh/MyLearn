// 快速模式匹配（KMP）
// 样例输入
// ababc
// abc

// 样例输出
// 2

#include <string.h>
void Next(char *t, int *next)
{
    next[0] = -1;
    int i = 0, k = -1;
    while (t[i] != '\0')
    {
        if (k == -1 || t[i] == t[k])
            next[++i] = ++k;
        else
            k = next[k];
    }
}
int strstr(char *s, char *t)
{
    int next[100001];
    Next(t, next);
    int i = 0, j = 0;
    int lenS = strlen(s), lenT = strlen(t);
    while (i < lenS && j < lenT)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= lenT)
        return i - lenT;
    return -1;
}
#include <stdio.h>
int main()
{
    char s[100001], t[100001];
    scanf("%s%s", s, t);
    printf("%d\n", strstr(s, t));
    return 0;
}