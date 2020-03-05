#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node* prev;
} Node;

typedef struct {
    struct Node* top;
} Stack;

void push(Stack* stack, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = stack->top;
    stack->top = node;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("스택 언더플로우");
        return -INF;
    }
    Node* node = stack->top;
    int data = node->data;
    stack->top = node->prev;
    free(node);
    return data;
}

void show(Stack* stack) {
    Node* cur = stack->top;
    printf("최상단\n");
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->prev;
    }
    printf("최하단\n");
}

int main(void) {
    Stack s;
    s.top = NULL;
    push(&s, 7);
    push(&s, 5);
    push(&s, 4);
    push(&s, 3);
    pop(&s);
    show(&s);
    system("pause");
    return 0;
}