//MCD CON IL METODO DEI DECREMENTI SUCCESSIVI
/*
MCD = minimo tra m ed n
controlla se m e n sono entrambi divisibili per MCD:
 se sì, stampa e termina;
 se no, decrementa di 1 MCD e ripeti
 (finché MCD non diventa 1)
*/

#include <stdio.h>
#include <stdlib.h>

#define FALSO 0
#define VERO 1

int main()
{
   int m, n, mcd;
   int flag_non_trovato_mcd;
   flag_non_trovato_mcd = VERO;

//inserimento e controllo su m
   printf("Inserire m > 0:\n");
   do
   {
      scanf("%d", &m);
      if(!(m > 0))
      {
         printf("Valore non valido. Inserire un numero maggiore di 0:\n");
      }
   } while( !(m > 0) );

//inserimento e controllo su n
   printf("Inserire n > 0:\n");
   do
   {
      scanf("%d", &n);
      if(!(n > 0))
      {
         printf("Valore non valido. Inserire un numero maggiore di 0:\n");
      }
   } while( !(n > 0) );

//calcolo MCD
   int test_i = 0;
   mcd = (m < n ? m : n);
   while(flag_non_trovato_mcd)
   {
      if( m % mcd == 0 && n % mcd == 0)
      {
         printf("MCD(%d, %d) = %d\n", m, n, mcd);
         flag_non_trovato_mcd = FALSO;
      }
      else
      {
         mcd--;
      }
      //test
      printf("ciclo %d. MCD = %d\n", test_i, mcd);
      test_i++;
   }
   if( mcd == 1 )
   {
      printf("%d e %d sono primi tra loro.\n", m, n);
   }

   return EXIT_SUCCESS;
}