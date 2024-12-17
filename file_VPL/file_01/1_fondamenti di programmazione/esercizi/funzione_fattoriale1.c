#include <stdio.h>
#include <stdlib.h>

long long int fattoriale (int n);

int main ()
{
   int n;

   printf("Inserire il numero di cui calcolare il fattoriale: \n");
   //controllo n >= 0:
   do{
      scanf("%d", &n);
      if (n < 0)
      {
         printf("ERRORE: valore non valido. n deve essere positivo.\n");
         printf("Inserire nuovamente n.\n");
      }
   } while (n < 0);

   printf("%d! = %lld\n", n, fattoriale(n));


   return EXIT_SUCCESS;
}

long long int fattoriale (int n)
{
   long long int fatt;
   int i;
   fatt = 1;
   i = 1;

   while (i <= n)
   {
      fatt *= i;
      i++;
   }
   return fatt;
}