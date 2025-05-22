#include <stdio.h>
#include <stdlib.h>

Node *CreateTree(int n)
{
    Node *root = NULL;
    int val, i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        if (root == NULL)
        {
            root = (Node *)malloc(sizeof(Node));
            root->data = val;
            root->left = root->right = NULL;
        }
        else
        {
            Node *current = root;
            Node *parent = NULL;
            while (current != NULL)
            {
                parent = current;
                if (val < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = val;
            newNode->left = newNode->right = NULL;
            if (val < parent->data)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
        }
    }
    return root;
}