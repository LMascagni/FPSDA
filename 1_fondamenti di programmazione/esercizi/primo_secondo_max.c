/*
primo e secondo massimo:
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, tot, numero, max1, max2;
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


//calcolo primo e secondo massimo
   printf("Inserire i numeri:\n");
   printf("1°: ");
   scanf("%d", &max1);
   printf("2°: ");
   scanf("%d", &numero);

   if(numero > max1)
   {
      max2 = max1;
      max1 = numero;
   }
   else
   {
      max2 = numero;
   }

   //calcolo massimi successivi
   for(i = 2; i < tot; i++)
   {
      printf("%d°: ", i+1);
      scanf("%d",&numero);

      if(numero > max1)
      {
         max2 = max1;
         max1 = numero;
      }
      else if (numero > max2)
      {
         max2 = numero;
      }
   }

   printf("Il primo massimo è %d e il secondo massimo è %d\n", max1, max2);

   return EXIT_SUCCESS;
}