#include <stdlib.h>
#include <stdio.h>

#define DIM_MAX 10

void riempi_matrice_a_spirale(int matrice[DIM_MAX][DIM_MAX], int dim);
void stampa_matrice(int matrice[DIM_MAX][DIM_MAX], int dim);

int main(int argc, char *argv[])
{
	int matrice[DIM_MAX][DIM_MAX];
	int dim;
	
	//leggi il numero
	printf("dimensione della matrice (quadrata max 10x10): ");
	scanf("%d", &dim);
	
	//chiama la funzione pe riempire la matrice a spirale
	riempi_matrice_a_spirale(matrice, dim);
	
	//stampa la matrice
	stampa_matrice(matrice, dim);
	
	return EXIT_SUCCESS;	
}

void riempi_matrice_a_spirale(int matrice[DIM_MAX][DIM_MAX], int dim) 
{
    int val = 0;
    int top = 0, bottom = dim - 1;
    int left = 0, right = dim - 1;

    while (val < dim * dim) {
        for (int i = left; i <= right; i++) {
            matrice[top][i] = val++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrice[i][right] = val++;
        }
        right--;
        for (int i = right; i >= left; i--) {
            matrice[bottom][i] = val++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            matrice[i][left] = val++;
        }
        left++;
    }
}

void stampa_matrice(int matrice[DIM_MAX][DIM_MAX], int dim)
{
	int i, j;
	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			printf("%6d", matrice[i][j]);
		}
		printf("\n");
	}
}