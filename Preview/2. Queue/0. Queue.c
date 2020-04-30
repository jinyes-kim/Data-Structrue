#include <stdio.h>
#include <stdlib.h>
# define MAX 5
/*
���� ť ����

ť�� �迭�� ����ϴ� �ڷᱸ��

��� �����ͷ� ��������
��� �ʵ�� �������� �����ϱ�

*/
typedef int element;

typedef struct QueueType {
    element data[MAX];
    int front, rear;
} QueueType;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void init_queue(QueueType* head) {
    head->front = 0;
    head->rear = 0;
}

int is_full(QueueType* head) {
    return (head->rear + 1 == MAX);
}

int is_empty(QueueType* head) {
    return (head->front == head->front == 0);
}

void enqueue(QueueType* head, element item) {
    if (is_full(head)) {
        return error("Overflow");
    }
    if (is_empty(head)) {
        head->data[0] = item;
    }
    else {
        head->data[head->rear] = item;
    }
    head->rear++;
}

element dequeue(QueueType* head) {
    if (is_empty(head)) error("Underflow");

    // ť�� fifo first in first out
    // [] [] [] [] [] []
    element res = head->data[head->front];
    head->front += 1;
    return res;

    /*
    �ش� ������ ��ť�� �ϸ� front�� �������� �ϹǷ� �迭����
    ��Ұ� ��¥�� ��������� �ʴ´�.
    */
}

void print_queue(QueueType* head) {
    for (int i = head->front; i < head->rear; i++) {
        if (head->front == i) printf("-> ");
        printf("%d ", head->data[i]);
    }
}

// �켱 ť�� ����������� Ȯ���ϱ�
// ��ť ��ť Ȯ���ϱ�

int main(void) {
    QueueType queue;
    /*
    ť ����ü�� ����
    �ش� ����ü���� �迭�� front, tail �� �ִ�.
    �迭�� queue ����� �Բ� MAX ũ��� �ʱ�ȭ�ȴ�.

    */
    init_queue(&queue);
    // ť�� front, rear �� 0���� �ʱ�ȭ���ִ� �Լ�
    // �迭�� ����� ���ÿ� �ʱ�ȭ�ǹǷ� �ʱ�ȭ���� �ʿ䰡 ����.

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 30);
    print_queue(&queue);
    printf("\n");

    //
    dequeue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    return 0;
}