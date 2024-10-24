//RADICE QUADRATA METODO DI NEWTON
// NON VIENE!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
   int n;
   double precisione, n1, n2;
   printf("Inserire il radicando:\n");
   scanf("%d", &n);
   printf("Inserire la precisione voluta:\n");
   scanf("%lf", &precisione);

   n1 = n;
   n2 = 1;
   int i = 0;
   while( abs(n1 - n2) > precisione)
   {
      printf("\nciclo %d\n", i);
      n1 = (n1 + n2) / 2.0;
      printf("n1 = %lf\n", n1);
      n2 = n / n1;
      printf("n2 = %lf\n", n2);
   }

   printf("la radice quadrata di %d è %lf.\n", n, n1);
   

   return EXIT_SUCCESS;
}