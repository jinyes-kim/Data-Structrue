#include <stdio.h>
#include <stdlib.h>

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
    return 0;
}
