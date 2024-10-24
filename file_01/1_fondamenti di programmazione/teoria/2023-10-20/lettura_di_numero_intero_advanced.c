
/* lettura di un numero intero da tastiera */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero;
   char valore_letto;

   /* numero <- 0; */
   numero = 0;

   while ( (valore_letto = getchar()) != '\n')
   {
      /* if (valore_letto non e` una cifra)
         {
            exit (EXIT_FAILURE);
         }
      */

      /* moltiplica e somma il valore_letto - '0' */
      /* numero <- numero * 10 + valore_letto - '0'; */
      numero = numero * 10 + valore_letto - '0';
   }

   /* output numero; */
   printf ("ho letto il valore %d\n", numero);

   return EXIT_SUCCESS;
}


         