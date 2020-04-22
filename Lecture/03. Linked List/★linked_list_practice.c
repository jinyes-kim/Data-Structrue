#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{    // 익명구조체 쓰면 포인터 타고 못넘어간다 주의할 것
    element data;
    struct ListNode* link;
} ListNode;

void error(char* msg) {
    fprintf(stderr, msg);
}

ListNode* get_last_node(ListNode* head) {
    ListNode* p = head;
    if (p == NULL || p->link == NULL) {
        return p;
    }
    while (p->link != NULL) {
        p = p->link;
    }
    return p;
}

// return new head
ListNode* insert_front(ListNode* head, element value) {
    ListNode* front = (ListNode*)malloc(sizeof(ListNode));
    front->data = value;
    front->link = head;
    head = front;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = value;
    
    if (head == NULL) {
        tmp->link = NULL;
        return tmp;
    }
    if (pre == NULL) {
        pre = get_last_node(head);
    }
    tmp->link = pre->link;
    pre->link = tmp;
    return head;
}

ListNode* delete_front(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* remove = head;
    head = head->link;
    free(remove);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    if (head == NULL) return NULL;
    if (pre == NULL) {
        pre = head;
        while (pre->link->link != NULL) {
            pre = pre->link;
        }
    }
    ListNode* tmp = pre->link;
    pre->link = tmp->link;
    free(tmp);
    return head;

}

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p->link != NULL) {
        printf("%d ->", p->data);
        p = p->link;
    }
    printf("%d", p->data);
    printf("\n");
}


int main(void) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->data = NULL, head->link = NULL;
    
    head = insert_front(head, 1);
    head = insert_front(head, 2);
    head = insert_front(head, 3);
    print_list(head);
    head = delete_front(head);
    print_list(head);
    head = delete(head, NULL);
    print_list(head);
    head = insert(head, NULL, 4);
    print_list(head);
    head = insert(head, NULL, 5);
    print_list(head);
    head = insert(head, NULL, 6);
    print_list(head);
}