/**
描述

给定一个一元多项式a0+a1x+a2x2+...+anxn中n, x和a0, a1, a2, ..., an的值，求多项式的值。


输入

第一行为正整数n(n<=100000)和小数x(0<=x<=1)

第二行n+1个小数，a0, a1, a2, ..., an的值(0<=ai<=10)


输出

输出结果，保留3位小数。


样例输入

3 1
1 2 3 0


样例输出

6.000

 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i;
    long n;
    double x,tmp;
    double a[100001];
    a[0]=1;
    double sum=0;
    scanf("%ld %lf",&n,&x);
    for(i=0;i<=n;i++){
        a[i+1]=x*a[i];
        scanf("%lf",&tmp);
        a[i]*=tmp;
        sum+=a[i];
    }
    printf("%.3lf\n",sum);
}