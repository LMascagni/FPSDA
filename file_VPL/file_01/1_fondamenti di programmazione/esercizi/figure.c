#include <stdio.h>
#include <stdlib.h>
#define FALSO 0
#define VERO 1
void stampa_linea(int lunghezza);
void stampa_quadrato(int lato);
void stampa_triangolo_rett_iso(int cateto);

int main()
{
   char ch;
   int ch1;
   int flag_errore;
   flag_errore = FALSO;
   printf("Inseire la sequenza con lettera e cifra (LcLcLc...)\n(Le lettere possibili sono L, Q, T)\n");
   while((ch = getchar()) != '\n')
   {
      ch1 = getchar() - '0';
      if(ch1 < 0 || ch1 > 9)
      {
         printf("ERRORE: ul dato non rientra nel range 0-9:\n");
         flag_errore = VERO;
      }
      switch (ch)
      {
         case 'L':
         case 'l':
            if(!flag_errore)
            {
               stampa_linea(ch1);
            }
            printf("\n");
            break;
         case 'Q':
         case 'q':
            if(!flag_errore)
            {
               stampa_quadrato(ch1);
            }
            printf("\n");
            break;
         case 'T':
         case 't':
            if(!flag_errore)
            {
               stampa_triangolo_rett_iso(ch1);
            }
            printf("\n");
            break;
         default:
            printf("ERRORE: dato non corretto.\n");
      }
   }

   return EXIT_SUCCESS;
}


void stampa_linea (int lunghezza)
{
   int i;

   for(i = 0; i < lunghezza; i++) //i++: esegue op, poi incrementa valore. ++i: incrementa valore, poi esegue op.
   {
      printf("*");
   }
   printf("\n");

   return;
}

void stampa_quadrato(int lato)
{
   int i;
   for(i = 0; i < lato; i++)
   {
      stampa_linea (lato);
   }
   return;
}

void stampa_triangolo_rett_iso(int cateto)
{
   int i;
   // for(i = 0; i < lato; i++)
   // {
   //    for(j = 0; j <= i; j++)
   //    {
   //       printf("*");
   //    }
   // printf("\n");
   // }

   for(i = 1; i <= cateto; i++)
   {
      stampa_linea (i);
   }
   return;
}
