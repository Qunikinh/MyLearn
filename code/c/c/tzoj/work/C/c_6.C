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
    k = 0;
    while (k < i)
    {
        if (k == 0)
        {
            printf("%d", next[k++] + 1);
        }
        else
        {
            printf(" %d", next[k++] + 1);
        }
    }
}