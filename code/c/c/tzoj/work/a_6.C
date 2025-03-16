#include<stdlib.h>
#include<stdio.h>

typedef int Elemtype;
typedef struct node
{
    Elemtype  data;
    struct node *prev;
    struct node *next;
}Node;

Node* CreateLinkList(int n){
    int i;
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->prev=NULL;
    Node *q=head,*p;

    for ( i = 0; i < n; i++)
    {
        p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->data);
        q->next=p;
        p->prev=q;
        p->next=NULL;
        q=p;
    }
    return head;
}

Node* Find(Node *head,int x){
    Node *p=head;
    while (p->next!=NULL)
    {
        p=p->next;
        if (p->data==x)
        {
            return p;
        }
    }
    return NULL;
}
void Delete(Node *p){
    if (p->next==NULL)
    {
        p->prev->next=NULL;//!要正确处理边界
        free(p);
        return;
    }
    
    Node *a,*d;
    a=p->prev;
    d=p->next;
    a->next=d;
    d->prev=a;
    free(p);
}

void PrintLinkList(Node *head)
{
    int flag = 0;
    Node *p = head->next, *q;
    while(p)
    {
        if(flag)
            printf(" ");
        flag = 1;
        printf("%d", p->data);
        q = p;
        p = p->next;
        free(q);
    }
    free(head);
}

int main()
{
    int n, x;
    scanf("%d", &n);
    Node *head = CreateLinkList(n);
    scanf("%d", &x);
    Node *p = Find(head, x);
    Delete(p);
    PrintLinkList(head);
    return 0;
}