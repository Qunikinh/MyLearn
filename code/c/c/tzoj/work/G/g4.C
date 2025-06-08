#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Selection(int a[], int k, int n)
{
    int i, e = k;
    int min = a[k];
    for (i = k; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            e = i;
        }
    }
    int tmp;
    tmp = a[k];
    a[k] = a[e];
    a[e] = tmp;
}

// todo--------------------------
void Print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void SelectionSort(int a[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        Selection(a, i, n); // 第i次选择排序
        Print(a, n);        // 打印每次排序后的结果
    }
}
int main()
{
    int n, a[300], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    SelectionSort(a, n);
    return 0;
}