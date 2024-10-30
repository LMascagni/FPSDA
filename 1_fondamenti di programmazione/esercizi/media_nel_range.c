/*
leggere n numeri compresi tra -50 e +50, e ne calcoli la media
#define massimo = 50
#define minimo = -50

se l'utente inserisce un numero fuori dal range, segnalare l'errore e richiedere il numero
*/

/*
leggi numero n tot
leggi numero in ingresso
ripetere per n volte
   while(i < n)
   {
      verificare se il numero in ingresso è compreso nel range
         if (numero > MINIMO && numero < MASSIMO)
         {
            calcola la somma
               somma += numero
            aumenta il contatore
         }
         else //se non lo è: errore + richiedere il numero
         {
            errore
            leggi il numero in ingresso
         }
   }
calcola la media
stampa la media
*/

#include <stdio.h>
#include <stdlib.h>

#define MASSIMO 50
#define MINIMO -50

int main()
{
  // non serve definire somma, vedi in fondo
  // int totale, numero, somma, i;
  // double media;
  int totale, numero, somma, i;
  somma = 0;
  i = 0;

  printf("Inserire la lunghezza della seguenza di numeri da sommare\n");
  scanf("%d", &totale);

  while( i < totale )
  {
     do
     {
         printf("Inserire un numero compreso tra %d e %d \n", MINIMO, MASSIMO);
         scanf ("%d", &numero);
         if (!(numero >= MINIMO && numero <= MASSIMO))
         {
            printf("ERRORE: il numero inserito non è compreso tra %d e %d.\n", MINIMO, MASSIMO);
         }
     }
     while(!(numero >= MINIMO && numero <= MASSIMO));

   somma += numero;
   i++;
  }
  // media = somma/(double)totale;
  // printf("La media intera è: %d\n", media);
  if( i > 0 )
  {
   printf("La media è: %lf\n", somma / (double)i);
  } else
  {
   printf("Non sono stati inseriti dati.");
  }
  // i = totale, posso infatti fare la media
  // dividendo somma per i o per totale
  //%lf: double
  //%f: float

  return EXIT_SUCCESS;
}