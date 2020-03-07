#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int n, m;
int a[SIZE];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		a[m]++;
	}
	for (int i = 0; i < SIZE; i++) {
		while (a[i] != 0) {
			printf("%d ", i);
			a[i]--;
		}
	}
	return 0;
}
