// 数据结构：串的块链存储
// 输入一个字符串，请将其用块链结构存储，所谓块链结构是将串分割成多个块，以链表形式存储，链表的每个结点存储一个固定大小的子串。本题假设块的大小为3，块的定义如下：
// 实现CreateString函数，用于输入并创建块链结构。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NodeSize 3
typedef struct Node
{
    char data[NodeSize];
    struct Node *next;
} Node;

Node *CreateString();
void PrintString(Node *head)
{
    int i, flag = 0;
    Node *temp = head;
    while (temp)
    {
        if (flag)
            printf("->");
        flag = 1;
        for (i = 0; i < NodeSize; i++)
        {
            printf("%c", temp->data[i]);
        }
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node *head = NULL;
    head = CreateString();
    PrintString(head);
    return 0;
}
// todo __________________________
Node *CreateString()
{
    char str[101];
    gets(str);
    Node *head = NULL, *tail = head, *p;
    int i, j = 0;
    for (i = 0; str[i] != 0; i++)
    {
        if (j == 0)
        {
            p = (Node *)malloc(sizeof(Node));
            p->next = NULL;
            if (head == NULL)
            {
                head = p;
            }
            else
            {
                tail->next = p;
            }
            tail = p;
        }
        p->data[j++] = str[i];
        if (j == NodeSize)
        {
            j = 0;
        }
    }
    while (j > 0 && j < NodeSize)
    {
        p->data[j++] = '#';
    }

    return head;
}
