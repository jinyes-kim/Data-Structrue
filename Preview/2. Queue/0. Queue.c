#include <stdio.h>
#include <stdlib.h>
# define MAX 5
/*
선형 큐 구현

큐는 배열을 사용하는 자료구조

어디를 포인터로 접근할지
어디를 필드로 접근할지 생각하기

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

    // 큐는 fifo first in first out
    // [] [] [] [] [] []
    element res = head->data[head->front];
    head->front += 1;
    return res;

    /*
    해당 구조는 디큐를 하면 front로 눈속임을 하므로 배열에서
    요소가 진짜로 사라지지는 않는다.
    */
}

void print_queue(QueueType* head) {
    for (int i = head->front; i < head->rear; i++) {
        if (head->front == i) printf("-> ");
        printf("%d ", head->data[i]);
    }
}

// 우선 큐가 만들어지는지 확인하기
// 디큐 인큐 확인하기

int main(void) {
    QueueType queue;
    /*
    큐 구조체를 선언
    해당 구조체에는 배열과 front, tail 이 있다.
    배열은 queue 선언과 함께 MAX 크기로 초기화된다.

    */
    init_queue(&queue);
    // 큐의 front, rear 를 0으로 초기화해주는 함수
    // 배열은 선언과 동시에 초기화되므로 초기화해줄 필요가 없다.

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