#if 0
//elevamento a potenza
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a, b, i;
   long int potenza;
   printf("Inserire la base a:\n");
   scanf("%d", &a);
   printf("Inserire l'esponente b:\n");
   scanf("%d", &b);

   //calcolo dell'esponente:
   for( i=0; i < b; i++ )
   {
      potenza *= a; //potenza = potenza * a;
   }
   //controllo il segno di potenza in base al valore di a e b
   if( a < 0 && b%2 != 0 )
   {
      potenza = -potenza;
   }

   printf("a^b = %d\n", potenza);

   return EXIT_SUCCESS;
}
#endif
/*
leggi a da tastiera
leggo il numero finchè inserisco da tastiera
devo ripeterlo due volte...
leggi b da tastiera

o faccio l'inserimento da tastiera oppure lascio l'input e basta

calcola a^b
   moltiplica a per b volte
      while(i < b)
      {
         pot <- pot * a
         i++
      }
      for( i = 0; i < b; i++)
      {
         pot <- pot * a;
      }
controlla il segno di a e di pot
   if (a<0 && b%2 != 0)
   {
      pot = -pot
   }
stampa pot
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
   int base, esp, i;
   double potenza;
   potenza = 1;
   printf("Inserire la base a:\n");
   scanf("%d", &base);
   printf("Inserire l'esponente b:\n");
   scanf("%d", &esp);

  // calcolo della potenza con b>0:
   if (esp > 0)
   {
      for (i = 0; i < esp; i++)
      {
         potenza *= base; // funziona con base maggiore e minore di 0
      }
   } else
   // calcolo della potenza con esp<0:
   if (esp < 0 && base != 0)
   {
      for (i = 0; i > esp; i--)
      {
         potenza = potenza / (double)base;
      }
   }
   printf("a^b = %lf\n", potenza);

   return EXIT_SUCCESS;
}
