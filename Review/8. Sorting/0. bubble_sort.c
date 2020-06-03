#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX 10

void bubble_sort(int list[], int n){
    int i, j, tmp;
    int flag = 1;
    for (i = n - 1; i > 0 && flag == 1; i--) {       // range
        flag = 0;
        for (j = 0; j < i; j++) {       // travel
            if (list[j] > list[j + 1]) {    // check condition
                SWAP(list[j], list[j+1], tmp);
                flag = 1;
            }
        }
    }
}

void print_list(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
}

int main(void) {  
    int list[MAX];
    int n = MAX;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        list[i] = rand() % 100;
    }
    print_list(list, n);
    printf("\n");
    bubble_sort(list, n);
    print_list(list, n);
    return 0;
}
