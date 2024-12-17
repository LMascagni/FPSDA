//max sequenza di numeri scegliendo solo i numeri pari data la lunghezza della sequenza n all'inizio

/*
1) imposto il ciclo
   1.a condizione del ciclo
   1.b inizializzi le variabili
   1.c aggiorno il contatore
2) definizione delle operazioni interne al ciclo
FARE LA TRACCIA DELLA COMPUTAZIONE
3) traduzione in C
*/

/*
1) impostazione del ciclo
1.b:
inizializza i a zero;
leggi n da tastiera;
b.f: inizializza a falso il flag massimo_inizializzato;
1.a:
while(i < n)
{
   2) definizione delle operazioni interne del ciclo
   2.aleggi il valore corrente
   2.b usalo per aggiornare il max;
2.c:  if (il numero è pari)
      {
   2.d: //esegui il confronto con il max oppure inizializza il max;
         if(max è inizializzato)
         {
            if(valore corrente)
            {
               aggiorna il max;
            }
         }
         else
         {
            2.e: inizializza il max con il valore corrente;
            memorizza il fatto che max è inizializzato;
         }
      }
   1.c: incrementa di 1 i;
}
2.g: stampa il risultato;
2.h: if(max è stato inizializzato)
{
   stampa il valore del max;
}
else
{
   stampa un messaggio di "assenza dati";
}
*/
// 3) traduzione in glinguaggio C
#include <stdio.h>
#include <stdlib.h>

#define FALSO = 0;
#define VERO = 1;

int main()
{
   int i, n, valore, max;
   int flag_max_inizializzato;
   i = 0;
   printf ("Inserire il numero di valori: ")
   scanf ("%d", &n);
   flag_max_inizializzato = FALSO;

   while (i < n)
   {
      printf ("Inserisci il valore corrente: ");
      scanf("%d", &valore);

      if (valore % 2 == 0)
      {
         if (flag_max_inizializzato) /*non serve scrivere flag_max_inizializzato == FALSO perchè il programma lo legge come: if falso {allora...} 
         (se falso/0 allora fai... . quando il valore sarà vero l'if non funziona più)*/
         {
            if (valore > max)
            {
               max = valore;
            }
         }
         else
         {
            max = valore;
            flag_max_inizializzato = VERO; //dubbio sull'if del flag scritto così: if(flag)
         }
      }
      i++;
   }
   if (flag_max_inizializzato)
   {
      printf ("Il massimo é: %d\n", max);
   }
   else
   {
      printf ("Non sono stati inseriti numeri pari\n");
   }

   return EXIT_SUCCESS;
}