// 描述
// 给定一个字符串S1，S2，···，Sn，按如下过程加密:取出第一个字符S1，将第二个字符S2放到字符串的末尾Sn后面，得到字符串S3…S2;接着把S3取出，S4放到字符串的末尾S2后面…直到最后一个字母Sn被取出。这些字母按取出的顺序形成一个新的字符串，称为密串。请编写一个加密程序，输入一个字符串(长度小于等于200)，输出该字符串的密串。
// 输入
// 输入为一字符串，长度不超过200字符，包含空格。
// 输出
// 输出其信息加密后的值。

// 样例输入
// Python
// 样例输出
// Ptoynh
// 提示
// 1.取出P输出
// 2.将y放置后面，此时字符串为thony
// 3.取出t并输出
// 4.将h放置后面，此时字符串为onyh
// 5.取出o并输出
// 6.将n放置后面，此时字符串为yhn
// 7.取出y并输出
// 8.将h放置后面，此时字符串为nh
// 9.取出n并输出
// 10.将h放置后面，此时字符串为h
// 11.取出h并输出

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Elemtype;
typedef struct SqQueue
{
    Elemtype *data;
    int front;
    int rear;
    int size;
} SqQueue;
void InitQueue(SqQueue *q)
{
    q->size = 99999;
    q->data = (Elemtype *)malloc(sizeof(Elemtype) * q->size);
    q->front = 0;
    q->rear = -1;
    char c[201];
    gets(c);
    while (c[++q->rear] != 0)
    {
        q->data[q->rear] = c[q->rear];
    }
    return;
}
void Change(SqQueue *q)
{
    q->data[(q->rear++)] = q->data[(q->front++)];
}

int main()
{
    SqQueue q;
    InitQueue(&q);
    while (q.front != q.rear)
    {
        putchar(q.data[q.front++]);
        Change(&q);
    }
}