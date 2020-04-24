#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;


void init(ListNode* head) {
    head->data = NULL;
    head->link = NULL;
}

ListNode* insert(ListNode* head, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = data;
    tmp->link = NULL;   // 항상 초기화 부분 유의할 것
    if (head == NULL) {
        return tmp;
    }
    ListNode* pointer = head;
    while (pointer->link != NULL) {
        pointer = pointer->link;
    }
    pointer->link = tmp;
    return head;
}

ListNode* delete(ListNode* head) {
    ListNode* pointer = head;
    ListNode* removed;
    while (pointer->link->link != NULL) {
        pointer = pointer->link;
    }
    removed = pointer->link;
    free(removed);
    pointer->link = NULL;
    return head;
}

void print_list(ListNode* head) {
    ListNode* tmp = head;
    while (tmp->link != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->link;
    }
    printf("%d\n", tmp->data);
}

int main(void) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    print_list(head);

    head = delete(head);
    print_list(head);
    head = delete(head);
    print_list(head);
    return 0;
}
