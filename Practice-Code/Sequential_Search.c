#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 1000

char** array;
int founded;

int main(void) {
	int n;
	char* word;
	word = (char*)malloc(sizeof(char) * LENGTH);
	scanf("%d %s", &n, word);
	array = (char**)malloc(sizeof(char*) * n);
	
	for (int i = 0; i < n; i++) {
		array[i] = malloc(sizeof(char) * LENGTH);
		scanf("%s", array[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!strcmp(word, array[i])) {
			printf("index: %d", i + 1);
			founded = 1;
		}
	}
	if (!founded) printf("Not Found");
	return 0;
}