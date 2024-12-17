/*
SWITCH:
l'espressione che controlla lo switch è INTERA, NON Dà RISULTATI NON INTERI. l'unico risultato è un INTERO SCALARE 
(un solo risultato intero, diverso dal quello VETTORIALE che dà più riusltati... è un vettore)

switch (espressione) //non è vero o falso, ma dà un NUMERO
{
   case val_int1: istruzione1;
                  break;
   case val_int2: istruzione2;
                  break;
...
   default:       istruzione_default;
                  break;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
   //svuotiamo il buffer della tastiera in modo che la lettura parta sempra dal primo carattere
   /*
   leggi carattere;
   while(carattere != '\n'){
      leggi ancora un carattere;
   }*/

   #if 0
   //versione 1:
   int carattere_tmp;
   carattere_tmp = getchar();
   while (carattere_tmp != '\n')
   {
      carattere_tmp = getchar();
   }

   //versione 2:
   while ((carattere_tmp = getchar()) != '\n')
   {
   }
   #endif
   char voto;
   int favorevoli, contrari, astenuti;
   favorevoli = 0;
   contrari = 0;
   astenuti = 0;
   //versione 3:
   while ((voto = getchar()) != 'X')
   {
      while (getchar() != '\n'); //svuota il buffer della tastiera, passa al secondo ciclo e poi ricomincia da capo... penso... vedi file su moodle
      switch (voto)
      {
         case 'Y':
         case 'y':
         case 's':
         case 'F':
         case 'f': favorevoli++;
                   break;
         case 'N':
         case 'n':
         case 'C':
         case 'c': contrari++;
                   break;
         case '-':
         case 'A':
         case 'a': astenuti++;
                   break;
         default:  printf ("Voto non riconosciuto.");
                   break;
      }
   }

   return EXIT_SUCCESS;
}