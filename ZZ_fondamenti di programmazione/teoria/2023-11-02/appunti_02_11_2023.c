/*
nel buffer di input si hanno i caratteri ascii inseriti es.:
'3' '7' ... '\n'
getchar() è una funzione che restituisce il primo valore del buffer che trova
es: '3' poi lo cancella e restituisce '7' fino a quando non restituisce '\n'
quando il buffer è vuoto esce dalla funzione.

N.B: PROVA A STAMPARE OGNI COSA DELLA GETCHAR(): TESTALA
*/

/*
Fattoriale:
*/
//fattoriale
#include <stdio.h>
#include <stdlib.h>

//prototipo della funzione fattoriale
int fattoriale(int n);

int main()
{
   int n;
   //leggi il mìnumero di cui fare il fattoriale
   printf("Inserire n: \n");
   scanf("%d", &n);

   //richiama la funzione fattoriale
   //output fattoriale
   printf("n! = %d\n", fattoriale(n));

   return EXIT_SUCCESS;
}


int fattoriale(int n)
{
   int fatt, i;
   fatt = 1;   

   for( i = 1; i <= n; i++)
   {
      fatt *= i;
   }

   return fatt;
}