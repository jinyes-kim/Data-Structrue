#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    char name[10];
    int score[3];
    double avg; // key
} student_t;

typedef student_t* element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
    int (*gt)(element, element);    //�Լ� ������
} HeapType;

// *���� �迭�� �����ϴ� element Ÿ���� �Ķ����
int gt_avg(element e1, element e2) {
    return e1->avg > e2->avg;
}

int gt_name(element e1, element e2) {
    return strcmp(e1->name, e2->name) > 0;
}

// ���� �Լ�
HeapType* create(int (*gt)(element, element))
{
    HeapType* tmp = (HeapType*)malloc(sizeof(HeapType));
    tmp->gt = gt;
    return tmp;
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
    h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    //  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
    while ((i != 1) && (h->gt(item, h->heap[i / 2]))) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        // ���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã�´�.
        if ((child < h->heap_size) &&
            (h->gt(h->heap[child + 1], h->heap[child])))
            child++;
        if (h->gt(temp, h->heap[child])) break;
        // �� �ܰ� �Ʒ��� �̵�
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n, int (*gt)(element, element))
{
    int i;
    HeapType* h;

    h = create(gt);
    init(h);
    for (i = 0; i < n; i++) {
        insert_max_heap(h, a[i]);
    }
    for (i = (n - 1); i >= 0; i--) {
        a[i] = delete_max_heap(h);
    }
    free(h);
}

element read_student() {
    int sub1, sub2, sub3;
    char name[10];
    //��ü ����
    element tmp = (element)malloc(sizeof(student_t)); // student_t*�� ĳ���� ����

    scanf_s("%s", &name, 10);
    scanf_s("%d %d %d", &sub1, &sub2, &sub3);
    strcpy(tmp->name, name);
    tmp->score[0] = sub1;
    tmp->score[1] = sub2;
    tmp->score[2] = sub3;
    tmp->avg = (double)(sub1 + sub2 + sub3) / 3; // why this green line?
    return tmp;
}

void print_student(element s) {
    printf("\t%s\t%d\t%d\t%d\t(%.2f)\n", s->name, s->score[0],
        s->score[1], s->score[2], s->avg);
}

#define SIZE 8
int main(void)
{
    element ptr_list[SIZE]; // ptr array
    int n;
    //element st;
    scanf_s("%d", &n);      // repeat number

    for (int i = 0; i < n; i++) {
        ptr_list[i] = read_student();   // no addr, just data
    }

    heap_sort(ptr_list, n, gt_avg);
    printf("\n======= ��� ������ ��� =======\n");

    for (int i = 0; i < n; i++) {
        print_student(ptr_list[i]);
    }

    heap_sort(ptr_list, n, gt_name);
    printf("\n======= �̸� ������ ��� =======\n");

    for (int i = 0; i < n; i++) {
        print_student(ptr_list[i]);
    }
    return 0;
}