#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int max_sum = 0;  // 记录最大子列和
    int cur_sum = 0;  // 记录当前子列和

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        cur_sum += num;
        if (cur_sum < 0) {
            cur_sum = 0;  // 如果当前子列和为负数，重置为 0
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;  // 更新最大子列和
        }
    }

    printf("%d\n", max_sum);

    return 0;
}