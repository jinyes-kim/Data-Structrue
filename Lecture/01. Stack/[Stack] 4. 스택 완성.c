#include <stdio.h>
#include <stdlib.h>

/*
동적 배열 스택 완성 코드

추가
            1. void delete_stack
            2. void print_stack
            3. 구조체를 포인터로 선언

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
void print_stack(stackType* s);

int main(void) {
    stackType *s;
    s = (stackType*)malloc(sizeof(stackType));
    init_stack(s);
    for (int i = 1; i <= 10; i++) {
        push(s, i*i);
        print_stack(s, i*i);
    }
    printf("peek: %d\n", peek(s));
    for (int i = 0; i <= 10; i++) {
        printf("pop: %-10d", pop(s));
        print_stack(s, pop(s));
    }
    delete_stack(s);
}

void init_stack(stackType* s) {
    s->top = -1;
    s->capacity = 8;    // 처음 배열의 크기는 8
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
        realloc 함수로 배열의 크기를 확장한다. 
        파라미터 옵션
        기존 배열, 변경할 크기
        */
        s->capacity *= 2;
        s->stack = (element*)realloc(s->stack, s->capacity * sizeof(element));
        printf("\n*** Extend Array %d => %d ***\n\n", s->capacity/2, s->capacity);
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

void print_stack(stackType* s, element item) {
    printf("%-20d [stack]", item);
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}