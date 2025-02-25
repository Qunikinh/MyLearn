
/*
描述

输入学生的人数N，然后再输入N位学生的分数和姓名，求获得最高分数的学生的姓名。


输入


输入数据多组，每组先输入一个正整数N（N≤5），表示学生人数。接着输入N行，每行格式如下：

分数 姓名
分数是一个非负整数，且小于等于100；
姓名为一个连续的字符串，中间没有空格，长度不超过20。


输出

获得最高分数同学的姓名。


样例输入

5
87 lilei
99 hanmeimei
97 lily
96 lucy
77 jim

样例输出

hanmeimei

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct St{
    int score;
    char name[21];
}St;


int main() {
    St tmp;
    St a[5];
    int n,i;
   
    while (scanf("%d", &n) != EOF)
    {   
        for ( i = 0; i < n; i++) {
            scanf("%d %s", &a[i].score, a[i].name);
        }
        tmp = a[0];
        for ( i = 1; i < n; i++) {
            if (a[i].score > tmp.score) {
                tmp = a[i];
            }
        }
    printf("%s\n", tmp.name);
    }
}