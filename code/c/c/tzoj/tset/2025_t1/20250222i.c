#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void fdj(char *p);
int main()
{
    char t[1001];
    gets(t);
    int i, n;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        char *p = (char*)malloc(100001);
        strcpy(p, t);
        fdj(p);
    }
    return 0;
}

void fdj(char *p){
    puts(p);
    free(p);
}