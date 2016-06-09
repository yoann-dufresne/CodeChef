#include <stdio.h>
#include <stdlib.h>

int ** matrix;
int **** maxs;
int N, M;

int main () {
	int i, j, x, y;

	scanf ("%d %d", &N, &M);
	
	matrix = (int **) malloc (N * sizeof(int *));
	maxs = (int ****) malloc (N * sizeof(int ***));

	for (x=0 ; x<N ; x++) {
		matrix[x] = (int *) malloc (M * sizeof(int));

		for (y=0 ; y<M ; y++) {
			scanf("%d", &(matrix[x][y]));
		}
	}

	for (x=0 ; x<N ; x++) {
		for (y=0 ; y<M ; y++) {
			printf("%d ", matrix[x][y]);
		}
		printf("\n");
	}

	return 0;
}

int getMax (int x, int y, int i, int j) {
	if (i == 1 && j == 1)
		return matrix[x][y];

	if (matrix[x] == NULL) {
		matrix[x] = (int ***) malloc (M * sizeof (int **));
	}

	
}
