#include <stdio.h>
#include <string.h>
#define MAX_SIZE 5
#define ADD_F 1
#define ADD_R 2
#define REMOVE_F 3
#define REMOVE_R 4

typedef int element;

typedef struct {
    element queue[MAX_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q){
    q->front = q->rear = 0;
}

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int is_empty(QueueType* q) {
    return q->front == q->rear;
}

int is_full(QueueType* q) {
    return q->front == (q->rear + 1) % MAX_SIZE;
}

void print_queue(QueueType* q, int cmd, element item) {
    printf("\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == q->front) printf("<");
        else printf(" ");
        if (i < q->front && q->front < q->rear) printf("_");
        else if (q->front < i && i <= q->rear) printf("%d", q->queue[i]);
        else if (i <= q->rear && q->rear < q->front) printf("%d", q->queue[i]);
        else if (q->front < i && q->rear < q->front) printf("%d", q->queue[i]);
        else printf("_");
        if (i == q->rear) printf("-");
        else printf(" ");
    } 
    char* inout[] = { "Ãß°¡" , "²¨³¿" };
    printf("%s[%d]\n", inout[cmd / 3], item);

}

void add_rear(QueueType* q, element item) {
    if (is_full(q)) error("overflow");
    q->rear = (q->rear + 1) % MAX_SIZE; // same condition is_full
    q->queue[q->rear] = item;
}

void add_front(QueueType* q, element item) {
    if (is_full(q)) error("overflow");
    q->queue[q->front] = item;
    q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}

element delete_rear(QueueType* q) {
    if (is_empty(q)) error("underfolw");
    element res = q->queue[q->rear];
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return res;
}

element delete_front(QueueType* q){
    if (is_empty(q)) error("underflow");
    q->front = (q->front + 1) % MAX_SIZE;
    return q->queue[q->front];
}

element peek_rear(QueueType* q) {
    if (is_empty(q)) error("underflow");
    return q->queue[q->rear];
}

element peek_front(QueueType* q) {
    if ((is_empty(q))) error("underflow");
    return q->queue[(q->front + 1) % MAX_SIZE];
}

int main(void) {
    QueueType queue;
    element e;
    int command;
    init_queue(&queue);
    const char* cmd_str[] = { "add_front", "add_rear", "delete_front", "delete_rear" };
    printf("(1) add_front (2) add_rear \n(3) delete_front (4) delete_rear  (0) end  \n");
    
    while (1) {
        printf("=> ");
        scanf_s("%d", &command);
        if (command == 0) break;
        switch (command) {
        case ADD_F: scanf_s("%d", &e); add_front(&queue, e); break;
        case ADD_R: scanf_s("%d", &e); add_rear(&queue, e); break;
        case REMOVE_F: e = delete_front(&queue); break;
        case REMOVE_R: e = delete_rear(&queue); break;
        default: continue;
        }
        printf("%-13s", cmd_str[command - 1]);
        print_queue(&queue, command, e);

  
    }
    return 0;
}