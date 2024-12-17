//lettura_numero_intero

//controllo che l'input sia corretto -> un numero exit (EXIT_FAILURE)
#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int numero;
   char valore_letto;
   numero = 0;

   while ((valore_letto = getchar()) != '\n')
   {
      numero = numero * 10 + valore_letto - '0';
   }

   printf ("Ho letto il valore %d\n", numero);

   return EXIT_SUCCESS;
}