#include <stdio.h>
void Swap(int *, int*);
int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        Swap(&a, &b);
        printf("%d %d\n", a, b);       
    }
    return 0;
}

void Swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}