#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct node {
    element vertext;
    struct node* link;
} node;

typedef struct graph {
    int size;
    node** header;
} graph;

//ADT

graph* init_graph(int n);
node* insert_tail(node* list, element item);
void add_edge(node* list, element v, element u);
void print_list(node* head);
void print_graph(graph* g);
void dfs(graph* g);
void dfs(graph* g);

//Queue
typedef struct Queue {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
}

void error(char* msg) {
    fprintf(stderr, msg);
    exit(1);
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return (q->rear + 1 >= MAX_QUEUE_SIZE);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("overflow");
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) error("underflow");
    return  q->data[++(q->front)];
}


graph* init_graph(int n) {
    graph* tmp = (graph*)malloc(sizeof(graph));
    tmp->header = (node**)malloc(sizeof(node*) * n);
    tmp->size = n;
    for (int i = 0; i < n; i++) {
        tmp->header[i] = NULL;
    }
    return tmp;
}

node* insert_tail(node* head, element item) {
    node* res = (node*)malloc(sizeof(node*));
    res->vertext = item;
    res->link = NULL;
    if (head == NULL) return res;
    
    node* tmp = head;
    while (tmp->link != NULL) {
        tmp = tmp->link;
    }
    tmp->link = res;
    return head;
}

void add_edge(graph* g, element v, element u) {
    g->header[v] = insert_tail(g->header[v], u);
    g->header[u] = insert_tail(g->header[u], v);
}

void print_list(node* head) {
    node* tmp = head;
    for (; tmp; tmp = tmp->link) {
        printf("%d ", tmp->vertext);
    }
    printf("\n");
}

void print_graph(graph* g) {
    for (int i = 0; i < g->size; i++) {
        printf("정점 [%d]: ", i);
        print_list(g->header[i]);
    }
}


int visited[100] = { 0 };
void reset_dummy() {
    for (int i = 0; i < 100; i++) {
        visited[i] = 0;
    }
}

void bfs(graph* g, int n) {
    int i;
    node* tmp;
    QueueType q;
    init_queue(&q);
    visited[n] = 1;
    printf("%d ", n);
    enqueue(&q, n);
    
    while (!is_empty(&q)) {
        i = dequeue(&q);
        for (tmp = g->header[i]; tmp; tmp = tmp->link) {
            if (visited[tmp->vertext] != 1) {
                visited[tmp->vertext] = 1;
                printf("%d ", tmp->vertext);
                enqueue(&q, tmp->vertext);
            }
        }
    }
}


int main(void) {
    srand(time(NULL));
    int n;
    printf("정점 개수: ");
    scanf_s("%d", &n);
    graph* g = init_graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (rand() % 5 == 0)
                add_edge(g, i, j);
        }
    }
    print_graph(g);

    reset_dummy();
    printf("탐색할 노드: ");
    scanf_s("%d", &n);
    bfs(g, n);
    return 0;
}
