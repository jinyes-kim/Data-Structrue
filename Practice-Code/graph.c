#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* next;
} Node;

void addNode(Node* root, int data) {
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

int main(void) {
	int n, line;
	scanf("%d %d", &n, &line);
	Node** array = (Node**)malloc(sizeof(Node*) * (n+1));
	for (int i = 1; i <= n; i++) {
		array[i] = (Node*)malloc(sizeof(Node));
		array[i]->next = NULL;
	}
	for (int i = 0; i < line*2; i++) {
		int root, new;
		scanf("%d %d", &root, &new);
		addNode(array[root], new);
	}
	for (int i = 1; i <= n; i++) {
		printf("Node[%d]: ", i);
		showAll(array[i]);
		printf("\n");
	}
	return 0;
}