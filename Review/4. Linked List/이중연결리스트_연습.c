#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* rlink;
    struct ListNode* llink;
} ListNode;


// ADT
void error(char* msg);
ListNode* insert_first(ListNode* list, element item);
ListNode* insert(ListNode* list, ListNode* pre, element item);
ListNode* delete_first(ListNode* list);
ListNode* delet(ListNode* list, ListNode* pre);
void print_list(ListNode* list);


void error(char* msg) {
    fprintf(stderr, msg);
    exit(1);
}


ListNode* insert_first(ListNode* head, element item) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = item;
    if (head == NULL) {
        tmp->rlink = tmp;
        tmp->llink = tmp;
        return tmp;
    }
    head->rlink->llink = tmp;
    tmp->rlink = head->rlink;
    head->rlink = tmp;
    tmp->llink = head;
    return head;
}

ListNode* insert(ListNode* head, element item) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = item;
    if (head == NULL) {
        tmp->rlink = tmp;
        tmp->llink = tmp;
        return tmp;
    }
    ListNode* tail = head;
    head->rlink->llink = tmp;
    tmp->rlink = head->rlink;
    head->rlink = tmp;
    tmp->llink = head;
    head = tmp;
    return head;
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) error("리스트에 요소가 없습니다");
    if (head->rlink == head) {
        free(head);
        return NULL;
    }
    ListNode* removed = head->rlink;
    head->rlink->rlink->llink = head;
    head->rlink = head->rlink->rlink;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head) {
    if (head == NULL) error("리스트에 요소가 없습니다");
    if (head->rlink == head) {
        free(head);
        return NULL;
    }
    ListNode* tmp = head->llink;
    ListNode* removed = head;
    tmp->rlink = head->rlink;
    head->rlink->llink = tmp;
    free(removed);
    return tmp;
}


void print_list(ListNode* head) {
    ListNode* tmp = head->rlink;
    do {
        printf("-> (%d)%d ", tmp->llink->data, tmp->data);
        tmp = tmp->rlink;
    } while (tmp != head->rlink);
    printf("\n");
}



int main(void) {

    ListNode* head = NULL;


    head = insert_first(head, 1);
    head = insert_first(head, 2);
    head = insert_first(head, 3);
    head = insert_first(head, 4);

    print_list(head);


    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);

    print_list(head);


    head = delete_first(head);
    head = delete_first(head);
    head = delete_first(head);
    print_list(head);


    head = delete(head);
    head = delete(head);
    head = delete(head);
    print_list(head);
    head = delete_first(head);
    head = delete_first(head);
    head = delete_first(head);
    return 0;
}

