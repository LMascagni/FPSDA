
#include <stdio.h>
#include <stdlib.h>
#include "date_lib.h"

int main()
{
   int g1, m1, a1, g2, m2, a2;

   printf ("lettura prima data\n");
   leggi_data (&g1, &m1, &a1);

   printf ("lettura seconda data\n");
   leggi_data (&g2, &m2, &a2);

   #if 0
   // collaudo di confronta_date
   printf ("confronta_date restituisce %d\n",
           confronta_date (g1, m1, a1, g2, m2, a2));

   // collaudo di giorno_successivo
   giorno_successivo (&g1, &m1, &a1);
   printf ("giorno_successivo della prima data restituisce %d %d %d\n", g1, m1, a1);
   giorno_successivo (&g2, &m2, &a2);
   printf ("giorno_successivo della seconda data restituisce %d %d %d\n", g2, m2, a2);
   #endif

   printf ("la differenza tra le date e` di %d giorni\n",
           differenza_tra_date (g1, m1, a1, g2, m2, a2));

   return EXIT_SUCCESS;
}
