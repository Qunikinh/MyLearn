// 数据结构实验——next数组
// 给定一个字符串，求KMP算法（快速模式匹配）中各个字符对应的next值。
// 字符串各个next值用来表示当子串匹配失败时能够快速找到重新匹配的位置，其值为当前字符的后缀子串与前缀子串的最长公共子串长度。如ABCAC中，第二个A字符的后缀有：A、CA、BCA，前缀有：A，AB，ABC，最长的公共子串是A，因此next值为1。

// 样例输入
// ABACDABABE

// 样例输出
// 0 0 1 0 0 1 2 3 2 0
#include <string.h>
#include <stdio.h>

int main()
{
    char t[101];
    int next[101] = {0};
    next[0] = -1;
    int k = -1, i = 0;
    scanf("%s", t);
    while (t[i] != 0)
    {
        if (k == -1 || t[i] == t[k])
        {
            next[++i] = ++k;
        }
        else
        {
            k = next[k];
        }
    }
    k = 1;
    while (k <= i)
    {
        if (k == 1)
        {
            printf("%d", next[k++]);
        }
        else
        {
            printf(" %d", next[k++]);
        }
    }
}