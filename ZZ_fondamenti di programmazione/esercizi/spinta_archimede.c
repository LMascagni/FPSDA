//spinta di archimede
/* 
Si scriva un programma che legga da tastiera il raggio di
una sfera e calcoli la spinta di Archimede che essa
riceve quando viene immersa (completamente) in
acqua. Per questo programma si scriva (o si riutilizzi, se
già scritta) una funzione per il calcolo del volume di una
sfera.
Nota: si approssimi il  con il valore 3.141592 e la
densità dell’acqua con 1.028 kg/dm3
Per i test il programma deve chiedere l’informazione
relativa al raggio e stampare il risultato una volta sola!
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utility.h"

int main()
{
   double raggio;

   do
   {
      printf("Inserire il raggio della sfera > 0.000016:\n");
      scanf("%lf", &raggio); //input : è il puntatore in sè: contenitore

      if(raggio <= 0.000016) //*input: valore contenuto dal puntatore
      {
         printf("Valore non valido. Inserire un numero maggiore di 0.000016");
      }
   } while( raggio <= 0.000016 );
   //DA TESTARE
   while(getchar() != '\n'); //svuota il buffer se c'è un errore di inserimento
   printf("Una sfera di raggio %.3lf, quando completamente immersa in acqua, riceve una spinta di Archimede di %lf.\n", raggio, spinta_archimede(raggio));

   return EXIT_SUCCESS;
}