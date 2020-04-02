#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void RadixSort(int* a, int n) {
	int res[MAX], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue / exp > 0) {
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) {
			bucket[a[i] / exp % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		} 
		for (int i = n - 1; i >= 0; i--) { 
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) {
			a[i] = res[i];
		}
		exp *= 10;
	}
}
int main(void) {
	int a[MAX];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	RadixSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}