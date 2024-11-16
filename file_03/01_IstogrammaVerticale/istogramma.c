#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define VAL_MIN 0
#define VAL_MAX 20

int main()
{
    int counters[VAL_MAX - VAL_MIN + 1];

    leggi_sequenza_e_aggiorna_i_contatori(counters, VAL_MIN, VAL_MAX);

#ifdef DEBUG
    printf("DEBUG: stampa di counters[]\n");
    stampa_vettore (counters, VAL_MAX - VAL_MIN + 1);
#endif
    
    //stampa dell'istogramma verticale
    stampa_istogramma_verticale (counters, VAL_MAX - VAL_MIN + 1, VAL_MIN, VAL_MAX);

    return EXIT_SUCCESS;
}
