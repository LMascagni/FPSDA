
#include <stdio.h>
#include <stdlib.h>

#define FALSO 0
#define VERO 1

void controllo_su_inserimento (int *a);
int MCD (int a, int b);

int main()
{
   int m, n, *mp, *np;

//USA I PUNTATORI!!!!!!!!!!!
//inserimento e controllo su m
   printf("Inserire m > 0:\n");
   scanf("%d", &m);
   
   controllo_su_inserimento (mp);
   printf("m = %d", m);
   printf("m = %d", mp);

//inserimento e controllo su n
   printf("Inserire n > 0:\n");
   scanf("%d", &n);
   controllo_su_inserimento (*n);
   printf("n = %d", n);

//calcolo MCD
   if( MCD (m, n) != 1 )
   {
      printf("MCD(%d, %d) = %d\n", m, n, MCD (m, n));
   }
   else
   {
      printf("%d e %d sono primi tra loro.\n", m, n);
   }
   return EXIT_SUCCESS;
}

void controllo_su_inserimento (int *a)
{
   while( !(a > 0) )
   {
      printf("Valore non valido. Inserire un numero maggiore di 0:\n");
      scanf("%d", &a);
      printf("a = %d", a);
   }

   return;
}

int MCD (int a, int b)
{
   int flag_non_trovato_mcd = VERO;
   int mcd;
   mcd = (a < b ? a : b);

   while(flag_non_trovato_mcd)
   {
      if( a % mcd == 0 && b % mcd == 0)
      {
         flag_non_trovato_mcd = FALSO;
         return mcd;
      }
      else
      {
         mcd--;
      }
   }
   return 1;
}