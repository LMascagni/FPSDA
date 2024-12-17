//ricerca valore
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, conta_val, tot, n, val_cercato;
   i = 0;
   printf("Inserire la lunghezza della sequenza di numeri:\n");
   scanf("%d", &tot);
   printf("Inserire il valore cercato:\n");
   scanf("%d", &val_cercato);
   printf("Inserire i valori:\n");

   while( i < tot)
   {
      scanf("%d", &n);
      if( n == val_cercato)
      {
         conta_val++;
      }
      i++;
   }

   printf("%d è stato tovato %d volte all'interno della sequenza.\n", val_cercato, conta_val);

   return EXIT_SUCCESS;
}