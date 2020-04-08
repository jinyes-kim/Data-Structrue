#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
/*
���� ť

��ť�� ���ڸ� ���� ��� �� ������ Ȱ���ϱⰡ ���� �ʴ�.
�ڵ忡�� ��ť�� 3���� �̾Ҵµ�, ��ť�� �ϸ� �����÷ο찡 ����.
ť �迭�� �����ʹ� ���� �����ϱ� �����̴�.

���� ���� ť�� �����Ͽ�, �������� ������ ��Ȱ���� �� �ְ� �����.

*/
typedef int element;

typedef struct {
    element queue[MAX_SIZE];
    int front, rear;
} QueueType;


void error(char* msg) {
    fprintf(stderr, "%s\n", msg);   // remind this point
    exit(1);
}

void init_Queue(QueueType* q) {
    q->front = q->rear = -1;
}   

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return (q->rear == MAX_SIZE-1);
}

void enqueue(QueueType* q, element item){
    if (is_full(q)) error("Queue OverFlow");
    q->queue[++q->rear] = item;
}
element dequeue(QueueType* q) {
    if (is_empty(q)) error("Queue UnderFlow");
    element res = q->queue[q->front + 1];
    q->front = q->front + 1;
    return res;
}

element peek(QueueType* q) {
    if (is_empty(q)) error("Queue UnderFolow");
    return q->queue[q->front + 1];
}

void print_Queue(QueueType* q) {
    for (int i = q->front+1; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}
int main(void) {
    QueueType q;
    init_Queue(&q);

    enqueue(&q, 1);
    print_Queue(&q);
    enqueue(&q, 2);
    print_Queue(&q);
    enqueue(&q, 3);
    print_Queue(&q);
    enqueue(&q, 4);
    print_Queue(&q);
    enqueue(&q, 5);
    print_Queue(&q);
    dequeue(&q);
    print_Queue(&q);
    dequeue(&q);
    print_Queue(&q);
    dequeue(&q);
    print_Queue(&q);
    enqueue(&q, 5);     
    print_Queue(&q);
    peek(&q);
    print_Queue(&q);
}