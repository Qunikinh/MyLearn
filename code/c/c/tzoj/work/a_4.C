#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Elemtype;
typedef struct node
{
    Elemtype  data;
    struct node *next;
}Node;

Node* CreateLinkList()
{
Node *head = (Node*)malloc(sizeof(Node)), *last = head;
head->next = NULL;
int i, n;
Elemtype x;
scanf("%d", &n);
for (i=1; i<=n; i++)
{
scanf("%d", &x);
Node *p = (Node*)malloc(sizeof(Node));
p->data = x;
p->next = NULL;
last->next = p;
last = p;
}
return head;
}

void Print(Node *head){
    Node *p=head;
    p=p->next;
    int c=0;
    while (p!=NULL)
    {
        if (c)
        {
            printf(" %d",p->data);
        }else{
            printf("%d",p->data);
            c++;
        }
        p=p->next;
    }
    printf("\n");
}

void Insert(Node* head, int pos, Elemtype x)//在链表的第pos（从1开始）位置前插入值为x的结点，head为头指针
{
    int i;
    Node *q=head;
    for ( i = 0; i < pos-1; i++)
    {
        q=q->next;
    }
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=x;
    p->next=q->next;
    q->next=p;
    Print(head);
}

void Delete(Node* head, int pos)//删除链表pos（从1开始）位置的元素，head为头指针
{
    int i;
    Node *q=head;
    for ( i = 0; i < pos-1; i++)
    {
        q=q->next;
    }
    if (q->next->next==NULL)
    {
        free(q->next);
        q->next=NULL;
        Print(head);
        return;
    }
    
    Node *p=q->next;
    q->next=p->next;
    free(p);
    Print(head);
}

int Find(Node* head, Elemtype x)//查找值为x的第一个结点，找到返回位置（从1开始），否则返回-1
{
    Node *q=head->next;
    int c=1;
    while (q!=NULL)
    {
        if (q->data==x)
        {
            return c;
        }
        q=q->next;
        c++;
    }
    return -1;
}
void Update(Node* head,int pos, Elemtype x)//将链表第pos（从1开始）位置的值修改为x
{
    int i;
    Node *q=head;
    for ( i = 0; i < pos; i++)
    {
        q=q->next;
    }
    q->data=x;
    Print(head);
}

void Reverse(Node* head) {
    if (head == NULL || head->next == NULL) return;
    Node* prev = NULL;
    Node* current = head->next;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
    Print(head);
}
void Destroy(Node *head){
    Node *p;
    while (head!=NULL)
    {
        p=head;
        head=head->next;
        free(p);
    }
}

int main(){
    int n;
    Node *head=NULL;
    head=CreateLinkList();//建表
    char cmd[20];
    int pos;
    Elemtype x;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "Insert")==0)
            scanf("%d %d",&pos,&x),Insert(head, pos, x);
        else if(strcmp(cmd, "Print")==0)
            Print(head);
        else if(strcmp(cmd, "Delete")==0)
            scanf("%d",&pos),Delete( head, pos);
        else if(strcmp(cmd, "Find")==0)//查找
        {
            scanf("%d", &x);
            pos = Find(head, x);
            printf("%d\n",pos);
        }
        else if(strcmp(cmd, "Update")==0)//逆置
        {
            scanf("%d %d",&pos,&x);
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