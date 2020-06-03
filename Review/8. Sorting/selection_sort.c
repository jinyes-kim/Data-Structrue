#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX 10

void selection_sort(int list[], int n) {
    int i, j, least, tmp;
    for (i = 0; i < n-1; i++) {     // total travel
        least = i;
        for (j = i + 1; j < n; j++) {       // find minmum value
            if (list[j] < list[least]) least = j;
        }
        SWAP(list[i], list[least], tmp);    // exchange value
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
    selection_sort(list, n);
    print_list(list, n);
    return 0;
}
