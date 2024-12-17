//fibonacci

#include <stdio.h>
#include <stdlib.h>
int main ()
{
   int n, f, i, prec1, prec2;
   scanf ("%d", &n);
   f = 0;
   i = 0;
   prec2 = 0;
   prec1 = 1;
   printf ("%d\n", prec1); //giusto??????
   printf ("%d\n", prec2); //giusto??????

   while (i =< n)
   {
      f = prec1 + prec1;
      prec2 = prec1;
      prec1 = f;
      i = i+1;
      printf ("%d\n", f);
   } 
   return EXIT_SUCCESS;
}
