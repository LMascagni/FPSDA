#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int main()
{
   int tot, i;
   char solido;
   double raggio, lato, b, h, h_para;
   long double volume_tot;
   volume_tot = 0;
   /*
   -inserisci il numero di solidi (ciclo for)
   -inserisci la lettera che identifica il solido
   -nello switch decidi che operazioni fare per calcolare il volume
   esegui la somma dei volumi*/
   printf("Quanti solidi?\n");
   scanf("%d", &tot);
   //eventuale controllo_su_inserimento: devi prima far funzionare i puntatori
   printf("Inserire il tipo di solido:\n- sfera (s)\n- cubo (c)\n- parallelepipedo (p)\n");
   
   for (i = 0; i < tot; i++)
   {
      while (getchar() != '\n');
      printf("Tipo di solido n. %d (s, c, p): \n", i+1);
      scanf("%c", &solido);

      switch (solido)
      {
         case 's':
            printf("- raggio: ");
            scanf("%lf", &raggio);
            volume_tot += vsfera (raggio);
            break;
         case 'c':
            printf("- lato: ");
            scanf("%lf", &lato);
            volume_tot += vcubo (lato);
            break;
         case 'p':
            printf("- base del triangolo di base: ");
            scanf("%lf", &b);
            printf("- altezza del triangolo di base: ");
            scanf("%lf", &h);
            printf("- altezza del parallelepipedo: ");
            scanf("%lf", &h_para);
            volume_tot += vparall_ret_bas_tri(b, h, h_para);
            break;
         default:
            printf("Solido non riconosciuto.\n");
            i--;
            break;
      }
   }
   printf("VOLUME TOTALE: %Lf\n", volume_tot);
   return EXIT_SUCCESS;
}

//%.2lf nel printf questo comando stampa 2 cifre dopo la virgola

/*
sinx
3 funzioni: int main, fettoriale, potenza
usa un do while

MCM:
usa le printf di debug per tracciare l'efficienza dell'algoritmo

per calcolare il valore assoluto non usare abs(), usa una funzione tua

operando1? operando2: operando3 -> è un'espressione

operando1= condizione
l'espressione vale operando2 se è vera
e operando3 se è falsa

es: 
   double myabs(double x)
   {
      return x>=0? x: -x;
   }

nota: in excel la funzione if ha la stessa sintassi
*/