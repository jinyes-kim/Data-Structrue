#include <stdio.h>
#include <stdlib.h>
# define MAX 5
/*
���� ť

ť�� �迭�� ����ϴ� �ڷᱸ��

���� ����ü�� ť�� �׸��̴�.
�׸� ���� �迭���� �����͸� �ִ� ����. �Ѵ�.
�� ��ġ�� �˷��ִ� �� ����ü�� �ִ�
front�� rear

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

void init_queue(QueueType* q) {
    q->front = 0;
    q->rear = 0;
}

int is_full(QueueType* q) {
    return (q->rear + 1 == MAX);
}

int is_empty(QueueType* q) {
    return (q->rear == 0);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        return error("Overflow");
    }
    if (is_empty(q)) {
        q->data[0] = item;
    }
    else {
        q->data[q->rear] = item;
    }
    q->rear++;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) error("Underflow");

    // ť�� first in first out
    // [] [] [] [] [] []
    element res = q->data[q->front];
    q->front += 1;
    return res;

    /*
    �ش� ������ ��ť�� �ϸ� front�� �������� �ϹǷ� �迭����
    ��Ұ� ��¥�� ��������� �ʴ´�.

    */
}

void print_queue(QueueType* q) {
    if (is_empty(q)) error("empty queue");
    for (int i = q->front; i < q->rear; i++) {
        if (q->front == i) printf("-> ");
        printf("%d ", q->data[i]);
    }
}

int main(void) {
    QueueType queue;
    /*
    ť ����ü�� ����
    �ش� ����ü���� �迭�� front, tail �� �ִ�.
    �迭�� queue ����� �Բ� MAX ũ��� �ʱ�ȭ�ȴ�.

    */
    init_queue(&queue);
    // ť�� front, rear �� 0���� �ʱ�ȭ���ִ� �Լ�
    // ����ü�� �迭�� ����� ���ÿ� �ʱ�ȭ�ǹǷ� �ʱ�ȭ���� �ʿ䰡 ����.

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 30);
    print_queue(&queue);
    printf("\n");

    dequeue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    return 0;
}