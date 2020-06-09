#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion_sort(int list[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {   // travel
        key = list[i];          // check point
        for (j = i-1; j >= 0 && list[j] > key; j--) {
            list[j+1] = list[j];
        }
        list[j+1] = key;
        // * j+1 
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
    insertion_sort(list, n);
    print_list(list, n);
    return 0;
}
