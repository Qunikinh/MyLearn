#include <iostream>
#include <cstdio>
using namespace std;

int MinValue(int a[], int n)
{
    int min = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}
int MaxValue(int a[], int n)
{
    int max = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void PutIn(int value, int bias, int bucket[])
{
    bucket[value + bias]++;
}
void TakeOut(int a[], int index, int i, int bias)
{
    a[index] = i - bias;
}

// todo---------------------------------------
void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}
void CountingSort(int a[], int n)
{
    // 分别求出最小值和最大值
    int Min = MinValue(a, n);
    int Max = MaxValue(a, n);
    // 求出偏移量
    int bias = 0 - Min;
    // 设置桶
    int bucket[Max - Min + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        PutIn(a[i], bias, bucket); // 装进桶
    }
    int index = 0, i = 0;
    while (index < n)
    {
        // 桶里有元素取出
        if (bucket[i])
        {
            // 从桶中取出
            TakeOut(a, index, i, bias);
            bucket[i]--;
            index++;
        }
        else
            i++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[300], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    CountingSort(a, n);
    Print(a, n);
    return 0;
}