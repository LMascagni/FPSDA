
#include <stdio.h>
#include <stdlib.h>
#include "date_lib.h"

int main()
{
   int g1, m1, a1, n;

   printf ("lettura data di partenza\n");
   leggi_data (&g1, &m1, &a1);

   printf ("inserisci n: ");
   scanf ("%d", &n);

   somma_n_a_data (&g1, &m1, &a1, n);

   printf ("la data ottenuta e` %d %d %d\n", g1, m1, a1);

   return EXIT_SUCCESS;
}
