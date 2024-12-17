#include <stdio.h>
#include <stdlib.h>

int main()
{
   int base, contatore, potenza, esponente;
   printf ("Inserire la base: ");
   scanf ("%d", &base); // "%d": formato del numero, lettura di un valore in base 10; &variabile: indirizzo di memoria della variabile
   printf ("Inserire la esponente: ");
   scanf ("%d", &esponente);

   potenza = 1;
   contatore = 0;

   while ( contatore < esponente )
   {
      potenza = base * potenza;
      contatore = contatore + 1;
   }
   // ==; =<; =>; <; >.
   printf ("potenza = %d\n", potenza);
   return EXIT_SUCCESS;
}