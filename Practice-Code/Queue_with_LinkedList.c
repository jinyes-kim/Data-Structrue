#include <stdio.h>
#include <stdlib.h>
#define INF 999999

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* back;
	int count;
} Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->back->next = node;
	}
	queue->back = node;
	queue->count++;
}

int pop(Queue* queue) {
	Node* node = (Node*)malloc(sizeof(Node));
	node = queue->front;
	if (queue->count <= 0) {
		printf("Queue Underflow\n");
		return -INF;
	}
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}

void show(Queue* queue) {
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = queue->front;
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}


int main() {
	Queue q;
	q.count = 0;
	q.front = q.back = NULL;
	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	push(&q, 5);
	pop(&q);
	show(&q);
	pop(&q);
	pop(&q);
	pop(&q);
	pop(&q);
	pop(&q);
	pop(&q);

	return 0;
}