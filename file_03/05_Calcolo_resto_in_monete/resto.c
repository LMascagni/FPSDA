#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define N_MAX 100

int resto_in_monete (int resto, int n, int valori[], int numeroMonete[]);

int main() {
    int valori[N_MAX];
    int numeroMonete[N_MAX];
    int resto, n;

    n = leggi_interi_vettore(valori, N_MAX);

    printf("Inserisci il valore totale del resto: ");
    scanf("%d", &resto);

    printf("calcolo del resto...\n");

    resto = resto_in_monete(resto, n, valori, numeroMonete);

    stampa_vettore(numeroMonete, n);

    printf("resto rimanente: %d\n", resto);

    return EXIT_SUCCESS;
}

int resto_in_monete (int resto, int n, int valori[], int numeroMonete[]) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        numeroMonete[i] = resto / valori[i];
        resto = resto % valori[i];
#ifdef DEBUG
        printf("valori[%d] = %d, numeroMonete[%d] = %d, resto = %d\n", i, valori[i], i, numeroMonete[i], resto);
#endif
    }

    return resto;
}
