#include <stdio.h>
#include <stdlib.h>
int main()
{
    int h[21][21] = {0};
    int c, i, j, n;
    int x, y, d;
    for (c = 0; c < 2; c++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x, &y, &d);
            h[x][y] += d;
        }
    }
    for (x = 0; x <= 20; x++)
    {
        for (y = 0; y <= 20; y++)
        {
            if (h[x][y] == 0)
            {
                continue;
            }
            else
            {
                printf("%d %d %d\n", x, y, h[x][y]);
            }
        }
    }
}