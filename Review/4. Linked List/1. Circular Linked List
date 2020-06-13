#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

//ADT
ListNode* insert_first(ListNode* head, element time);
ListNode* insert_last(ListNode* head, element time);
void print_list(ListNode* head);
ListNode* delete_first(ListNode* head);
ListNode* delete_last(ListNode* head);

ListNode* insert_first(ListNode* head, element item) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = item;
    if (head == NULL) {
        tmp->link = tmp;
        return tmp;
    }
    tmp->link = head->link;
    head->link = tmp;
    return head;
}

ListNode* insert_last(ListNode* head, element item) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = item;
    if (head == NULL) {
        tmp->link = tmp;
        return tmp;
    }
    tmp->link = head->link;
    head->link = tmp;
    head = tmp;
    return head;
}

void print_list(ListNode* head) {
    ListNode* tmp = head->link; // head가 사실은 마지막이니까!
    do {
        printf("%d ->", tmp->data);
        tmp = tmp->link;
    } while (tmp != head);
    printf("%d\n", tmp->data);
}


ListNode* delete_first(ListNode* list) {
    ListNode* removed = list->link;
    list->link = list->link->link;
    free(removed);
    return list;
}

ListNode* delete_last(ListNode* list) {
    ListNode* removed = list;
    ListNode* tmp = list->link;
    while (tmp->link != list) {
        tmp = tmp->link;
    }
    tmp->link = list->link;
    free(removed);
    return tmp;
}

int main(void) {
    ListNode* list = NULL;
    list = insert_first(list, 1);
    list = insert_first(list, 2);
    list = insert_first(list, 3);
    list = insert_first(list, 4);
    print_list(list);


    list = insert_last(list, 4);
    list = insert_last(list, 5);
    list = insert_last(list, 6);
    print_list(list);

    list = delete_last(list);
    list = delete_last(list);
    print_list(list);



    list = delete_first(list);
    list = delete_first(list);
    print_list(list);
    free(list);
    return 0;
}
