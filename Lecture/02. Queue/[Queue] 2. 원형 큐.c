#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5
/*
선형 큐

q->rear = (q->rear + 1) % MAX_SIZE;

전체 길이로 나눠서 앞에 빈 공백을 다시 재활용
따라서 is_full() 함수에 추가적인 작업이 필요함


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
    q->front = q->rear = 0;
}   

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return (q->front == (q->rear+1) % MAX_SIZE);
}

void enqueue(QueueType* q, element item){
    if (is_full(q)) error("Queue OverFlow");
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->queue[q->rear] = item;
}
element dequeue(QueueType* q) {
    if (is_empty(q)) error("Queue UnderFlow");
    q->front = (q->front + 1) % MAX_SIZE;
    return q->queue[q->front];
}

element peek(QueueType* q) {
    if (is_empty(q)) error("Queue UnderFolow");
    return q->queue[(q->front+1) % MAX_SIZE];
}

void print_Queue(QueueType* q, int enq, element item) {
    printf("\t");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == (q->front+1) % MAX_SIZE) printf("<");
        else printf(" ");

        if (i < q->front && q->front < q->rear) printf("_");
        else if (q->front < i && i <= q->rear) printf("%d", q->queue[i]);
        else if (i <= q->rear && q->rear < q->front) printf("%d", q->queue[i]);
        else if (q->front < i && q->rear < q->front) printf("%d", q->queue[i]);
        else printf("_");

        if (i == q->rear) printf("-");
        else printf(" ");
    }
    printf("%s[%d]\n", enq ? "꺼냄" : "추가", item);
}

int main(void) {
    QueueType q;
    init_Queue(&q);
    char token[10], buf[10];
    element item;

    while (1) {
        printf("==> ");
        scanf_s("%s", token, 10);
        if (strcmp(token, "end") == 0) break;
        if (strcmp(token, "enq") == 0) {
            scanf_s("%d", buf, 10);
            item = buf[0];
            enqueue(&q, item);
        }
        else item = dequeue(&q);
        print_Queue(&q, (strcmp(token, "deq")==0), item);
    }
    return 0;
}