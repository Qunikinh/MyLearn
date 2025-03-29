#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int coef;
    int exp;
    Node *next;
}Node;

Node* Add(Node* A, Node* B){
    A=A->next;
    B=B->next;
    Node *C=NULL;
    Node *head=(Node*)malloc(sizeof(Node));
    Node *p=head;
    p->next=NULL;
    while (A!=NULL&&B!=NULL)
    {
        if (A->exp>B->exp)
        {
            C=B;
        }else{
            C=A;
        }
        if (p->exp!=C->exp)
        {
            p->next=C;
            C=C->next;
        }
        else{
            Node *q;
            p->coef+=C->coef;
            q=C;
            C=C->next;
            free(q);
        }
    }
    while (A!=NULL||B!=NULL)
    {
        if (A==NULL)
        {
            C=B;
        }else{
            C=A;
        }
        if (p->exp!=C->exp)
        {
            p->next=C;
            C=C->next;
        }
        else{
            Node *q;
            p->coef+=C->coef;
            q=C;
            C=C->next;
    }
}
    return head;
}