#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int numero;
   numero = 0;
   char valore_letto;
   while( (valore_letto = getchar()) != '\n' ) //leggo i caratteri finichè non inserisco un invio (\n)
   {
      //controllo che il carattere inserito sia un numero
      if( !(valore_letto >= '0' && valore_letto <= '9'))
      {
         printf("Errore: carattere non valido.\n");
         return EXIT_FAILURE;
      }
      numero = numero*10 + valore_letto -'0';
   }
   printf ("Ho letto il valore %d\n", numero);
   return EXIT_SUCCESS;
}