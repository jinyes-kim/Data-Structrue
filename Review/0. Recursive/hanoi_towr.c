#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void move(int n, char from, char to) {
    printf("원판%d을 %c에서 %c로 이동합니다.\n", n, from, to);
}
void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) move(n, from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        move(n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}
int main(void) {
    hanoi_tower(3, 'A', 'B', 'C');
    return 0;
  
}
