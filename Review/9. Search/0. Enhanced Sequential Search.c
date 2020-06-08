#include <stdio.h>
#include <stdlib.h>

int list[];

int seq_search(int key, int low, int high) {
    int i;
    list[high + 1] = key;
    for (i = low; list[i] != key; i++)
        ;
    if (i == (high+1)) return -1;
    else return i;
}
