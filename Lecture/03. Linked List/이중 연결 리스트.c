#include <stdio.h>
#include <stdlib.h>


/*
이중 연결 리스트

노드: left link, right link 수정
출력: 수정 없음
입력: 
        1.헤드 -> 노드 1
        2.헤드 -> 노드 2 -> 노드 1
        3.헤드 -> 노드 3 -> 노드 2 -> 노드 1

삭제:
        1.헤드 -> 노드 3 -> 노드 2 -> 노드 1
        2.헤드 -> 노드 2 -> 노드 1
        3 헤드 -> 노드 1

    
    헤드 바로 옆에 노드가 추가되면서, 양방향으로 링크를 갖는 구조다.
*/

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* llink;
    struct ListNode* rlink;
} ListNode;

// initialize head node
void init(ListNode* head) {
    head->llink = head;
    head->rlink = head;
}

// add new noew behind at before parameter
void insert(ListNode* before, element data) {
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->data = data;

    tmp->llink = before;
    tmp->rlink = before->rlink;
    before->rlink->llink = tmp;
    before->rlink = tmp;
}


void delete(ListNode* head, ListNode* removed) {
    if (head == NULL) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void print_list(ListNode* head) {
    ListNode* tmp = head->rlink;
    for (tmp; tmp != head; tmp = tmp->rlink) {
        printf("<- %d -> ", tmp->data);
    }
    printf("\n");
}

int main(void) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    init(head);

    for (int i = 0; i < 5; i++) {
        insert(head, i);
        print_list(head);
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        print_list(head);
        // head->rlink를 지우면
        // head->rlink의 rlink가 head의 rlink가 되는 구조
        delete(head, head->rlink);
    }
    free(head);
    return 0;
}
