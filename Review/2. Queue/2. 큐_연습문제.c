/*
교재 169~170p
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
    int id;
    int arrival_time;
    int service_time;
}element;

typedef struct Dequeue {
    element data[MAX];
    int front, rear;
} Deque;

//ADT
void error(char* msg);
int is_full(Deque* d);
int is_empty(Deque* d);
void init_deque();
void print_deque(Deque* d);
void add_rear(Deque* d, element item);
void add_front(Deque* d, element item);
element delete_rear(Deque* d);
element delete_front(Deque* d);

void error(char* msg) {
    fprintf(stderr, msg);
    exit(1);
}

void init_deque(Deque* d) {
    d->front = 0;
    d->rear = 0;
}

int is_full(Deque* d) {
    return ((d->rear + 1) % MAX) == d->front;
}

int is_empty(Deque* d) {
    return (d->front == d->rear);
}

void print_dequ(Deque* d) {
    int i = d->front;
    do {
        i = (i + 1) % MAX;
        printf("%d ", d->data[i]);
        if (i == d->rear) {
            break;
        }
    } while (i != d->front);
    printf("\n");
}

void add_rear(Deque* d, element item) {
    if (is_full(d)) error("overflow");
    d->rear = (d->rear + 1) % MAX;
    d->data[d->rear] = item;
}

void add_front(Deque* d, element item) {
    if (is_full(d)) error("overflow");
    d->data[d->front] = item;
    d->front = (d->front - 1 + MAX) % MAX;
}

element delete_rear(Deque* d) {
    if (is_empty(d)) error("underflow");
    element res = d->data[d->rear];
    d->rear = (d->rear - 1 + MAX) % MAX;
    return res;
}

element delete_front(Deque* d) {
    if (is_empty(d)) exit("underflow");
    d->front = (d->front + 1) % MAX;
    return d->data[d->front];
}

int main(void) {
    int minutes = 60;
    int total_customer = 0;
    int service_time = 0;
    int total_wait = 0;
    int service_customer;
    Deque q;
    init_deque(&q);
    srand(time(NULL));
    for (int i = 0; i < minutes; i++) {
        if ((rand() % 3) < 3) {
            element customer;
            customer.id = total_customer++;
            customer.arrival_time = i;
            customer.service_time = (rand() % 3) + 1;
            add_rear(&q, customer);
            printf("%d번 고객 %d분 입장 / 소요시간 %d분\n",
                customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) {
            printf("%d번 고객 업무 처리중\n", service_customer);
            service_time--;
        }
        else {
            if (!is_empty(&q)) {
                element customer = delete_front(&q);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("%d번 고객 업무시작 /대기시간 %d분 /소요시간 %d분\n",
                    service_customer, i - customer.arrival_time, customer.service_time);
                total_wait = i - customer.arrival_time;
            }
        };
    }
    printf("전체 대기시간 %d분\n", total_wait);
    return 0;
}
