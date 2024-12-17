#include <stdlib.h>
#include <stdio.h>

#define DIM_MAX 10

int leggi_matrice(int matrice[DIM_MAX][DIM_MAX]);
void stampa_matrice(int matrice[DIM_MAX][DIM_MAX], int dim);
void ruota_matrice(int matrice[DIM_MAX][DIM_MAX], int dim);
void trasposta_di_matrice(int matrice[DIM_MAX][DIM_MAX], int dim);
void inverti_colonne_di_matrice(int matrice[DIM_MAX][DIM_MAX], int dim);
void swap(int *a, int *b);

int main(int argc, char *argv[])
{
	int dim;
	int matrice[DIM_MAX][DIM_MAX];

	//lettura della matrice
	dim = leggi_matrice(matrice);

	//rotazione della matrice
	ruota_matrice(matrice, dim);
	//stampa della matrice
	stampa_matrice(matrice, dim);

	return EXIT_SUCCESS;
}

int leggi_matrice(int matrice[DIM_MAX][DIM_MAX])
{
	int dim;
	printf("dimensione della matrice (quadrata max 10x10): ");

	scanf("%d", &dim);

	int i, j;

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			scanf("%d", &matrice[i][j]);
		}
	}

	return dim;
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

void ruota_matrice(int matrice[DIM_MAX][DIM_MAX], int dim)
{
	//fai la trasposta della matrice
	trasposta_di_matrice(matrice, dim);

	//inverti le colonne della matrice
	inverti_colonne_di_matrice(matrice, dim);

	return;
}

void trasposta_di_matrice(int matrice[DIM_MAX][DIM_MAX], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			swap(&matrice[i][j], &matrice[j][i]);
		}
	}
	return;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void inverti_colonne_di_matrice(int matrice[DIM_MAX][DIM_MAX], int dim)
{
	int i, s, d;

	for (i = 0; i < dim; i++)
	{
		s = 0;
		d = dim - 1;
		while (s < d)
		{
			swap(&matrice[i][s], &matrice[i][d]);
			d--;
			s++;
		}
	}
}