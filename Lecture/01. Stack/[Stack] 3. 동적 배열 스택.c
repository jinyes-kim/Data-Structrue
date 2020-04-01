#include <stdio.h>
#include <stdlib.h>

/*
���� �迭 ����

�迭�� ����� �������� �Ҵ��ϰ�, �迭�� �� ����
realloc �Լ��� ���� �迭�� ũ�⸦ ���� ��Ų��.

realloc(���� �迭, ������ ũ��)

*/


typedef int element;        // element is data tpye of stack, it is easy to adjust code 
typedef struct {
    element* stack;
    int top;
    int capacity;
} stackType;

void init_stack(stackType* s);
int is_full(stackType* s);
int is_empty(stackType* s);
void push(stackType*, element item);
element pop(stackType* s);
element peek(stackType* s);
void delete_stack(stackType* s);

int main(void) {
    stackType s;
    init_stack(&s);
    for (int i = 1; i <= 10; i++) {
        push(&s, i*i);
    }
    printf("peek: %d\n", peek(&s));
    for (int i = 0; i <= 10; i++) {
        printf("pop: %d\n", pop(&s));
    }
    delete_stack(&s);
}

void init_stack(stackType* s) {
    s->top = -1;
    s->capacity = 8;    // ó�� �迭�� ũ��� 8
    s->stack = (element*)malloc(sizeof(element) * s->capacity);
}

int is_full(stackType* s) {
    return (s->top >= (s->capacity - 1));
}

int is_empty(stackType* s) {
    return (s->top <= -1);
}

void push(stackType* s, element item) {
    if (is_full(s)) {
        /*
        realloc �Լ��� �迭�� ũ�⸦ Ȯ���Ѵ�. 
        �Ķ���� �ɼ�
        ���� �迭, ������ ũ��
        */
        s->capacity *= 2;
        s->stack = realloc(s->stack, s->capacity * sizeof(element));
        printf("%d\n", s->capacity);
    }
    s->stack[++(s->top)] = item;
}

element pop(stackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}

element peek(stackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    return s->stack[s->top];
}

void delete_stack(stackType* s) {
    free(s);
}