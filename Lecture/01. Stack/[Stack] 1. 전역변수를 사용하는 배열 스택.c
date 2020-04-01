#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
/*
전역 변수를 사용하는 배열 스택

단점
            1. 전역 변수를 많이 사용한다.

해결 방법
            1. 구조체를 활용해서 전역 변수 사용을 줄인다.

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