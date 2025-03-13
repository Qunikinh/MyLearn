#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Elemtype;
typedef struct node
{
    Elemtype  data;
    struct node *next;
}Node;

void Create(Node *head,int n){

}

void Print(Node *head){

}

void Insert(Node* head, int pos, Elemtype x);//在链表的第pos（从1开始）位置前插入值为x的结点，head为头指针

void Delete(Node* head, int pos);//删除链表pos（从1开始）位置的元素，head为头指针

int Find(Node* head, Elemtype x);//查找值为x的第一个结点，找到返回位置（从1开始），否则返回-1

void Update(Node* head,int pos, Elemtype x);//将链表第pos（从1开始）位置的值修改为x

void Reverse(Node *head);//将链表所有元素逆置

void Destroy(*head);

int main(){
    int n;
    Node *head;
    scanf("%d",&n);
    Create(head,n);//建表
    char cmd[20];
    int pos;
    Elemtype x;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "Insert")==0)
            Insert(head, pos, x);
        else if(strcmp(cmd, "Delete")==0)
            Delete( head, pos);
        else if(strcmp(cmd, "Find")==0)//查找
        {
            scanf("%d", &x);
            pos = Find(head, x);
            if(pos == -1)
                printf("Not found\n");
            else
                printf("%d\n", pos);
        }
        else if(strcmp(cmd, "Update")==0)//逆置
        {
            Update(head,pos,x);
        }
        else if(strcmp(cmd, "Reverse")==0)//逆置
        {
            Reverse(head);
        }
        else
            break;
    }
    Destroy(head);
    return 0;
}