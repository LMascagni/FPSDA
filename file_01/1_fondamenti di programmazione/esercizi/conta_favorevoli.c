#include <stdio.h>
#include <stdlib.h>

int main()
{
   char voto;
   int favorevoli, contrari, astenuti, totale_voti;
   favorevoli = 0;
   contrari = 0;
   astenuti = 0;
   totale_voti = 0;

   
   while ((voto = getchar()) != 'X')
   {
      while (getchar() != '\n'); //svuotamento buffer
      switch (voto)
      {
         case 'Y':
         case 'y':
         case 'S':
         case 's':
         case 'F':
         case 'f': favorevoli++;
                   totale_voti++;
                  break;
         case 'N':
         case 'n':
         case 'C':
         case 'c': contrari++;
                   totale_voti++;
                  break;
         case '-':
         case 'A':
         case 'a': astenuti++;
                   totale_voti++;
                  break;
         default: printf ("Voto non riconosciuto.\n");
                  break;
      }
   }
   printf ("Il totale dei voti è: %d\n", totale_voti);
   printf("Favorevoli: %d\nContrari: %d\nAstenuti: %d\n", favorevoli, contrari, astenuti);
   return EXIT_SUCCESS;
}