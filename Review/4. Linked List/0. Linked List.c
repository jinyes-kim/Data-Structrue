#include <stdio.h>
#include <stdlib.h>

/*
링크드 리스트

노드(구조체)를 생성하고 노드와 노드를 연결하는 자료구조

데이터를 추가, 삭제시 연산하고 헤드 노드를 리턴한다.


<추가 함수>
insert_first - 헤드 노드 앞에 노드를 추가하고 새 헤드를 리턴
insert - 특정 노드 위치 뒤에 새 노드를 추가하고 헤드를 리턴

<삭제 함수>
delete_first - 헤드 노드를 삭제하고 헤드 노드 뒤의 노드를 헤드로 리턴
delete - 특정 위치의 노드를 삭제하고 헤드를 리턴

*/

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = value;
    tmp->link = head;
    head = tmp;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = value;
    tmp->link = pre->link;
    pre->link = tmp;
    return head;
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) return NULL;
    ListNode* removed = head;
    head = head->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link) {
        printf("%d ->", p->data);
    }
    printf("NULL\n");
}



/*
[링크드 리스트 뒤집기]

leadr는 길잡이 역할(기존 연결리스트를 순회하는 포인터)
new_head는 새로 리턴할 헤드 노드를 가리키는 포인터
tail은 노드를 임시로 저장하는 포인터

*/
ListNode* reverse(ListNode* head) {
    ListNode* new_head, * tail, * leader;
    leader = head;
    new_head = NULL;
    while (leader != NULL) {
        tail = new_head;
        new_head = leader;
        leader = leader->link;
        new_head->link = tail;
    }
    return new_head;
}

// 데이터 검색
ListNode* search_list(ListNode* head, element value) {
    ListNode* tmp = head;
    while (tmp != NULL) {
        if (tmp->data == value) return tmp;
        tmp = tmp->link;
    }
    return NULL;
}

// 두 링크드 리스트 합치기
ListNode* concat_list(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) return list2;
    else if (list2 == NULL) return list1;
    else {
        ListNode* tmp = list1;
        while (tmp->link != NULL) {
            tmp = tmp->link;
        }
        tmp->link = list2;
        return list1;
    }
}


int main(void) {
    ListNode* head = NULL;
    
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    ListNode* rever = reverse(head);
    print_list(rever);
    printf("\n%d\n", search_list(head, 4));

    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        print_list(head);
    }
    for (int i = 0; i < 5; i++) {
        head = delete_first(head, i);
        print_list(head);
    }

    // concat_list
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;
    printf("\nlist1\n");
    for (int i = 0; i < 5; i++) {
        list1 = insert_first(list1, i);
        print_list(list1);
    }
    printf("\nlist2\n");
    for (int i = 0; i < 5; i++) {
        list2 = insert_first(list2, i);
        print_list(list2);
    }
    printf("\nconcat_list\n");
    list1 = concat_list(list1, list2);
    print_list(list1);
    return 0;
}
