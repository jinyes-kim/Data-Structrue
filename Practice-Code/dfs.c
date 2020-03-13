#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int check[MAX];

typedef struct {
	int data;
	struct Node* next;
} Node;

Node** array;

void addData(Node* root, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void dfs(int data) {
	if (check[data]) return;
	check[data] = 1;
	printf("-> %d", data);
	Node* cur = array[data]->next;
	while (cur != NULL) {
		int next = cur->data;
		dfs(next);
		cur = cur->next;
	}
}


int main(void) {
	int n, edge;
	scanf("%d %d", &n, &edge);
	array = (Node**)malloc(sizeof(Node*) * (n+1));
	for (int i = 1; i <= n; i++) {
		array[i] = (Node*)malloc(sizeof(Node));
		array[i]->next = NULL;
	}
	for (int i = 0; i < edge ; i++) {
		int root, data;
		scanf("%d %d", &root, &data);
		addData(array[root], data);
		addData(array[data], root);
	}
	for (int i = 1; i <= n; i++) {
		printf("Node[%d]: ", i);
		showAll(array[i]);
		printf("\n");
	}
	dfs(1);
	return 0;
}