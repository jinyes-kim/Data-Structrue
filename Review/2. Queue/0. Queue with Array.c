#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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
    q->front = -1;
    q->rear = -1;
}

int is_full(QueueType* q) {
    return (q->rear + 1 >= MAX);
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
    if (is_full(q)) error("overflow");
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
    enqueue(&q, 10);
    print_queue(&q);
    enqueue(&q, 20);
    print_queue(&q);
    enqueue(&q, 30);
    print_queue(&q);
    enqueue(&q, 40);
    print_queue(&q);

    printf("\ndequeue start\n");
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    return 0;
}
