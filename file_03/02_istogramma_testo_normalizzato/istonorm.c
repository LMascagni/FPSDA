#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define V_MIN 'a'
#define V_MAX 'z'

#define MAX_LEN 100000


int main()
{
    int text[MAX_LEN];
    int counters[V_MAX - V_MIN + 1];

    int dim;

    dim = leggi_testo_vettore(text, MAX_LEN);

    //stampa_vettore(text, dim);

    aggiorna_contatori(text, dim, V_MIN, V_MAX, counters);

#ifdef DEBUG
    printf("DEBUG: stampa di text[]\n");
    stampa_vettore(text, dim);
    printf("DEBUG: stampa di counters[]\n");
    stampa_vettore(counters, V_MAX - V_MIN + 1);
#endif

    stampa_istogramma_verticale(counters, V_MAX - V_MIN + 1, V_MIN, V_MAX, 'c', 1, 0, 20);

    return EXIT_SUCCESS;
}
