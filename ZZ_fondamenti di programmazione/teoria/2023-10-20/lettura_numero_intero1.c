//lettura_numero_intero

//controllo che l'input sia corretto -> un numero exit (EXIT_FAILURE)
//versione avanzata = elimino un getchar... vedi i suoi file (file_advanced)
#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int numero;
   numero = 0;

   char valore_letto = getchar(); //la funzione getchar() restituisce il valore del codice ascii del carattere inserito da tastiera
   //sfrutta in BUFFER, un'area di memoria temporanea tra tastiera e computer che tiene traccia della sequenza di caratteri inseriti da tastiera e quando viene premuto invio
   //il buffer spedisce i valori al programma
   //chiamando getchar() il primo valore viene preso e codificato in codice ascii e viene eliminato dal buffer. chiamata una seconda volta prende i lsecondo valore etc finchè non svuota ompletamente il buffer
   
   while (valore_letto != '\n')
   {
      numero = numero * 10 + valore_letto - '0'; //valore_letto è un codice ascii che vale x sottraendo il valore del codice ascii di 0 ottengo il valore vero:
      //valore_letto = 1 -> ascii 49 qundi numero = 49 - 48 = 1
      valore_letto = getchar();
   }

   printf ("Ho letto il valore %d\n", numero);

   return EXIT_SUCCESS;
}