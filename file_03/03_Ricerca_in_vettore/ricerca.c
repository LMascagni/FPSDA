#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define MAX_VAL 100

int main ()
{
    int v[MAX_VAL];

    int dim, valore_cercato, inizio, fine, risultato;

    dim = leggi_interi_vettore(v, MAX_VAL);

    // Lettura del valore da cercare e degli estremi del sottovettore
    printf("Inserisci il valore da cercare: ");
    scanf("%d", &valore_cercato);
    printf("Inserisci l'indice del primo elemento del sottovettore in cui cercare: ");
    scanf("%d", &inizio);
    printf("Inserisci l'indice dell'ultimo elemento del sottovettore in cui cercare: ");
    scanf("%d", &fine);

    risultato = cerca_in_sottovettore(v, inizio, fine, valore_cercato);

    if (risultato != -1) {
        printf("v[%d] = %d\n", risultato, v[risultato]);
    } else {
        printf("Valore non trovato\n");
    }
}