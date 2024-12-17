#include <stdio.h>
#include <stdlib.h>
#include "datelib.h" 

int main()
{
   int g, m, a;
   printf("Inserisci giorno, mese e anno: ");
   scanf("%d %d %d", &g, &m, &a);

   //provo le funzioni della libreria:
   if(bisestile (a))
   {
      printf("L'anno è bsestile\n");
   }
   else
   {
      printf("L'anno non è bisestile\n");
   }

   printf("Il numero di siorni del mese è %d\n", numero_giorni_del_mese(m, a));


   if(chkdate (g, m, a))
   {
      printf("La data è valida\n");
   }
   else
   {
      printf("La data non è valida\n");
   }

   return EXIT_SUCCESS;
}