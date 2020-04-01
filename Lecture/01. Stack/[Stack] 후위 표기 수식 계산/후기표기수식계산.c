#include "stack.h"
#include <string.h>
#include <stdio.h>


int eval(char* value) {
    int n = strlen(value);
    int v1, v2;
    char ch;

    stackType s;
    init_stack(&s);
    for (int i = 0; i < n; i++) {
        ch = value[i];
        if (ch != '+' && ch != '-' && ch != '/' && ch != '*') {
            ch = ch - '0';  // atoi
            push(&s, ch);
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
        }
    }
    return pop(&s);
}

int main(void) {
    int result;
    char buf[20];
    printf(">>");
    scanf_s("%s", buf, 20);
    result = eval(buf);
    printf("Result: %d", result);
    return 0;
}