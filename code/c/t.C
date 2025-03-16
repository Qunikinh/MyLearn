Node* Add(Node* A, Node* B) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* p = head;

    Node* a = A->next;
    Node* b = B->next;

    while (a != NULL && b != NULL) {
        if (a->exp < b->exp) {

            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->coef = a->coef;
            newNode->exp = a->exp;
            newNode->next = NULL;
            p->next = newNode;
            p = p->next;
            a = a->next;
        } else if (a->exp > b->exp) {

            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->coef = b->coef;
            newNode->exp = b->exp;
            newNode->next = NULL;
            p->next = newNode;
            p = p->next;
            b = b->next;
        } else {

            int sum = a->coef + b->coef;
            if (sum != 0) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->coef = sum;
                newNode->exp = a->exp;
                newNode->next = NULL;
                p->next = newNode;
                p = p->next;
            }
            a = a->next;
            b = b->next;
        }
    }

    while (a != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->coef = a->coef;
        newNode->exp = a->exp;
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
        a = a->next;
    }

    while (b != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->coef = b->coef;
        newNode->exp = b->exp;
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
        b = b->next;
    }

    return head;
}