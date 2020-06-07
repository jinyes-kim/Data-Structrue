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
node* insert_tail(node* head, element item);
void add_edge(graph* g, element v, element u);
void print_list(node* list);
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
    node* tmp = (node*)malloc(sizeof(node));
    tmp->vertext = item;
    tmp->link = NULL;
    if (head == NULL) {
        return tmp;
    }
    else {
        node* marker = head;
        while (marker->link != NULL) {
            marker = marker->link;
        }
        marker->link = tmp;
    }
    return head;
}

void add_edge(graph* g, element v, element u) {
    g->header[v] = insert_tail(g->header[v], u);
    g->header[u] = insert_tail(g->header[u], v);
}

void print_list(node* list) {
    node* tmp = list;
    for (; tmp; tmp = tmp->link) {
        printf("%d ", tmp->vertext);
    }        
    printf("\n");
}

void print_graph(graph* g) {
    for (int i = 0; i < g->size; i++) {
        printf("정점 [%d] : ", i);
        print_list(g->header[i]);
    }
    
}

int main(void) {
    srand(time(NULL));
    int size;
    printf("노드 개수:");
    scanf_s("%d", &size);
    graph* g = init_graph(size);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (rand() % 5 == 0)
                add_edge(g, i, j);
        }
    }
    print_graph(g);
    return 0;
}

