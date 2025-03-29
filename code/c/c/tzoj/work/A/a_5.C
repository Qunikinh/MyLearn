#include<stdlib.h>
#include<stdio.h>

typedef int Elemtype;
typedef struct node
{
    Elemtype  data;
    struct node *next;
}Node;

void CreateHeader(Node **head){
    *head=(Node*)malloc(sizeof(Node));
    (*head)->next=NULL;
}

void Insert(Node *head,int d){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=d;
    p->next=head->next;
    head->next=p;
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
    int n, d;

    Node *head;
    CreateHeader(&head);
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &d);
        Insert(head, d);
    }
    PrintLinkList(head);
    return 0;
}