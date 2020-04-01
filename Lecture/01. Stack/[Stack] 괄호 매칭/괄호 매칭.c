#include "stack.h"
#include <string.h>
#include <stdio.h>

int check_matching(const char* input) {
    int i, n = strlen(input);
    char ch, open_ch;

    stackType s;
    init_stack(&s);
    print_stack(&s, input);

    for (i = 0; i < n; i++) {
        ch = input[i];
        switch (ch) {
        case '(': case '{': case '[':
            push(&s, ch);
            print_stack(&s, input + (i + 1));
            break;

        case ')': case '}': case ']':
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                print_stack(&s, input + (i + 1));
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '{' && ch != '}') ||
                    (open_ch == '[' && ch != ']')) {
                    return 0;
                }
                break;
            }
        default: break;
        }
    }
    if (!is_empty(&s)) return 0;
    return 1;
}

int main(void) {
    char buf[20];
    printf(">>");
    scanf_s("%s", buf, 20);
    if (check_matching(buf) == 1) {
        printf("Sucess\n");
    }
    else {
        printf("fail\n");
    }
    return 0;
}
 S