#include <stdio.h>

int main()
{
    int t, n, x, i, j;
    int b[10000] = {0};
    scanf("%d %d", &t, &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        int pos = x % t;
        int found = 0;
        int p = 1; //! p的作用是p
        for (j = 0; j < t; j++)
        {
            int cur = (pos + j * j * p) % t;
            if (b[cur] == 0)
            {
                b[cur] = x;
                break;
            }
            cur = (pos - j * j * p) % t;
            if (cur < 0)
            {
                cur += t;
            }

            if (b[cur] == 0)
            {
                b[cur] = x;
                break;
            }
        }
    }
    for (i = 0; i < t; i++)
    {
        if (i)
        {
            printf(" ");
        }
        if (b[i])
        {
            printf("%d", b[i]);
        }
        else
        {
            printf("X");
        }
    }

    return 0;
}