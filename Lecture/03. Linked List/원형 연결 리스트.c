#include <stdio.h>
#include <stdlib.h>


/*
원형 연결 리스트

노드: 변경 없음
출력: 헤드 전 까지만 출력하도록 수정
입력:  
        1. 첫 노드가 자기 자신을 가르키게 한다.
        2. 다음에 들어온 노드를 tmp 가정

            tmp->link = head->link
            head->link = tmp

*/
typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = data;
    if (head == NULL) {
        head = tmp;
        head->link = head;
        return head;
    }
    tmp->link = head->link;
    head->link = tmp;
    return head;
}

ListNode* insert_last(ListNode* head, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = data;
    if (head == NULL) {
        head = tmp;
        head->link = head;
        return head;
    }
    tmp->link = head->link;
    head->link = tmp;
    head = tmp;
    return head;
}

void print_list(ListNode* head) {
    ListNode* tmp = head->link;   
    if (head == NULL) return;
    do {
        printf("%d -> ", tmp->data);
        tmp = tmp->link;
    } while (tmp != head);
    printf("%d", tmp->data);
    printf("\n");
}


int main(void) {
    ListNode* list1 = NULL;
    ListNode *list2 = NULL;
    list1 = insert_first(list1, 1);
    list1 = insert_first(list1, 2);

    print_list(list1);
 
    printf("head: %d\n", list1->data);
    printf("head->link: %d\n", list1->link->data);
    printf("head->link->link: %d\n", list1->link->link->data);
    
    list2 = insert_last(list2, 1);
    list2 = insert_first(list2, 2);
    list2 = insert_last(list2, 3);
    print_list(list2);
    return 0;
}
