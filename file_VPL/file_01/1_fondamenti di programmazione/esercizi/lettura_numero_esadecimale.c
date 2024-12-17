#include <stdio.h>
#include <stdlib.h>

//NON FUNZIONAAAAAAA
int main ()
{
   char inserito;
   int dec = 0;

   while ((inserito = getchar()) != '\n')
   {
      if (!((inserito >= '0' && inserito <= '9') || (inserito >= 'A' && inserito <= 'F')))
      {
         printf("Errore: carattere non valido.\n");
         return EXIT_FAILURE;
      }

      if(inserito >= '0' && inserito <= '9')
      {
         dec = dec*16 + inserito - '0';
      }
      if(inserito >= 'A' && inserito <= 'F')
      {
         dec = dec*16 + inserito - 'A' + 10; 
      }
   }
   printf("Ho letto il valore %X che corrisponde a %d.\n", dec, dec);

   return EXIT_SUCCESS;
}     