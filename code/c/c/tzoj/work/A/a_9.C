#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int num;
    int cost;
    Node *next;
}Node;

Node* Creat(int n){
    int i;
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    Node *q=head,*p;
    for ( i = 0; i < n; i++)
    {
        p=(Node*)malloc(sizeof(Node));
        scanf("%d %d",&p->num,&p->cost);
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return head;
}

void Print(Node *head){
    Node *p=head->next;
    while (p!=NULL)
    {
        printf("%d %d\n",p->num,p->cost);
        p=p->next;
    }
}
void Add(Node* head, int m, int x){
    int i;
    Node *q=head,*p=(Node*)malloc(sizeof(Node));
    p->num=m;
    p->cost=x;
    p->next=NULL;
    while (q->next!=NULL)
    {
        if (q->next->cost==x)
        {
            q=q->next;
            q->num+=p->num;
            free(p);
            break;
        }
        
        else if (q->next->cost>x)//!使用else if而不是if
        {
            p->next=q->next;
            q->next=p;
            break;
        }
        q=q->next;
    }
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

int main(){
    int n,i;
    scanf("%d",&n);
    Node *head=Creat(n);
    int m,x;
    scanf("%d %d",&m,&x);
    Add(head,m,x);
    Print(head);
    Destory(head);
}