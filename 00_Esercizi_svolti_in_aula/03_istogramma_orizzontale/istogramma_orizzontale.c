#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define VAL_MIN 0
#define VAL_MAX 99



int main()
{
   int contatori[VAL_MAX - VAL_MIN + 1];

   leggi_sequenza_e_aggiorna_i_contatori (contatori, VAL_MIN, VAL_MAX);

   stampa_istogramma_orizzontale (contatori, VAL_MAX - VAL_MIN + 1);
   // stampa_vettore (contatori, VAL_MAX - VAL_MIN + 1);

   return EXIT_SUCCESS;
}

