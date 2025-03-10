#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;

typedef struct {
    Elemtype *data;
    int length;
} SeqList;

void CreateSeqList(SeqList &L) {
    L.data = NULL;
    L.length = 0;
}

void InitSeqList(SeqList &L) {
    int n;
    scanf("%d", &n);
    if (L.data != NULL) {
        free(L.data);
        L.data = NULL;
    }
    L.data = (Elemtype*)malloc(200 * sizeof(Elemtype));
    for (int i = 0; i < n; i++) {
        scanf("%d", &L.data[i]);
    }
    L.length = n;
}

void InsertSeqList(SeqList &L, int pos, Elemtype x) {
    if (pos < 0 || pos > L.length || L.length >= 200) {
        return;
    }
    for (int i = L.length; i > pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos] = x;
    L.length++;
}

void DeleteSeqList(SeqList &L, int pos) {
    if (pos < 0 || pos >= L.length) {
        return;
    }
    for (int i = pos; i < L.length - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
}

void GetElemInSeqList(SeqList &L, int pos, Elemtype &x) {
    x = L.data[pos];
}

int FindInSeqList(SeqList &L, Elemtype x) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x) {
            return i;
        }
    }
    return -1;
}

void ReverseSeqList(SeqList &L) {
    int i = 0, j = L.length - 1;
    while (i < j) {
        Elemtype temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;
        i++;
        j--;
    }
}

// 以下为题目已给出的代码，无需提交
// 打印
void PrintSeqList(SeqList &L) {
    int i;
    for(i=0;i<L.length;i++) {
        if(i)
            printf(" ");
        printf("%d", L.data[i]);
    }
    printf("\n");
}
// 销毁
void DestroySeqList(SeqList &L) {
    free(L.data);
}

int main() {
    SeqList L;
    CreateSeqList(L);//建表
    char cmd[20];
    int pos;
    Elemtype x;
    while(scanf("%s", cmd)!=EOF) {
        if(strcmp(cmd, "Init")==0)//初始化
            InitSeqList(L);
        else if(strcmp(cmd, "Print")==0)//打印表
            PrintSeqList(L);
        else if(strcmp(cmd, "Insert")==0)//位置前插入元素
        {
            scanf("%d%d", &pos, &x);
            InsertSeqList(L, pos, x);
        }
        else if(strcmp(cmd, "Delete")==0)//删除
        {
            scanf("%d", &pos);
            DeleteSeqList(L, pos);
        }
        else if(strcmp(cmd, "GetElem")==0)//索引
        {
            scanf("%d", &pos);
            GetElemInSeqList(L, pos, x);
            printf("%d\n", x);
        }
        else if(strcmp(cmd, "FindElem")==0)//查找
        {
            scanf("%d", &x);
            pos = FindInSeqList(L, x);
            if(pos == -1)
                printf("Not found\n");
            else
                printf("%d\n", pos);
        }
        else if(strcmp(cmd, "Reverse")==0)//逆置
        {
            ReverseSeqList(L);
        }
        else
            break;
    }
    DestroySeqList(L);//销毁
    return 0;
}

//todo  c语言无法完成，需要c++来完成
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef int Elemtype;

// typedef struct {
//     Elemtype *data;
//     int length;
// } SeqList;

// void CreateSeqList(SeqList &L) {
//     L.data = NULL;
//     L.length = 0;
// }

// void InitSeqList(SeqList &L) {
//     int n;
//     scanf("%d", &n);
//     if (L.data != NULL) {
//         free(L.data);
//         L.data = NULL;
//     }
//     L.data = (Elemtype*)malloc(200 * sizeof(Elemtype));
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &L.data[i]);
//     }
//     L.length = n;
// }

// void InsertSeqList(SeqList &L, int pos, Elemtype x) {
//     if (pos < 0 || pos > L.length || L.length >= 200) {
//         return;
//     }
//     for (int i = L.length; i > pos; i--) {
//         L.data[i] = L.data[i - 1];
//     }
//     L.data[pos] = x;
//     L.length++;
// }

// void DeleteSeqList(SeqList &L, int pos) {
//     if (pos < 0 || pos >= L.length) {
//         return;
//     }
//     for (int i = pos; i < L.length - 1; i++) {
//         L.data[i] = L.data[i + 1];
//     }
//     L.length--;
// }

// void GetElemInSeqList(SeqList &L, int pos, Elemtype &x) {
//     x = L.data[pos];
// }

// int FindInSeqList(SeqList &L, Elemtype x) {
//     for (int i = 0; i < L.length; i++) {
//         if (L.data[i] == x) {
//             return i;
//         }
//     }
//     return -1;
// }

// void ReverseSeqList(SeqList &L) {
//     int i = 0, j = L.length - 1;
//     while (i < j) {
//         Elemtype temp = L.data[i];
//         L.data[i] = L.data[j];
//         L.data[j] = temp;
//         i++;
//         j--;
//     }
// }

// // 以下为题目已给出的代码，无需提交
// // 打印
// void PrintSeqList(SeqList &L) {
//     int i;
//     for(i=0;i<L.length;i++) {
//         if(i)
//             printf(" ");
//         printf("%d", L.data[i]);
//     }
//     printf("\n");
// }
// // 销毁
// void DestroySeqList(SeqList &L) {
//     free(L.data);
// }

// int main() {
//     SeqList L;
//     CreateSeqList(L);//建表
//     char cmd[20];
//     int pos;
//     Elemtype x;
//     while(scanf("%s", cmd)!=EOF) {
//         if(strcmp(cmd, "Init")==0)//初始化
//             InitSeqList(L);
//         else if(strcmp(cmd, "Print")==0)//打印表
//             PrintSeqList(L);
//         else if(strcmp(cmd, "Insert")==0)//位置前插入元素
//         {
//             scanf("%d%d", &pos, &x);
//             InsertSeqList(L, pos, x);
//         }
//         else if(strcmp(cmd, "Delete")==0)//删除
//         {
//             scanf("%d", &pos);
//             DeleteSeqList(L, pos);
//         }
//         else if(strcmp(cmd, "GetElem")==0)//索引
//         {
//             scanf("%d", &pos);
//             GetElemInSeqList(L, pos, x);
//             printf("%d\n", x);
//         }
//         else if(strcmp(cmd, "FindElem")==0)//查找
//         {
//             scanf("%d", &x);
//             pos = FindInSeqList(L, x);
//             if(pos == -1)
//                 printf("Not found\n");
//             else
//                 printf("%d\n", pos);
//         }
//         else if(strcmp(cmd, "Reverse")==0)//逆置
//         {
//             ReverseSeqList(L);
//         }
//         else
//             break;
//     }
//     DestroySeqList(L);//销毁
//     return 0;
// }
