#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct element {
    int data;
} element;

typedef struct HeapType {
    element heap[MAX];
    int size;
} HeapType;


//ADT
HeapType* init_heap();
element create_node(int value);
void insert_heap();
element delete_heap();


HeapType* init_heap() {
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    tmp->size = 0;
    return tmp;
}

element create_node(int value) {
    element tmp;
    tmp.data = value;
    return tmp;
}

void insert_max_heap(HeapType* h, element node) {    
    int i = ++(h->size);
    while ( (i != 1) && (h->heap[i].data < h->heap[i / 2].data)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = node;
}

element delete_max_heap(HeapType* h) {

}

void print_heap(HeapType* h) {
    int end = h->size;
    for (int i = 1; i <= end; i++) {
        printf("%d ", h->heap[i].data);
    }
}

void heap_sort(element array[], int n) {
    HeapType* h = init_heap();

    for (int i = 0; i < n; i++) {
        insert_max_heap(h, array[i]);
    }
    for (int i = 0; i < n; i++) {
        array[i] = delete_max_heap(h);
    }
    free(h);
}

int main(void) {
    HeapType* h = init_heap();
    insert_max_heap(h, create_node(1));
    insert_max_heap(h, create_node(2));
    insert_max_heap(h, create_node(3));
    insert_max_heap(h, create_node(4));
    
    print_heap(h);



    return 0;
}
