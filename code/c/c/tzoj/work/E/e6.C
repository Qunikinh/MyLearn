
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int Height(int tree[], int n)
{
    int mh = 0, i;
    for (i = 0; i < n; i++)
    {
        if (tree[i] != 0)
        {
            int h = (int)(log2(i + 1)) + 1;
            if (h > mh)
            {
                mh = h;
            }
        }
    }
    return mh;
}
int main()
{
    int tree[512], n = 0;
    int data;
    while (scanf("%d", &data), data != -1)
    {
        tree[n++] = data;
    }
    printf("%d\n", Height(tree, n));
    return 0;
}