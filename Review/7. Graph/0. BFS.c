#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct QueueType {
    element data[MAX];
    int front, rear;
} QueueType;


void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void init_queue(QueueType* q) {
    q->front = -1;
    q->rear = -1;
}

int is_full(QueueType* q) {
    return (q->rear + 1 >= MAX);
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

void print_queue(QueueType* q) {
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("overflow");
    q->data[++q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) error("underflow");
    element res = q->data[++(q->front)];
    return res;
}

//Graph 
typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX];
} GraphType;

void init_graph(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX; v++) {
        g->adj_list[v] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX){
        fprintf(stderr, "그래프 정점 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while (p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void free_adj_list(GraphType* g) {
    //printf("그래프: 메모리 해제\n");
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        while (p != NULL) {
            GraphNode* removed = p;
            p = p->link;
            free(removed);
        }
    }
}

int visited[MAX];

void bfs(GraphType* g, int v) {
    GraphNode* w;
    QueueType q;

    init_queue(&q);
    visited[v] = TRUE;
    printf("%d -> ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = g->adj_list[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                visited[w->vertex] = TRUE;
                printf("%d -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}



int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init_graph(g);
    for (int i = 0; i < 5; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    insert_edge(g, 3, 4);
    print_adj_list(g);
    bfs(g, 0);
    free_adj_list(g);
    free(g);
    return 0;
}