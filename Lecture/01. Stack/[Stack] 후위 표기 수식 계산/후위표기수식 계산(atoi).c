#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int eval() {
    double v1, v2;
    char ch;
    char buf[10];
    char temp;

    stackType s;
    init_stack(&s);
    while(1) {
        scanf_s("%s", buf, 10);
        if (strcmp(buf, "end") == 0) break;
        ch = buf[0];
        if (ch != '+' && ch != '-' && ch != '/' && ch != '*') {
            temp = atoi(buf);
            push(&s, temp);
            print_stack(&s, buf);
        }
        else {
            v2 = pop(&s);
            v1 = pop(&s);
            switch (ch) {
            case '+': push(&s, v1 + v2); break;
            case '-': push(&s, v1 - v2); break;
            case '*': push(&s, v1 * v2); break;
            case '/': push(&s, v1 / v2); break;
            }
            print_stack(&s, buf);
        }
    }
    return pop(&s);
}

int main(void) {
    double result;
    printf(">>");
    result = eval();
    printf("Result: %2.f", result);
    return 0;
}