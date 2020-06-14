#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
} element;

typedef struct HeapType {
    element* heap;
    int size;
}HeapType;

//ADT
HeapType* init(int n);
void insert_max_heap(HeapType* root, element item);
element create_element(int n);
element delete_max_heap(HeapType* root);
void heap_sort(element list[], int n);
void print_heap(HeapType* root);
void print_list(element list[]);

HeapType* init(int n) {
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    tmp->heap = (element*)malloc(sizeof(element) * (n + 1));
    tmp->size = 0;
    return tmp;
}

element create_element(int n) {
    element tmp;
    tmp.data = n;
    return tmp;
}

void insert_max_heap(HeapType* root, element item) {
    int i = ++(root->size);
    while (i != 1 && item.data > root->heap[i / 2].data) {
        root->heap[i] = root->heap[i / 2];
        i /= 2;
    }
    root->heap[i] = item;
}

element delete_max_heap(HeapType* root) {
    element res = root->heap[1];
    element new_root = root->heap[(root->size)--];
    
    int parent = 1;
    int child = 2;

    while (child <= root->size) {
        if (child < root->size &&
            root->heap[child].data < root->heap[child+1].data) {
            child++;
        }
        if (new_root.data > root->heap[child].data) break;
        root->heap[parent] = root->heap[child];
        parent = child;
        child *= 2;
    }
    root->heap[parent] = new_root;
    return res;
}

void heap_sort(element list[], int n) {
    HeapType* h = init(n);
    for (int i = 0; i < n; i++) {
        insert_max_heap(h, list[i]);
    }
    for (int i = 0; i < n; i++) {
        list[i] = delete_max_heap(h);
    }
    free(h);
}

void print_list(element list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void print_heap(HeapType* root, int n) {
    for (int i = 1; i <= root->size; i++) {
        printf("%d ", root->heap[i]);
    }
    printf("\n");
}

int main(void) {
    int count, n;
    printf("데이터 개수: ");
    scanf_s("%d", &count);

    element* data = (element*)malloc(sizeof(element) * (count));
    for (int i = 0; i < count; i++) {
        printf("데이터: ");
        scanf_s("%d", &n);
        data[i] = create_element(n);
    }
    print_list(data, count);
    heap_sort(data, count);
    print_list(data, count);

    return 0;
}
