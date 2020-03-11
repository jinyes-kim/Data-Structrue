void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];
	int count;
} priorityQueue;

void push(priorityQueue* queue, int data) {
	if (queue->count >= MAX_SIZE) return;
	queue->heap[queue->count] = data;
	int now = queue->count;
	int parent = (queue->count - 1) / 2;
	while (now > 0 && queue->heap[now] > queue->heap[parent]) {
		swap(&queue->heap[now], &queue->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	queue->count++;
}

int pop(priorityQueue* queue) {
	if (queue->count <= 0) return -9999;
	int res = queue->heap[0];
	queue->count--;
	queue->heap[0] = queue->heap[queue->count];
	int now = 0, leftchild = 1, rightchild = 2;
	int target = now;

	while (leftchild < queue->count) {
		if (queue->heap[target] < queue->heap[leftchild]) target = leftchild;
		if (queue->heap[target] < queue->heap[rightchild] && rightchild < queue->count)\
			target = rightchild;
		if (now == target) break;
		else {
			swap(&queue->heap[now], &queue->heap[target]);
			now = target;
			leftchild = now * 2 + 1;
			rightchild = now * 2 + 2;
		}
	}
	return res;
}

int main(void) {
	int n, data;
	priorityQueue pq;
	pq.count = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}

	for (int i = 0; i < n; i++) {
		int data = pop(&pq);
		printf("%d ", data);
	}
	return 0;
}
