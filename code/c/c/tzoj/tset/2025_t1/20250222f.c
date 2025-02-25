#include<stdio.h>
#include<string.h>

typedef struct St{
    char num[15];
    int a,b;
}St;

int main(){
    int n,m,i,j,k;
    St a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d %d",a[i].num,&a[i].a,&a[i].b);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&k);
        for(j=0;j<n;j++){
            if(k==a[j].a){
                printf("%s %d\n",a[j].num,a[j].b);
                break;
            }
        }
    }
}