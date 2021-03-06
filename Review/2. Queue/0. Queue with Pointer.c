#include <stdio.h>
#include <stdlib.h>

/*
포인터를 이용해서 계속 크기를 늘려가는 큐

하지만 디큐를 할수록 공간 낭비가 심해진다.
원형큐로 이런 문제를 해결할 수 있다.

*/
typedef int element;

typedef struct QueueType {
    element* data;
    int front, rear, capacity;
} QueueType;


void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void init_queue(QueueType* q) {
    q->capacity = 3;
    q->data = (element*)malloc(sizeof(element) * q->capacity);
    q->front = -1;
    q->rear = -1;
}

int is_full(QueueType* q) {
    return (q->rear + 1 >= q->capacity);
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void print_queue(QueueType* q) {
    for (int i = q->front+1; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        q->capacity *= 2;
        q->data = (element*)realloc(q->data, sizeof(element) * q->capacity);
        printf("\nExpand Memory\n");
    }
    q->data[++q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) error("underflow");
    element res = q->data[++(q->front)];
    return res;
}


int main(void) {
    QueueType q;
    init_queue(&q);

    for (int i = 1; i < 10; i++) {
        enqueue(&q, i * 10);
        print_queue(&q);
    }
    printf("\ndequeue start\n");
    for (int i = 0; i < 10; i++) {
        dequeue(&q);
        print_queue(&q);
    }
    return 0;
}
