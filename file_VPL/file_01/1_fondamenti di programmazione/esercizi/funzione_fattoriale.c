//fattoriale
#include <stdio.h>
#include <stdlib.h>

//prototipo della funzione fattoriale
long long int fattoriale(int n);

int main()
{
   int n;
   //leggi il mìnumero di cui fare il fattoriale
   printf("Inserire n: \n");
   scanf("%d", &n);

   //richiama la funzione fattoriale
   //output fattoriale
   printf("n! = %lld\n", fattoriale(n)); //%lld: long long int

   return EXIT_SUCCESS;
}

long long int fattoriale(int n)
{
   long long int fatt;
   int i;
   fatt = 1;   

   for( i = 1; i <= n; i++)
   {
      fatt *= i;
   }
   return fatt;
}

/*
va in overflow: lavoriamo su 32 bit:
-2^31 < n < 2^31-1
= 2^31 = 2*2^30 = 2*G = 2 miliardi, ma già con 14! si è già a 26 miliardi...
quindi non ci stiamo; il programma va in overflow e non ci dice nulla e continua a lavorare
per esempio 17! diventa negativo e eliminando i bit di carry (Cn e Cn-1 : i riporti)
il primo bit può essere negativo!!!
come si risolve il problema?
si usa il formato long long int che lavora con interi a 64 bit
-2^63 < n < 2^63-1
*/