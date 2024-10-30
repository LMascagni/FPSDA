#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n, fn_1, fn_2, i, fn;
   fn_2 = 0;
   fn_1 = 1;

   printf("Inserire n:\n");
   scanf("%d", &n);

   printf("La successione di Fibinacci per n = %d è:\n", n); 
   printf ("%d\n", fn_2);
   printf ("%d\n", fn_1);

   for( i = 0; i < n; i++ )
   {
      fn = fn_1 + fn_2;
      fn_2 = fn_1;
      fn_1 = fn;
      printf("%d\n", fn);
   }
   return EXIT_SUCCESS;
}

/*
leggi n
calcola la successione fino a n
   f0 <- 0
   f1 <- 1
   for(i = 0; i < n; i++)
   {
      fn <- fn-1 + fn-2
      fn-2 <- fn-1
      fn-1 <- fn
   }
stampa la successione
*/