/*
n1 = n;
m1 = m;
while (n1 è diverso da m1)
{
 sottrai dal maggiore tra n1 e m1
 l’altro numero
}
alla fine del ciclo n1 (o m1, avendo
lo stesso valore) è il MCD
*/

#include <stdio.h>
#include <stdlib.h>

#define FALSO 0
#define VERO 1

int main()
{
   int m, n, n1, m1, mcd;
   //int flag_non_trovato_mcd;
   //flag_non_trovato_mcd = VERO;

//VERSIONE AVANZATA: USO UNA FUNZIONE DI INSERIMENTO PER INSERIRE m E n
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
   n1 = n;
   m1 = m;
   int test_i = 0;
   while( n1 != m1 )
   {
      if( n1 > m1 )
      {
         n1 -= m1;
         mcd = n1;
      }
      if( n1 < m1 )
      {
         m1 -= n1;
         mcd = m1;
      }
      //test
      printf("ciclo %d. MCD = %d\n", test_i, mcd);
      test_i++;
   }
   if( mcd == 1 )
   {
      printf("%d e %d sono primi tra loro.\n", m, n);
   }
   else
   {
      printf("MCD(%d, %d) = %d\n", m, n, mcd);
   }

   return EXIT_SUCCESS;
}