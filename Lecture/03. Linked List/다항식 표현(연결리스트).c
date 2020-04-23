#include <stdio.h>
#include <stdlib.h>

/*
다항식 표현(연결 리스트)

a = (3x^12 + 2^8 + 1)
+
b = (8^12 -3^10 + 10^6)

c = 11^12 + -3^10 +2^8 + 10^6 + 1

*/


typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode* link;
} ListNode;

typedef struct ListType {
    int size;
    ListNode* head;
    ListNode* tail;
} ListType;


void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

// intialize header
ListType* create() {
    ListType* tmp = (ListType*)malloc(sizeof(ListType));
    if (tmp == NULL) error("Memory Not Assignment");
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void insert_last(ListType* header, int coef, int expon) {
    // 1. make new node for tail
    // 2. link to header

    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->coef = coef;
    tmp->expon = expon;
    tmp->link = NULL;

    if (header->head == NULL && header->tail == NULL) {
        header->head = header->tail = tmp;
    }
    else {
        // header->tail = ListType
        // header->tail->link = ListNode
        header->tail->link = tmp;
        header->tail = tmp;
    }
    header->size++;
}


void poly_print(ListType* header) {
    ListNode* tmp = header->head;
    
    // textbook code
    printf("polynomial = ");
    for (; tmp; tmp = tmp->link) {
        printf("%d^%d + ", tmp->coef, tmp->expon);
    }
    printf("\n");


    /*  personal code
    
        while (tmp->link != NULL) {
        printf("%d^%d + ", tmp->coef, tmp->expon);
        tmp = tmp->link;
    }
    printf("%d^%d\n", tmp->coef, tmp->expon);

    */
}


// list1 + list2 = list3
void poly_add(ListType* list1, ListType* list2, ListType* list3) {
    // case1 equal a.expon, b.expon
    // case2 a.expon > b.expon
    // case3 b.expon < a.expon
    // case4 remainder

    ListNode* a = list1->head;
    ListNode* b = list2->head;

    while (a && b) {
        if (a->expon == b->expon) {
            insert_last(list3, a->coef + b->coef, a->expon);
            a = a->link;
            b = b->link;
        }
        else if (a->expon > b->expon) {
            insert_last(list3, a->coef, a->expon);
            a = a->link;
        }
        else{
            insert_last(list3, b->coef, b->expon);
            b = b->link;
        }
    }
    for (; a != NULL; a = a->link) {
        insert_last(list3, a->coef, a->expon);
    }
    for (; b != NULL; b = b->link) {
        insert_last(list3, b->coef, b->expon);
    }
}

int main(void) {
    ListType* list1 = create();
    ListType* list2 = create();
    ListType* list3 = create();

    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1); 
    poly_print(list2);
    
    poly_add(list1, list2, list3);
    poly_print(list3);
    return 0;
}
