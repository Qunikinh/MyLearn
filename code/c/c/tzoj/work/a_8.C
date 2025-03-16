#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef int Elemtype;
typedef struct node
{
    Elemtype  data;
    struct node *next;
}Node;

Node* Create(){
    int n,i;
    scanf("%d",&n);
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    Node *q=head,*p;
    for ( i = 0; i < n; i++)
    {
        p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->data);
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return head;
}

void Insert(Node *head,int pos,int m){
    int i;
    Node *q=head,*p;
    for ( i = 1; i < pos; i++)
    {
        q=q->next;
    }
    for ( i = 0; i < m; i++)
    {
        p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->data);
        p->next=q->next;
        q->next=p;
        q=p;
    }
}

void Delete(Node *head,int pos,int m){
    int i;
    Node *q=head,*p;
    for ( i = 1; i < pos; i++)
    {
        q=q->next;
    }
    for ( i = 0; i < m; i++)
    {
        if(q->next==NULL) //!过界要提前结束
            break;
        p=q->next;
        q->next=p->next;
        free(p);
    }
}

void Print(Node *head){
    Node* p = head;
    int flag = 0;
    while (p->next)
    {
    p = p->next;
    if(flag)
    printf(" ");
    flag = 1;
    printf("%d",p->data);
    }
    printf("\n");
}

void Destory(Node *head){
    Node *p;
    while (head!=NULL)
    {
        p=head;
        head=head->next;
        free(p);
    }
}

void F(Node *head,int p){
    int i,pos,m;
    char cmd[10];
    for ( i = 0; i < p; i++)
    {
        scanf("%s",cmd);
        
        if (strcmp(cmd,"insert")==0)
        {
            scanf("%d %d",&pos,&m);
            Insert(head,pos,m);
        }
        else if (strcmp(cmd,"delete")==0)
        {
            scanf("%d %d",&pos,&m);
            Delete(head,pos,m);
        }else{break;}
    }
}
int main(){
    int i,t,p;
    scanf("%d",&t);
    for ( i = 0; i < t; i++)
    {
        Node *head = Create();
        scanf("%d",&p);
        F(head,p);
        Print(head);
        Destory(head);
    }
}