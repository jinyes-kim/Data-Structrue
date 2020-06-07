#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
} element;

typedef struct HeapType {
    element* heap;
    int size;
} HeapType;


//ADT
HeapType* init_heap(int n);
element create_node(int item);
void insert_max_heap(HeapType* h, element item);
element delete_max_heap(HeapType* h);
void heap_sort(element list[], int n);
void print_heap(HeapType* h);
void print_list(element list[], int n);


HeapType* init_heap(int n) {
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    tmp->heap = (element*)malloc(sizeof(HeapType) * n);
    tmp->size = 0;
    return tmp;
}

element create_node(int item) {
    element tmp;
    tmp.data = item;
    return tmp;
}

void insert_max_heap(HeapType* h, element item) {
    int i = ++(h->size);
    while (i != 1 && item.data > h->heap[i / 2].data) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
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
        else {
            h->heap[parent] = h->heap[child];
            parent = child;
            child *= 2;
        }
    }
    h->heap[parent] = tmp;
    return res;
}

void heap_sort(element list[], int n) {
    HeapType* h = init_heap(n);
    for (int i = 0; i < n; i++) {
        insert_max_heap(h, list[i]);
    }
    //print_heap(h); 힙에 저장된 상태 
    for (int i = 0; i < n; i++) {
        list[i] = delete_max_heap(h);
    }
    free(h);
}

void print_heap(HeapType* h) {
    for (int i = 1; i <= h->size; i++) {
        printf("%d ", h->heap[i].data);
    }
    printf("\n");
}

void print_list(element list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i].data);
    }
    printf("\n");
}


int main(void) {
    element* data;
    int count;
    int n;
    printf("리스트 개수 => ");
    scanf_s("%d", &count, 2);
    data = (element*)malloc(sizeof(element) * count);
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
