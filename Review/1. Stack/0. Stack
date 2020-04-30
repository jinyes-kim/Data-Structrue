#include <stdio.h>
#include <stdlib.h>
# define MAX 5
typedef int element;

/*
스택

스택을 구현할 때 배열과, 포인터 배열로 선언하는 것의 차이에 대해서
차이점을 정확히 기억하기

*/

typedef struct StackType {
    element* data;
    int top, capacity;
} StackType;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int is_full(StackType* s) {
    return (s->top + 1 >= MAX) ;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

void init_stack(StackType* s) {
    s->capacity = 5;
    s->data = (element*)malloc(sizeof(element) * s->capacity);
    s->top = -1;
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
        printf("\nrealloc memory\n\n");
    }
    s->data[++(s->top)] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) error("underflow");
    element res = s->data[s->top];
    s->top--;
    return res;
}

void print_stack(StackType* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(void) {
    StackType s;
    init_stack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    print_stack(&s);
    push(&s, 50);
    print_stack(&s);
    push(&s, 60);
    print_stack(&s);
    
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);
    pop(&s);
    print_stack(&s);    
    pop(&s);
    print_stack(&s);
    return 0;
}


