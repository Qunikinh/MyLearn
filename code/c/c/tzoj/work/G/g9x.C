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
        for (j = 0; j < t; j++)
        {
            int cur = (pos + j * j) % t;
            if (b[cur] == 0)
            {
                printf("%d\n", cur);
                b[cur] = 1;
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Error\n");
    }
    return 0;
}