#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Hash(char str[])
{
    return (str[0] - 'a') * 26 * 26 + (str[1] - 'a') * 26 + (str[2] - 'a');
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