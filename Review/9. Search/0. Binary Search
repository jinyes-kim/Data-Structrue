#include <stdio.h>
#include <stdlib.h>

// 시간복잡도 O(log2 N)
int list[];

int search_binary(int key, int low, int high) {
    int middle;
    while (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle]) return middle;
        else if (key > list[middle])
            low = middle + 1;
        else
            high = middle - 1;

    }
    return -1;
}
