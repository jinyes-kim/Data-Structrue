#include <stdio.h>
#include <stdlib.h>

/*
이중 연결 리스트

노드들이 양방향으로 연결된 리스트

***아래 코드에서 head 노드는 항상 NULL이다.***

insert, delete 함수가 특정 노드를 기준으로 삭제하므로 헤드를 리턴하지 않아도 된다.
head는 처음 동적할당 하고, 초기화 하고 이후에 변경하지 않는다. (변경 못하도록 막는다)


*/

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* rlink;
    struct ListNode* llink;
} ListNode;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void init(ListNode* head) {
    head->rlink = head->llink = head;
}

// before 노드 다음에 새로운 노드를 추가
void insert(ListNode* before, element value) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = value;
    tmp->llink = before;
    tmp->rlink = before->rlink;
    before->rlink->llink = tmp;
    before->rlink = tmp;
}

// 노드 removed를 삭제한다.
void delete(ListNode* head, ListNode* removed) {
    if (removed == head) {
        printf("! head can't remove !"); // 원형 구조이므로 삭제 하다보면 헤드까지 삭제할 수 있다. *헤드 삭제 방지
        return;
    }
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void print_list(ListNode* head) {
    // head 노드는 항상 NULL
    ListNode* tmp = head;
    for (tmp = head->rlink; tmp != head; tmp = tmp->rlink) {
        printf("%d ", tmp->data);
    }
    // tmp->data는 쓰레기 값
    // tmp 는 헤드 (메모리 주소)
    // printf("%d", tmp->data); 
    printf("\n");
}

int main(void) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    init(head); // 좌우 링크 초기화

    printf("add node\n");
    for (int i = 0; i < 5; i++) {
        insert(head, i);
        print_list(head);
    }
    printf("\nremove node\n");
    for (int i = 0; i < 6; i++) {
        print_list(head);
        delete(head, head->rlink);   
    }
    free(head);
    return 0;
}
