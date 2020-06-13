#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int coef;
    int expon;
    struct LinkNode* link;
} LinkNode;

typedef struct LinkHead {
    int size;
    LinkNode* head;
    LinkNode* tail;
} LinkHead;

//ADT
LinkHead* create();
void insert(LinkHead* head, int coef, int expon);
void poly_add(LinkHead* list1, LinkHead* list2, LinkHead* list3);
void print_list(LinkHead* list);

LinkHead* create() {
    LinkHead* tmp = (LinkHead*)malloc(sizeof(LinkHead));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void insert(LinkHead* head, int coef, int expon) {
    LinkNode* tmp = (LinkNode*)malloc(sizeof(LinkNode));
    tmp->coef = coef;
    tmp->expon = expon;
    tmp->link = NULL;
    if (head->tail == NULL) {
        head->head = head->tail = tmp;
    }
    else {
        head->tail->link = tmp;
        head->tail = tmp;
    }
    head->size++;
}

void print_list(LinkHead* head) {
    LinkNode* tmp = head->head;
    for (; tmp; tmp = tmp->link) {
        printf("%d^%d+ ", tmp->coef, tmp->expon);
    }
    printf("\n");
}

void poly_add(LinkHead* list1, LinkHead* list2, LinkHead* list3) {
    LinkNode* a = list1->head;
    LinkNode* b = list2->head;

    int sum = 0;
    while (a && b) {
        if (a->expon == b->expon) {
            sum = a->coef + b->coef;
            insert(list3, sum, a->expon);
            a = a->link;
            b = b->link;
        }
        else if (a->expon > b->expon) {
            insert(list3, a->coef, a->expon);
            a = a->link;
        }
        else {
            insert(list3, b->coef, b->expon);
            b = b->link;
        }
    }
    for (; a != NULL; a = a->link) {
        insert(list3, a->coef, a->expon);
    }
    for (; b != NULL; b = b->link) {
        insert(list3, b->coef, b->expon);
    }
}

int main(void) {
    LinkHead* list1 = create();
    LinkHead* list2 = create();
    LinkHead* list3 = create();

    insert(list1, 5, 12);
    insert(list1, 5, 8);
    insert(list1, 5, 2);
    insert(list1, 5, 0);
    print_list(list1);

    insert(list2, 5, 12);
    insert(list2, 5, 10);
    insert(list2, 5, 6);
    insert(list2, 5, 2);
    print_list(list2);

    poly_add(list1, list2, list3);
    print_list(list3);
    return 0;
}
