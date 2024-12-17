/*
Si scriva un programma che cerchi in una sequenza di
numeri inseriti da tastiera (si assuma che il primo
numero rappresenti la lunghezza della sequenza)
quello di valore più vicino ad un numero dato e lo
stampi
• In presenza di due differenti valori più vicini
equidistanti (es. 7 e 11 con numero dato 9), si stampi
il primo trovato
*/

//DOMANDA: STAMPO GIA' IL PRIMO VALORE PIU' VICINO TROVATO, MA NON SAPREI COME IMPLEMENTARLO O TROVARE IL SECONDO PIU' VICINO
//ricerca valore più vicino1 versione in C estremo XD
#include <stdio.h>
#include <stdlib.h>

#define FALSO 0;
#define VERO 1;

int main()
{
   int i, tot, n, val_cercato, diff, diff_tmp, vicino, vicino2;
   int flag_diff, flag_due_vicini;
   flag_diff = FALSO;
   flag_due_vicini = FALSO;
   i = 0;

   printf("Inserire la lunghezza della sequenza di numeri:\n");
   scanf("%d", &tot);
   printf("Inserire il valore cercato:\n");
   scanf("%d", &val_cercato);
   printf("Inserire i valori:\n");

   while( i < tot)  
   {
      scanf("%d", &n);
      //inizializzo la differenza:
      if(!flag_diff)
      {
         diff = ((val_cercato - n) >= 0 ? (val_cercato - n): -(val_cercato - n)); //osceno ma ok lol
         vicino = n;
         flag_diff = VERO;
      }
      else //differenza già inizializzata
      {
         diff_tmp = ((val_cercato - n) >= 0 ? (val_cercato - n): -(val_cercato - n));
         if(diff_tmp < diff)
         {
            vicino = n;
            diff = diff_tmp;
         }
         if(diff_tmp == diff) //due vicini
         {
            vicino2 = n;
            flag_due_vicini = VERO;
         }
      }
      i++;
   }

   if(flag_due_vicini == VERO)
   {
      printf("Il primo valore più vicino a %d è %d, il secondo è %d.\n", val_cercato, vicino, vicino2);
   }
   else
   {
      printf("Il valore più vicino a %d è %d.\n", val_cercato, vicino);
   }
   return EXIT_SUCCESS;
}

#if 0
//ricerca valore più vicino1 versione in C non estremo
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FALSO 0;
#define VERO 1;

int main()
{
   int i, tot, n, val_cercato, diff, diff_tmp, vicino, vicino2;
   int flag_diff, flag_due_vicini;
   flag_diff = FALSO;
   flag_due_vicini = FALSO;
   i = 0;

   printf("Inserire la lunghezza della sequenza di numeri:\n");
   scanf("%d", &tot);
   printf("Inserire il valore cercato:\n");
   scanf("%d", &val_cercato);
   printf("Inserire i valori:\n");

   while( i < tot)  
   {
      scanf("%d", &n);
      //inizializzo la differenza:
      if(flag_diff == 0)
      {
         diff = abs(val_cercato - n);
         vicino = n;
         flag_diff = VERO;
      }
      else
      { //diff inizializzata
         diff_tmp = abs(val_cercato - n);
         if(diff_tmp < diff)
         {
            vicino = n;
            diff = diff_tmp;
         }
         if(diff_tmp == diff) //due vicini
         {
            vicino2 = n;
            flag_due_vicini = VERO;
         }
      }
      i++;
   }
   if(flag_due_vicini == VERO)
   {
      printf("Il primo valore più vicino a %d è %d, il secondo è %d.\n", val_cercato, vicino, vicino2);
   }
   else
   {
      printf("Il valore più vicino a %d è %d.\n", val_cercato, vicino);
   }
   return EXIT_SUCCESS;
}
#endif