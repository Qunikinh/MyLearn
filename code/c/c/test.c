#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int va, vb, sum;
        int a[1000] = {0}, b[1000] = {0};
        scanf("%d", &va);
        for (j = 0; j < va; j++) {
            scanf("%d", &a[j]);
        }
        scanf("%d", &vb);
        for (j = 0; j < vb; j++) {
            scanf("%d", &b[j]);
        }
        sum = va + vb;
        printf("%d ", sum);
        int vai = 0, vbi = 0;
        // 当两个线性表都还有元素未处理时
        while (vai < va && vbi < vb) {
            if (a[vai] < b[vbi]) {
                printf("%d ", a[vai]);
                vai++;
            } else {
                printf("%d ", b[vbi]);
                vbi++;
            }
        }
        // 处理 va 中剩余的元素
        while (vai < va) {
            printf("%d ", a[vai]);
            vai++;
        }
        // 处理 vb 中剩余的元素
        while (vbi < vb) {
            printf("%d ", b[vbi]);
            vbi++;
        }
        printf("\n");
    }
    return 0;
}