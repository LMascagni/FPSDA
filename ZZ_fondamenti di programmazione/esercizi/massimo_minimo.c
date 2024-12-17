/*

• Scrivere un programma per calcolare il massimo e il
minimo tra n numeri interi inseriti da tastiera
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, tot, numero, min, max;
   printf("Inserire la lunghezza della lista di numeri (almeno 2):\n");
   
//controllo che la lunghezza della sequenza sia valida
   do
   {
      scanf("%d", &tot);
      if(tot < 2)
      {
         printf("Valore non valido. inserire un valore maggiore di 2:\n");
      }
   }while (tot < 2);

//calcolo minimo e massimo
   printf("Inserire i numeri:\n");
   scanf("%d", &numero);
   max = numero;
   min = numero;
   i = 1;
   while (i < tot)
   {
      scanf("%d",&numero);
      if (numero < min)
      {
         min = numero;
      }
      if (numero > max)
      {
         max = numero;
      }
      i++;
   }
   
   printf("il massimo è: %d\n", max);
   printf("il minimo è: %d\n", min);

   return EXIT_SUCCESS;
}