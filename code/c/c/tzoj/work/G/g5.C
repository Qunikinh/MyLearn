#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int a[], int start, int mid, int end)
{
    int i, p = start, q = mid + 1;
    int b[100000];
    for (i = 0; i < end - start + 1; i++)
    {
        if (p <= mid && q <= end)
        {
            if (a[p] > a[q])
            {
                b[i] = a[q++];
            }
            else
            {
                b[i] = a[p++];
            }
        }
        else
        {
            if (p > mid)
            {
                b[i] = a[q++];
            }
            else
            {
                b[i] = a[p++];
            }
        }
    }

    for (i = 0; i < end - start + 1; i++)
    {
        a[i + start] = b[i];
    }
}
// todo---------------------------
void mergeSort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
}

int main()
{
    int a[100000], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}