#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef int Elemtype;
typedef struct SeqList
{
    Elemtype *data;
    int length;
}SeqList;
#define MAXSIZE 100
//建表
void CreateSeqList(SeqList &L){
    L.length = 0;
    L.data = (Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
}
//初始化
void InitSeqList(SeqList &L, int pos, Elemtype x)
{
    scanf("%d", &L.length);
    for(int i=0;i<L.length;i++)
        scanf("%d", &L.data[i]);
}

void InsertSeqList(SeqList &L, int pos, Elemtype x){

}

//todo题目代码
//打印
void PrintSeqList(SeqList &L){
    int i;
    for(i=0;i<L.length;i++)
    {
        if(i)
            printf(" ");
        printf("%d", L.data[i]);
    }
    printf("\n");
}
//销毁
void DestroySeqList(SeqList &L)
{
    free(L.data);
}

int main()
{
    SeqList L;
    CreateSeqList(L);//建表
    char cmd[20];
    int pos;
    Elemtype x;
    while(scanf("%s", cmd)!=EOF)
    {
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