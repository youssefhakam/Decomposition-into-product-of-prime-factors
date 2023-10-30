#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void factorisation(int N) {
	int i = 2;
	int r = 2;
	int c = 5;

	int** array = (int**)malloc(r * sizeof(int*));
	for (int x = 0; x < r; x++) {
		array[x] = (int*)malloc(c * sizeof(int));
	}

	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 10; y++) {
			array[x][y] = 0;
		}
	}
	

	while (N != 1) {
		if (i < c) {
			while (N % i == 0) {
				N = N / i;
				array[0][i - 2] = i;
				array[1][i - 2]++;
			}
			i++;
		}
		else {
			for (int x = 0; x < r; x++) {
				array[x] = (int*)realloc(array[x], (c + 2) * sizeof(int));
				for (int y = c; y < c + 2; y++) {
					array[x][y] = 0;
				}
			}
			c += 2;
		}		
	}
	printf("\n\n");
	for (int i = 0; i < c; i++) {
		if (array[1][i] != 0) {
			printf("(%d)^(%d)", array[0][i], array[1][i]);
			printf("*");
		}
	}
	printf("1");

	for (i = 0; i < r; i++) {
		free(array[i]);
	}
	free(array);
}

int main() {
	int N;

	printf("donner un nombre pour factorisation : ");
	scanf("%d", &N);
	factorisation(N);

	return 0;

}