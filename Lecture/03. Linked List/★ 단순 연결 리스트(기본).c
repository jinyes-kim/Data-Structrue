#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 익명 구조체 사용시 포인터->포인터->포인터
// 같은 형태로 사용할 없음에 유의.
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;


ListNode* get_last_node(ListNode* head) {
    ListNode* cur = head;
    if (cur == NULL || cur->link == NULL) return cur;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    return cur;
}


ListNode* insert_first(ListNode* head, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = data;
    if (head == NULL) {
        tmp->link = NULL;
        head = tmp;
        return head;
    }
    tmp->link = head;
    head = tmp;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = data;
    if (head == NULL) {
        tmp->link = NULL;
        head = tmp;
        return head;
    }
    if (pre == NULL) {
        pre = get_last_node(head);
    }
    tmp->link = pre->link;
    pre->link = tmp;
    return head;
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* tmp = head;
    head = head->link;
    free(tmp);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* tmp;
    if (head == NULL || head->link == NULL) return NULL;
    if (pre == NULL) {
        pre = head;
        while (pre->link->link != NULL) {
            pre = pre->link;
        }
    }
    tmp = pre->link;
    pre->link = pre->link->link;
    free(tmp);
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

ListNode* concat_list(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    
    ListNode* tmp = head1;
    while (tmp->link != NULL) {
        tmp = tmp->link;
    }
    tmp->link = head2;
    return head1;
}

ListNode* search_node(ListNode* head, element data) {
    ListNode* tmp = head;
    while (tmp != NULL) {
        if (tmp->data == data) return tmp;
        tmp = tmp->link;
    }
    return NULL;
}

int main(void) {
    ListNode* list1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* list2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* list3 = (ListNode*)malloc(sizeof(ListNode));
    
    // 변수 초기화 잊지 않기
    // 초기화 하지 않으면 메모리 읽기 액세스 위반 에러가 난다.
    list1= NULL;
    list2= NULL;
    list3= NULL;


    list1 = insert_first(list1, 1);
    list1 = insert(list1, NULL, 2);
    list1 = insert(list1, NULL, 3);

    list2 = insert(list2, NULL, 5);
    list2 = insert_first(list2, 4);
    list2 = insert(list2, NULL, 6);

    print_list(list1);
    print_list(list2);

    list3 = concat_list(list1, list2);
    print_list(list3);


    // func test - search_node
    printf("serach node -> %d", search_node(list3, 5)->data);

    return 0;
}
