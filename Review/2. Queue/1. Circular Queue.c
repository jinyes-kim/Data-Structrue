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
    q->front = q->rear = 0;
}

int is_full(QueueType* q) {
    return ( (q->rear + 1) % MAX == q->front);
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void print_queue(QueueType* q) {
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX;
            printf("%d ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("overflow");
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) error("underflow");
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}


int main(void) {
    QueueType q;
    init_queue(&q);
    enqueue(&q, 1);
    print_queue(&q);
    enqueue(&q, 2);
    print_queue(&q);
    enqueue(&q, 3);
    print_queue(&q);
    enqueue(&q, 4);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    enqueue(&q, 5);
    print_queue(&q);

    return 0;
}
