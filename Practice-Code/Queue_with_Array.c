#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int back = 0;

void push(int data) {
	if (back > SIZE) {
		printf("Queue Overflow\n");
	}
	queue[back++] = data;
}

int pop() {
	if (front == back) {
		printf("Queue Underflow\n");
	}
	return queue[front++];
}

void show() {
	for (int i = front; i < back; i++) {
		printf("%d\n", queue[i]);
	}
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	pop();
	show();
	pop();
	pop();
	pop();
	pop();
	pop();
	
	return 0;
}