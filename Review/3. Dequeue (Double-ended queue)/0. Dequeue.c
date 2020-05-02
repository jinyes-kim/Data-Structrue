#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/*
덱 - 스택과 큐의 기능이 혼합된 자료구조

기본적인 구조는 원형큐 에서 앞, 뒤로 데이터 추가, 삭제가 가능한 구조다.

*** 원형 큐를 이해하면 스택, 큐, 덱이라는 세 가지 구조를 쉽게 이해할 수 있다. ***

*/

typedef int element;

typedef struct dequeue {
    element data[MAX];
    int front, rear;
} dequeue;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int is_full(dequeue* d) {
    return ((d->rear + 1) % MAX == d->front);
}

int is_empty(dequeue* d) {
    return (d->front == d->rear);
}

void init_dequeue(dequeue* d) {
    d->front = d->rear = 0;
}

void add_front(dequeue* d, element item) {
    if (is_full(d)) error("dequeue is full");
    // front 는 항상 비어있다는 구조를 응용한다.
    d->data[d->front] = item;
    d->front = (d->front - 1 + MAX) % MAX;
}

void add_rear(dequeue* d, element item) {
    if (is_full(d)) error("dequeue is full");
    d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = item;
}

element delete_front(dequeue* d) {
    if (is_empty(d)) error("dequeue is empty");
    // front 는 항상 비어있다는 구조를 응용한다.
    d->front = (d->front + 1) % MAX;
    return d->data[d->front];
}

element delete_rear(dequeue* d) {
    if (is_empty(d)) error("dequeue is empty");
    int prev = d->rear;
    d->rear = (d->rear - 1 + MAX) % MAX;
    return d->data[prev];
}

element get_front(dequeue* d) {
    if (is_empty(d)) error("dequeue is empty");
    return d->data[(d->front + 1) % MAX];
}

element get_rear(dequeue* d) {
    if (is_empty(d)) error("dequeue is empty");
    return d->data[d->rear];
}

void print_dequeue(dequeue* d) {
    if (!is_empty(d)) {
        int tmp = d->front;
        do {
            tmp = (tmp + 1) % MAX;
            printf("%d ", d->data[tmp]);
            if (d->rear == tmp)
                break;
        } while (tmp != d->front);
        printf("\n");
    }
}

int main(void) {
    dequeue d;
    init_dequeue(&d);

    add_front(&d, 3);
    add_front(&d, 4);
    print_dequeue(&d);

    add_rear(&d, 1);
    add_rear(&d, 2);
    print_dequeue(&d);

    delete_front(&d);
    print_dequeue(&d);

    delete_rear(&d);
    print_dequeue(&d);
        
    printf("\n%d\n", get_front(&d));
    printf("\n%d\n", get_rear(&d));
    return 0;
}
