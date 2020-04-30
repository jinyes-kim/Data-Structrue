#include <stdio.h>
#include <stdlib.h>

/*
기본 연결 리스트 (헤더, 양방향)

노드(구조체) -> 노드(구조체) -> 노드(구조체)...
와 같은 구조

그리고 위와 같은 연결 리스트의 헤드와 테일 노드의
주소를 갖는 헤더 타입 구조체

*/
typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* llink;
    struct ListNode* rlink;
} ListNode;

typedef struct ListType {
    ListNode* head;
    ListNode* tail;
    int size;
} ListType;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int is_empty(ListType* head) {
    return (head->head == NULL);
}

// *초기화 함수
// 해당 구조체를 초기화 하고 할당해주는 용도
ListType* init_link() {
    ListType* head = (ListType*)malloc(sizeof(ListType));
    // head = NULL 때려버리면 밑에서 필드에 접근 자체가 불가능하다. 주의하기
    head->tail = NULL;
    head->head = NULL;
    head->size = 0;
    return head;

    /*
    헤더를 사용하지 않고 노드를 초기화해주는 함수라면
    head = NULL 과 같은 형태로 접근해야 할 듯
    */
}

void insert_last(ListType* head, element item) {
    // 추가할 새로운 노드를 동적할당 한다.
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));

    tmp->data = item; tmp->rlink = NULL;

    // case1 head is NULL
    if (head->tail == NULL) {
        tmp->llink = NULL;
        head->tail = tmp;
        head->head = tmp;
        head->size++;
        return;
    }
    // case2 head is not NULL
    ListNode* ptr = head->head;
    while (ptr->rlink != NULL) {
        ptr = ptr->rlink;
    }
    ptr->rlink = tmp;
    tmp->llink = ptr;
    //tmp->rlink = head->head;
    head->tail = tmp;
    head->size++;
}

void remove_last(ListType* head) {
    // case1 delete last one
    if (head->size == 1) {
        head->head = NULL; head->tail == NULL;  // 헤더의 헤드와 테일 초기화
        head->size--;
        return;
    }

    // case2 else
    ListNode* tmp = head->head;
    while (tmp->rlink->rlink != NULL) {
        tmp = tmp->rlink;
    }
    ListNode* removed = tmp->rlink;
    tmp->rlink = NULL;
    free(removed);
    head->tail = tmp;
    head->size--;
}

void print_list(ListType* head) {
    if (is_empty(head)) error("empty list");
    ListNode* tmp = head->head;
    printf("[List size: %d]\n", head->size);
    while (tmp->rlink != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->rlink;
    }
    printf("%d\n\n", tmp->data);
}

int main(void) {
    // list1 이라는 헤더 타입을 초기화해준다.
    ListType* list1;
    list1 = init_link();

    // insert_last 함수를 사용하면 자동으로 헤드와 테일에 새 노드 지정
    insert_last(list1, 10);
    insert_last(list1, 20);
    print_list(list1);
    insert_last(list1, 30);
    print_list(list1);

    remove_last(list1);
    print_list(list1);
    remove_last(list1);
    print_list(list1);
    remove_last(list1);
    print_list(list1);
    return 0;
}