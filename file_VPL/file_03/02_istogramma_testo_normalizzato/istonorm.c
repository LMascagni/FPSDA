#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define V_MIN 'a'
#define V_MAX 'z'

int main()
{
   int counters[V_MAX - V_MIN + 1];

   leggi_testo_e_aggiorna_i_contatori(counters, V_MIN, V_MAX);

#ifdef DEBUG
   printf("DEBUG: stampa di counters[]\n");
   stampa_vettore(counters, V_MAX - V_MIN + 1);
#endif

   stampa_istogramma_verticale_testo(counters, V_MAX - V_MIN + 1, 20);

   return EXIT_SUCCESS;
}
