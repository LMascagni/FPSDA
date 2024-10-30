#include <stdio.h>
#include <stdlib.h>
#include "datelib.h" 
#include "utility.h"

int main()
{
   int giorno1, mese1, anno1, giorno2, mese2, anno2;
   
   printf("Data 1\n");
   leggi_data(&giorno1, &mese1, &anno1); //data 1
   //abbiamo usato dei puntatori: espressioni che calcolano gli indirizzi di memoria delle variabili e delle funzioni.
   printf("Data 2\n");
   leggi_data(&giorno1, &mese1, &anno1); //data 2

   printf("Data 1\n");
   stampa_data(giorno1, mese1, anno1); //vanno &?
   printf("Data 2\n");
   stampa_data(giorno2, mese2, anno2);


   printf("Numero di giorni tra le due date: %d\n",
      differenza_tra_date(giorno1, mese1, anno1, giorno2, mese2, anno2));

   return EXIT_SUCCESS;
}

