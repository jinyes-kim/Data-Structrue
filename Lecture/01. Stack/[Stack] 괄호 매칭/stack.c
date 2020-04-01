#include "stack.h"

void init_stack(stackType* s) {
    s->top = -1;
    s->capacity = 8;
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
        s->capacity *= 2;
        s->stack = (element*)realloc(s->stack, s->capacity * sizeof(element));
        printf("\n*** Extend Array %d => %d ***\n\n", s->capacity / 2, s->capacity);
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

void print_stack(stackType* s, const char* ch) {
    printf("%-20s [stack]", ch);
    for (int i = 0; i <= s->top; i++) {
        printf("%2c ", s->stack[i]);
    }
    printf("\n");
}