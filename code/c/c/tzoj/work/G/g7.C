#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *InsertSort(Node *head, int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        if (head->data > value)
        {
            p->next = head;
            head = p;
        }
        else
        {
            Node *q = head;
            while (q->next != NULL)
            {
                if (q->next->data < value)
                {
                    q = q->next;
                }
                else
                {
                    break;
                }
            }
            p->next = q->next;
            q->next = p;
        }
    }
    return head;
}

void Merge(Node **buckets, int NUM, int a[])
{
    int i, j = 0;
    for (i = 0; i < NUM; i++)
    {
        Node *p = buckets[i];
        while (p != NULL)
        {
            a[j++] = p->data;
            Node *q = p;
            p = p->next;
            free(q);
        }
    }
}
// todo----------------------------------------------
void BucketSort(int a[], int n)
{
    int i, j, mx = -10000000, mn = 10000000;
    for (i = 0; i < n; i++)
    {
        if (a[i] > mx)
            mx = a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    // 计算桶数量
    int LEN = 100; // 每100个数为一个桶
    int NUM = (mx - mn) / LEN + 1;
    Node **buckets = (Node **)malloc(sizeof(Node *) * NUM);
    for (i = 0; i < NUM; i++)
        buckets[i] = NULL;
    for (i = 0; i < n; i++)
    {
        j = (a[i] - mn) / LEN;
        Node *head = buckets[j];
        buckets[j] = InsertSort(head, a[i]);
    }
    Merge(buckets, NUM, a);
}

int main()
{
    int n, a[100000], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    BucketSort(a, n);
    for (i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}