#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void CreateHuffmanTree(HuffmanTree &HT, int *w, int n)
{
    if (n <= 1)
        return;                                         // 如果只有一个编码就相当于0
    intm = 2 * n - 1;                                   // 哈夫曼树总节点数，n就是叶子结点
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); // 0号位置不用
    HuffmanTreep = HT;
    // 初始化哈夫曼树中的所有结点
    for (inti = 1; i <= n; i++)
    {
        (p + i)->weight = w[i - 1];
        (p + i)->parent = 0;
        (p + i)->left = 0;
        (p + i)->right = 0;
    }
    // 从树组的下标n+1开始初始化哈夫曼树中除叶子结点外的结点
    for (int i = n + 1; i <= m; i++)
    {
        (p + i)->weight = 0;
        (p + i)->parent = 0;
        (p + i)->left = 0;
        (p + i)->right = 0;
    }
    // 构建哈夫曼树
    for (inti = n + 1; i <= m; i++)
    {
        ints1, s2;
        Select(HT, i - 1, &s1, &s2); // 选择两个最小的权值，s1最小，s2次小
        85 HT[s1].parent = HT[s2].parent = i;
        HT[i].left = s1;
        HT[i].right = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 打印哈夫曼编码的函数
void PrintHuffmanCode(int w[], char *code[], int n)
{
    printf("Huffman code:\n");
    for (int i = 1; i <= n; i++)
        printf("%d(%d)\n", w[i], strlen(code[i]));
}
int main()
{
    int w[101], n, i;
    char *code[101]; // code[i]为w[i]的编码
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    Node *ht = CreateHuffmanTree(w, n);
    HuffmanCode(ht, code);        // 计算编码长度
    PrintHuffmanCode(w, code, n); // 打印权值和编码长度
    return 0;
}