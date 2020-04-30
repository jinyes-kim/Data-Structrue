#include <stdio.h>
#include <stdlib.h>
# define MAX 5
/*
선형 큐

큐는 배열을 사용하는 자료구조

따라서 구조체가 큐의 그릇이다.
그릇 안의 배열에서 데이터를 넣다 뺐다. 한다.
그 위치를 알려주는 게 구조체에 있는
front와 rear

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

    // 큐는 first in first out
    // [] [] [] [] [] []
    element res = q->data[q->front];
    q->front += 1;
    return res;

    /*
    해당 구조는 디큐를 하면 front로 눈속임을 하므로 배열에서
    요소가 진짜로 사라지지는 않는다.

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
    큐 구조체를 선언
    해당 구조체에는 배열과 front, tail 이 있다.
    배열은 queue 선언과 함께 MAX 크기로 초기화된다.

    */
    init_queue(&queue);
    // 큐의 front, rear 를 0으로 초기화해주는 함수
    // 구조체의 배열은 선언과 동시에 초기화되므로 초기화해줄 필요가 없다.

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