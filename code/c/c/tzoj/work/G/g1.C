#include <stdio.h>

int Search(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < m; i++)
    {
        int target;
        scanf("%d", &target);
        int index = Search(arr, n, target);
        if (index != -1)
        {
            printf("%d\n", index + 1);
        }
        else
        {
            printf("None\n");
        }
    }
    return 0;
}