#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct element {
    int data;
} element;

typedef struct HeapType {
    element* heap;
    int size;
} HeapType;


//ADT
HeapType* init_heap(int n);
element create_node(int value);
void insert_heap();
element delete_heap();


HeapType* init_heap(int n) {
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    tmp->size = 0;
    tmp->heap = (element*)malloc(sizeof(element) * (n+1));
    return tmp;
}

element create_node(int value) {
    element tmp;
    tmp.data = value;
    return tmp;
}

void insert_max_heap(HeapType* h, element node) {    
    int i = ++(h->size);
    while ( (i != 1) && (node.data > h->heap[i / 2].data)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = node;
}

element delete_max_heap(HeapType* h) {
    element res = h->heap[1];
    element tmp = h->heap[(h->size)--];

    int parent = 1;
    int child = 2;

    while (child <= h->size) {
        if (child < h->size &&
            h->heap[child].data < h->heap[child + 1].data) {
            child++;
        }
        if (tmp.data > h->heap[child].data) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = tmp;
    return res;
}

void print_heap(HeapType* h) {
    int end = h->size;
    for (int i = 1; i <= end; i++) {
        printf("%d ", h->heap[i].data);
    }
}

void heap_sort(element array[], int n) {
    HeapType* h = init_heap(n);


    for (int i = 0; i < n; i++) {
        insert_max_heap(h, array[i]);
    }
    for (int i = 0; i < n; i++) {
        array[i] = delete_max_heap(h);
    }
    free(h);
}

void print_list(element array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i].data);
    }
    printf("\n");
}

int main(void) {
    int count;
    int n;
    printf("개수 => ");
    scanf_s("%d", &count, 2);
    element* data = (element*)malloc(sizeof(element) * count);
    for (int i = 0; i < count; i++) {
        printf("=> ");
        scanf_s("%d", &n, 2);
        data[i] = create_node(n);
    }
    print_list(data, count);
    heap_sort(data, count);
    print_list(data, count);
    return 0;
}
