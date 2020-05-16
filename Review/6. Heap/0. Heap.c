#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
Basic Heap

to do next 
1. delete
2. heap sort

*/


typedef struct element {    // Node
    int key;
} element;

typedef struct HeapType {
    element heap[MAX];
    int size;
} HeapType;

void init(HeapType* h) {
    h->size = 0;
}

element create_node(int key) {
    element tmp;
    tmp.key = key;
    return tmp;
}

void insert_heap(HeapType* h, element item) {
    if (h->size == 0) {
        h->heap[1] = item;
        h->size = 2;
        return;
    }
    else {
        int parent, child;
        child = h->size++;
        parent = child / 2;
        while (child != 1 && item.key < h->heap[parent].key) {
            if (item.key < h->heap[parent].key) {
                h->heap[child] = h->heap[parent];
                child /= 2;
                parent = child / 2;
            }
        }
        h->heap[child] = item;
        return;
    }
}

void print_heap(HeapType* h) {
    printf("Heap: ");
    for (int i = 1; i < h->size; i++) {
        printf("[%d] ", h->heap[i].key);
    }
}

int main(void) {
    HeapType h;
    init(&h);
    insert_heap(&h, create_node(1));
    insert_heap(&h, create_node(3));
    insert_heap(&h, create_node(4));
    insert_heap(&h, create_node(2));
    print_heap(&h);
}
