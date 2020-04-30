#include <stdio.h>
#include <stdlib.h>

/*
�⺻ ���� ����Ʈ (���, �����)

���(����ü) -> ���(����ü) -> ���(����ü)...
�� ���� ����

�׸��� ���� ���� ���� ����Ʈ�� ���� ���� �����
�ּҸ� ���� ��� Ÿ�� ����ü

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

// *�ʱ�ȭ �Լ�
// �ش� ����ü�� �ʱ�ȭ �ϰ� �Ҵ����ִ� �뵵
ListType* init_link() {
    ListType* head = (ListType*)malloc(sizeof(ListType));
    // head = NULL ���������� �ؿ��� �ʵ忡 ���� ��ü�� �Ұ����ϴ�. �����ϱ�
    head->tail = NULL;
    head->head = NULL;
    head->size = 0;
    return head;

    /*
    ����� ������� �ʰ� ��带 �ʱ�ȭ���ִ� �Լ����
    head = NULL �� ���� ���·� �����ؾ� �� ��
    */
}

void insert_last(ListType* head, element item) {
    // �߰��� ���ο� ��带 �����Ҵ� �Ѵ�.
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
        head->head = NULL; head->tail == NULL;  // ����� ���� ���� �ʱ�ȭ
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
    // list1 �̶�� ��� Ÿ���� �ʱ�ȭ���ش�.
    ListType* list1;
    list1 = init_link();

    // insert_last �Լ��� ����ϸ� �ڵ����� ���� ���Ͽ� �� ��� ����
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