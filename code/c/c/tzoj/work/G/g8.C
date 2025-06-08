#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashStr
{
    char str[5];
} HashStr;

typedef struct HashNode
{
    HashStr list[18000];
    int Num = 0;
} HashNode;

HashNode hash;

int Hash(char str[])
{
    int i;
    for (i = 0; i < hash.Num; i++)
    {
        if (strcmp(str, hash.list[i].str) == 0)
        {
            return i;
        }
    }
    strncpy(hash.list[hash.Num].str, str, 5);
    return hash.Num++;
}
int main()
{
    int sm[18000];
    int n, m, a;
    char str[5];
    scanf("%d%d", &n, &m);
    while (n--)
    {
        scanf("%s%d", &str, &a);
        sm[Hash(str)] = a;
    }
    while (m--)
    {
        scanf("%s", &str);
        printf("%d\n", sm[Hash(str)]);
    }
    return 0;
}