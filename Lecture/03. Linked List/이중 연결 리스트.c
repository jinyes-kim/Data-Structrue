#include <stdio.h>
#include <stdlib.h>


/*
���� ���� ����Ʈ

���: left link, right link ����
���: ���� ����
�Է�: 
        1.��� -> ��� 1
        2.��� -> ��� 2 -> ��� 1
        3.��� -> ��� 3 -> ��� 2 -> ��� 1

����:
        1.��� -> ��� 3 -> ��� 2 -> ��� 1
        2.��� -> ��� 2 -> ��� 1
        3 ��� -> ��� 1

    
    ��� �ٷ� ���� ��尡 �߰��Ǹ鼭, ��������� ��ũ�� ���� ������.
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
        // head->rlink�� �����
        // head->rlink�� rlink�� head�� rlink�� �Ǵ� ����
        delete(head, head->rlink);
    }
    free(head);
    return 0;
}
