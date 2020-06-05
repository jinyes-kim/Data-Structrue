#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;

typedef struct queueType {
    element queue[MAX];
    int front, rear;

} queueType;


//ADT

void error(queueType* q);
int is_empty(queueType* q);
int is_full(queueType* q);
void init_queue(queueType* q);
void enqueue(queueType* q, element item);
element dequeue(queueType* q);
void print_queue(queueType* q);

void error(char* msg) {
    fprintf(stderr, msg);
    exit(1);
}

int is_full(queueType* q) {
    return ( (q->rear + 1) % MAX) == q->front;
}

int is_empty(queueType* q) {
    return (q->front == q->rear);
}

void init_queue(queueType* q) {
    q->rear = 0;
    q->front = 0;
}

void enqueue(queueType* q, element item) {
    if (is_full(q)) error("큐가 다 찼다");
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = item;
}

element dequeue(queueType* q) {
    if (is_empty(q)) error("큐에 요소가 없다");
    element res = q->queue[++(q->front)];
    return res;
}

void add_front(queueType* q, element item) {
    if (is_full(q)) error("큐가 꽉 찼다.");
    q->queue[q->front] = item;
    q->front = (q->front - 1 + MAX) % MAX;
}

element delete_rear(queueType* q) {
    if (is_empty(q)) error("큐에 요소가 없다.");
    element res = q->queue[q->rear];
    q->rear = (q->rear - 1 + MAX) % MAX;
    return res;
}

void print_queue(queueType* q) {
    int i = q->front+1;
    while(i != q->front) {
        printf("%d ", q->queue[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(void) {
    queueType q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    print_queue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    print_queue(&q);

    enqueue(&q, 5);
    enqueue(&q, 6);

    add_front(&q, 7);
    print_queue(&q);

    delete_rear(&q);
    delete_rear(&q);
    print_queue(&q);




    return 0;
}
