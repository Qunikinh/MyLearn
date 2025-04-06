#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Elem
{
    int x, y, d;
};
typedef struct F
{
    struct Elem elem[100];
    int num;
} F;

void CreateF(F *h)
{
    int i;
    scanf("%d", &h->num);
    for (i = 0; i < h->num; i++)
    {
        scanf("%d %d %d", &h->elem[i].x, &h->elem[i].y, &h->elem[i].d);
    }
}
void Sum(F *n, F *m)
{
}
int main()
{
    F *m, *n;
    CreateF(n);
    CreateF(m);
    Sum(n, m);
}
