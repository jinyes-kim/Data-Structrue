#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
/*
����ü�� Ȱ���� �迭 ����

����
            1. �迭�� ũ�⸦ ������ �� ����. 
            2. �޸� ������鿡�� ��ȿ�����̴�.

�ذ� ���
            1. ���� �迭 ����

*/


typedef int element;        // element is data tpye of stack, it is easy to adjust code 
typedef struct {
    element data[MAX_SIZE];
    int top;
} stackType;

void init_stack(stackType* s);
int is_full(stackType* s);
int is_empty(stackType* s);
void push(stackType* s, element item);
element pop(stackType* s);
element peek(stackType* s);

int main(void) {
    stackType s;
    init_stack(&s);
    for (int i = 1; i <= 6; i++) {
        push(&s, i*i);
    }
    printf("peek: %d\n", peek(&s));
    for (int i = 0; i <= 6; i++) {
        printf("pop: %d\n", pop(&s));
    }

}

void init_stack(stackType* s) {
    s->top = -1;
}

int is_full(stackType* s) {
    return (s->top >= (MAX_SIZE - 1));
}

int is_empty(stackType* s) {
    return (s->top == -1);
}

void push(stackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(stackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(stackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)];
}