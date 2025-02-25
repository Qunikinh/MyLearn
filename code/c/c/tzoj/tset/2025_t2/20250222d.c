#include<stdio.h>

int main(){
    int n,i,j;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        int va,vb,sum;
        int a[1000]={0},b[1000]={0};
        scanf("%d",&va);
        for ( j = 0; j < va; j++){
            scanf("%d",&a[j]);
        }
        scanf("%d",&vb);
        for ( j = 0; j < vb; j++){
            scanf("%d",&b[j]);
        }
        sum=va+vb;
        printf("%d",sum);
        int vai,vbi;
        for ( vai = 0, vbi = 0; vai+vbi < sum; ){
            if (vai==va)
            {for (; vbi < vb; vbi++)
                {printf(" %d",b[vbi]);}
            break;}
            else if (vbi==vb)
            {for (; vai < va; vai++)
                {printf(" %d",a[vai]);}
            break;}
            
            if (a[vai]<b[vbi])
            {
                printf(" %d",a[vai]);
                vai++;
            }else{
                printf(" %d",b[vbi]);
                vbi++;
            }
        }
        printf("\n");
    }
}