#include <stdio.h>
#include <stdlib.h>


void compute (int x, int y, int i, int j);
int getMax (int x, int y, int i, int j);
int getVal (int x, int y, int i, int j);



int ** matrix;
int **** maxs;
int **** values;
int N, M, Q;

int main () {
	int i, j, x, y;
	int val, min, q;

	scanf ("%d %d", &N, &M);
	
	matrix = (int **) malloc (N * sizeof(int *));
	maxs = (int ****) malloc (N * sizeof(int ***));
	values = (int ****) malloc (N * sizeof(int ***));
	for (i=0 ; i<N ; i++) {
		maxs[i] = NULL;
		values[i] = NULL;
	}

	for (x=0 ; x<N ; x++) {
		matrix[x] = (int *) malloc (M * sizeof(int));

		for (y=0 ; y<M ; y++) {
			scanf("%d", &(matrix[x][y]));
		}
	}

	scanf ("%d", &Q);

	for (q=0 ; q<Q ; q++) {
		min = 1000 * N * M + 1;
		scanf("%d %d", &i, &j);

		for (x=0 ; x<N-i+1 ; x++) {
			for (y=0 ; y<M-j+1 ; y++) {
				compute(x, y, i, j);
				val = getVal (x, y, i, j);
				if (val < min) {
					min = val;
				}
			}
		}

		printf("%d\n", min);
	}

	return 0;
}

void compute (int x, int y, int i, int j) {
	int a, b, maxA, maxB, nbElmts;
	int idx;

	// Trivial case
	if (i == 1 && j == 1)
		return;

	// Dynamic allocations
	if (maxs[x] == NULL) {
		maxs[x] = (int ***) malloc (M * sizeof (int **));
		values[x] = (int ***) malloc (M * sizeof (int **));
		for (a=0 ; a<M ; a++) {
			maxs[x][a] = NULL;
			values[x][a] = NULL;
		}
	}

	if (maxs[x][y] == NULL) {
		maxs[x][y] = (int **) malloc ((N-x) * sizeof (int *));
		values[x][y] = (int **) malloc ((N-x) * sizeof (int *));
		for (a=0 ; a<N-x ; a++) {
			maxs[x][y][a] = NULL;
			values[x][y][a] = NULL;
		}
	}

	if (maxs[x][y][i-1] == NULL) {
		maxs[x][y][i-1] = (int *) malloc ((M-y) * sizeof (int));
		values[x][y][i-1] = (int *) malloc ((M-y) * sizeof (int));
		for (a=0 ; a<M-y ; a++) {
			maxs[x][y][i-1][a] = 0;
			values[x][y][i-1][a] = 0;
		}
	}

	// If not already present
	if (maxs[x][y][i-1][j-1] == 0) {
		if (i == 1) {
			idx = j/2;
			nbElmts = idx;

			compute (x, y, i, idx);
			a = getVal (x, y, i, idx);
			maxA = getMax(x, y, i, idx);

			compute (x, y+idx, i, j-idx);
			b = getVal (x, y+idx, i, j-idx);
			maxB = getMax(x, y+idx, i, j-idx);
		} else {
			idx = i/2;
			nbElmts = idx * j;

			compute (x, y, idx, j);
			a = getVal (x, y, idx, j);
			maxA = getMax(x, y, idx, j);

			compute (x+idx, y, i-idx, j);
			b = getVal (x+idx, y, i-idx, j);
			maxB = getMax(x+idx, y, i-idx, j);
		}

		if (maxA>maxB) {
			maxs[x][y][i-1][j-1] = maxA;
			values[x][y][i-1][j-1] = a + b + (i * j - nbElmts) * (maxA - maxB);
		} else {
			maxs[x][y][i-1][j-1] = maxB;
			values[x][y][i-1][j-1] = a + b + nbElmts * (maxB - maxA);
		}
	}
}

int getMax (int x, int y, int i, int j) {
	if (i == 1 && j == 1)
		return matrix[x][y];

	return maxs[x][y][i-1][j-1];
}

int getVal (int x, int y, int i, int j) {
	if (i == 1 && j == 1)
		return 0;

	return values[x][y][i-1][j-1];
}
