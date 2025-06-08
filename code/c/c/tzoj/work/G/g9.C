#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, n, i, x;
    int h[10000], b[10000] = {0};
    scanf("%d %d", &t, &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        x = x % t;
        if (b[x] == 0)
        {
            printf("%d\n", x);
            b[x] = 1;
        }
        else
        {
            int p = 1;
            while (x < t)
            {
                x += p * p;
                p++;
                if (b[x] == 0)
                {
                    printf("%d\n", x);
                    b[x] = 1;
                    break;
                }
            }
            if (x >= t)
            {
                printf("Error");
            }
        }
    }
}