//lettura di un testo fino all'EOF (end of file)
//EOF: end of file, leggendo in txt da tastiera non posso fermarmi agli INVIO '\n', ma alla fine del file EOF-> codice ascii speciale. da tastiera inseribile con ctrl+d

#include <stdio.h>
#include <stdlib.h>

#define VERO 1;
#define FALSO 0;

int main ()
{
   int contatore_caratteri, contatore_righe, contatore_parole;
   char carattere_letto;
   int in_parola;
   
   contatore_caratteri = 0;
   contatore_righe = 0;
   contatore_parole = 0;
   in_parola = FALSO;
   
   //conta caratteri
   while ( (carattere_letto = getchar()) != EOF )
   {
      contatore_caratteri++;
      //conta righe
      if (carattere_letto == '\n')
      {
         contatore_righe++;  
      }
      if (carattere_letto == ' ' || carattere_letto == '\n')
      {
         in_parola = FALSO; //memorizzo il fatto di essere fuori da una parola perchè sono su un carattere separatore
      }
      else if (!in_parola) //quindi in_parola è vero
      {
         /*sono in una parola, conto la parola solo se prima ero su un separatore 
         (cioè ora sono sul primo carattere della parola) e memorizzo nel flag che sono dentro la parola*/
         contatore_parole++;
         in_parola = VERO;
      }
   }
   printf ("Caratteri: %d, righe: %d, parole: %d\n", contatore_caratteri, contatore_righe, contatore_parole);
   //ci sono due codici di formato: i %d (tutte le stringhe di formato) vengono associati alle espressioni a dx nell'ordine in cui queste sono elencate
   //printf ("Caratteri: %d\n righe: %d\n", contatore_caratteri, contatore_righe); stampo caratteri: A CAPO righe:
   //NOTA: il printf non stampa se non c'è il \n perchè se non c'è allora la stringa non ha fine e non riesce a visualizzarla, sta lì ad aspettare che finisca.
   return EXIT_SUCCESS;
}

/*
prompt dei comandi:
wordcount < testo.txt (<: reindirizzazione dell'input. < testo.txt: il file wordcount prende in input i dati dal file testo.txt)
*/