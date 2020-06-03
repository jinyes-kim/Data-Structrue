#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX 10

int partition(int list[], int left, int right) {
    int low, high;
    int pivot, tmp;
    pivot = list[left];
    low = left;
    high = right + 1;
    do {
        do {
            low++;  // find over number pivot
        } while (list[low] < pivot);

        do {
            high--; // find under number pivot
        } while (pivot < list[high]);
        if (low < high) {
            SWAP(list[low], list[high], tmp);
        }
    } while (low < high);
    SWAP(list[left], list[high], tmp);
    return high;
}

void quick_sort(int list[], int left, int right) {
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
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
    quick_sort(list, 0, n-1);
    print_list(list, n);
    return 0;
}
