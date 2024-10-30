//fattoriale
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n, fattoriale, i;
   fattoriale = 1;

   printf("Inserire n: \n");
   scanf("%d", &n);

   for (i = 1; i <= n; i++)
   {
      fattoriale = fattoriale * i;
   }

   printf("n! = %d\n", fattoriale);

   return EXIT_SUCCESS;
}

/*
leggi n
calcola n!
   parti da fattoriale = 1 e i = 1, ogni giro aumenti i di 1 fino ad arrivare a n
   for( i = 1; i <= n; i++)
   {
      fattoriale = fattoriale * i;
   }
   
stampa n!
*/