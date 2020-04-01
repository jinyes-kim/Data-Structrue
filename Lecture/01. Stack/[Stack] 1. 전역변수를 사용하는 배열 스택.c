#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
/*
���� ������ ����ϴ� �迭 ����

����
            1. ���� ������ ���� ����Ѵ�.

�ذ� ���
            1. ����ü�� Ȱ���ؼ� ���� ���� ����� ���δ�.

*/


typedef int element;        // element is data tpye of stack, it is easy to adjust code 
element stack[MAX_SIZE];
int top = -1;

int is_full();
int is_empty();
void push(element item);
element pop();
element peek();

int main(void) {
    for (int i = 1; i <= 6; i++) {
        push(i*i);
    }
    printf("peek: %d\n", peek());
    for (int i = 0; i <= 6; i++) {
        printf("pop: %d\n", pop());
    }

}

int is_full() {
    return (top >= (MAX_SIZE - 1));
}

int is_empty() {
    return (top == -1);
}

void push(element item) {
    if (is_full()) {
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

element pop() {
    if (is_empty()) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

element peek() {
    if (is_empty()) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return stack[top];
}