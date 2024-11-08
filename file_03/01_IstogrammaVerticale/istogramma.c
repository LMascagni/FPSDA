#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

//definizione dei valori massimo e minimo inseribili nell'array
#define VAL_MIN 0
#define VAL_MAX 20

//definizione della lunghezza massima dell'array
#define MAX_LENGHT 100



int main()
{

    int values[MAX_LENGHT];
    int counters[VAL_MAX - VAL_MIN + 1];

    int dim;

    //lettura dei valori
    dim = leggi_vettore (values, MAX_LENGHT);

    //controllo dei valori e aggiornamento
    aggiorna_contatori (values, dim, VAL_MIN, VAL_MAX, counters);

#ifdef DEBUG
    printf("DEBUG: stampa di values[]\n");
    stampa_vettore (values, dim);
    printf("DEBUG: stampa di counters[]\n");
    stampa_vettore (counters, VAL_MAX - VAL_MIN + 1);
#endif
    
    //stampa dell'istogramma verticale
    stampa_istogramma_verticale(counters, VAL_MAX - VAL_MIN + 1, VAL_MIN, VAL_MAX);

    return EXIT_SUCCESS;
}
