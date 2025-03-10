#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);

    int max_sum = 0;
    int sum = 0;
    long long a[100000];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }

    printf("%d\n", max_sum);
    return 0;
}