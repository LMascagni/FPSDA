
#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"
#include "utility.h"

int leggi_vettore (int v[], int dim_max)
{
   int i, dim;

   // leggi la dimensione
   printf ("leggi_vettore: quanti elementi vuoi inserire? ");
   scanf ("%d", &dim);

   if (dim > dim_max)
   {
      printf ("sono troppi, potranno essere inseriti %d elementi\n", dim_max);
      dim = dim_max;
   }

   // leggi gli elementi
   for (i = 0; i < dim; i++)
   {
      printf ("inserisci l'elemento di indice %d: ", i);
      // printf ("v[%d] = ", i);
      scanf ("%d", &v[i]);
   }

   return dim;
}


void stampa_vettore (int v[], int dim)
{
   int i;

   // stampa gli elementi
   for (i = 0; i < dim; i++)
   {
      printf ("v[%d] = %d\n", i, v[i]);
   }

   return;
}


void inverti_vettore (int v[], int dim)
{
   int i, j;

   // parti dal primo e dall'ultimo elemento;
   i = 0;
   j = dim - 1;

   // while (il primo indice e` strettamente minore del secondo)
   while (i < j)
   {
      // scambia gli elementi;
      swap (&v[i], &v[j]);

      // sposta gli indici verso il centro del vettore
      i++;
      j--;
   }

   /* versione for:
   
   for (i = 0, j = dim - 1;  i < j;  i++, j--)
      swap (&v[i], &v[j]);

   */

   return;
}


void leggi_sequenza_e_aggiorna_i_contatori (int contatori[], int val_min, int val_max)
{
   int valore_letto, indice_contatore;

   // inizializza_i_contatori a zero;
   inizializza_vettore (contatori, val_max - val_min + 1, 0);

   // leggi un valore; (valore minimo - 1 e` il terminatore)
   printf ("inserisci un valore compreso tra %d e %d, %d per finire: ", val_min, val_max, val_min-1);
   scanf ("%d", &valore_letto);

   // while (ci sono ancora valori)
   while (valore_letto != val_min - 1)
   {
      // aggiorna il contatore corrispondente al valore letto;
      if (valore_letto >= val_min && valore_letto <= val_max)
      {
         // contatori[valore_letto]++;  se avessi sempre val_min = 0

         // calcola l'indice del contatore
         indice_contatore = valore_letto - val_min;
         contatori[indice_contatore]++;
      }
      else
      {
         printf ("il valore letto e` stato scartato perche' non valido\n");
      }

      // leggi il valore successivo; (valore minimo - 1 e` il terminatore)
      printf ("inserisci un valore compreso tra %d e %d, %d per finire: ", val_min, val_max, val_min-1);
      scanf ("%d", &valore_letto);
   }

   return;
}


void inizializza_vettore (int v[], int dim, int valore_iniziale)
{
   int i;

   for (i = 0; i < dim; i++)
      v[i] = valore_iniziale;

   return;
}

void stampa_istogramma_orizzontale (int v[], int dim)
{
   int i;

   // per ogni elemento del vettore
   for (i = 0; i < dim; i++)
   {
      // if (il valore e` maggiore di zero)
      if (v[i] > 0)
      {
         // stampa il valore indice
         printf ("%2d ", i);
         // stampa la fila di asterischi
         disegna_linea (v[i]);
         // vai a capo
         printf ("\n");
      }
   }

   return;
}


void disegna_linea (int lunghezza)
{
   int i;

   for (i = 0; i < lunghezza; i++)
      printf ("*");

   return;
}

