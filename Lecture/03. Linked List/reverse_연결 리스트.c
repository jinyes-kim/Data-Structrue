#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
ListNode* insert_first(ListNode* head, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    if (tmp == NULL) error("Memory Not Assignment");
    tmp->data = data;
    
    if (head == NULL) {
        tmp->link = NULL;
        return tmp;
    }
    tmp->link = head;
    head = tmp;
    return tmp;
}

void print_list(ListNode* head) {
    ListNode* tmp = head;
    for (; tmp != NULL; tmp = tmp->link) {
        printf("%d ->", tmp->data);
    }
    printf("\n");
}

ListNode* reverse(ListNode* head) {
    ListNode* front, *tmp, *tail;
    tail = head;
    front = NULL;
    while (tail != NULL) {
        tmp = front;
        front = tail;
        tail = tail->link;
        front->link = tmp;
    }
    return front;
}


int main(void){
    ListNode* list1 = NULL;
    list1 = insert_first(list1, 1);
    list1 = insert_first(list1, 2);
    list1 = insert_first(list1, 3);
    list1 = insert_first(list1, 4);
    print_list(list1);

    list1 = reverse(list1);
    print_list(list1);
    return 0;

}