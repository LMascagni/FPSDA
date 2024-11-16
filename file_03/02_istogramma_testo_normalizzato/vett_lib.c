#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vett_lib.h"
#include "utility.h"

int leggi_vettore (int v[], int dim_max)
{
   int i, dim;

   printf ("leggi_vettore: quanti elementi vuoi inserire? ");
   scanf ("%d", &dim);

   if (dim > dim_max)
   {
      printf ("sono troppi, potranno essere inseriti %d elementi\n", dim_max);
      dim = dim_max;
   }

   for (i = 0; i < dim; i++)
   {
      printf ("inserisci l'elemento di indice %d: ", i);
      scanf ("%d", &v[i]);
   }

   return dim;
}

void stampa_vettore (int v[], int dim)
{
   int i;

   for (i = 0; i < dim; i++)
   {
      printf ("v[%d] = %d\n", i, v[i]);
   }

   return;
}

void inverti_vettore (int v[], int dim)
{
   int i, j;

   for (i = 0, j = dim - 1;  i < j;  i++, j--)
      swap (&v[i], &v[j]);

   return;
}

void leggi_sequenza_e_aggiorna_i_contatori (int contatori[], int val_min, int val_max)
{
   int valore_letto, indice_contatore;

   inizializza_vettore (contatori, val_max - val_min + 1, 0);

   printf ("inserisci un valore compreso tra %d e %d, %d per finire: ", val_min, val_max, val_min-1);
   scanf ("%d", &valore_letto);

   while (valore_letto != val_min - 1)
   {
      if (valore_letto >= val_min && valore_letto <= val_max)
      {
         indice_contatore = valore_letto - val_min;
         contatori[indice_contatore]++;
      }
      else
      {
         printf ("il valore letto e` stato scartato perche' non valido\n");
      }

      printf ("inserisci un valore compreso tra %d e %d, %d per finire: ", val_min, val_max, val_min-1);
      scanf ("%d", &valore_letto);
   }

   return;
}

void leggi_testo_e_aggiorna_i_contatori (int contatori[], int val_min, int val_max)
{
   int indice_contatore;
   char valore_letto;

   inizializza_vettore (contatori, val_max - val_min + 1, 0);

   valore_letto = getchar();
   valore_letto = minuscola (valore_letto);

   while (valore_letto != EOF)
   {
      if (valore_letto >= val_min && valore_letto <= val_max)
      {
         indice_contatore = valore_letto - val_min;
         contatori[indice_contatore]++;
      }

      valore_letto = getchar();
      valore_letto = minuscola (valore_letto);
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

   for (i = 0; i < dim; i++)
   {
      if (v[i] > 0)
      {
         printf ("%2d ", i);
         disegna_linea (v[i]);
         printf ("\n");
      }
   }

   return;
}

void stampa_istogramma_verticale (int v[], int dim, int x_axes_min, int x_axes_max)
{
   int max_value_index;

   max_value_index = massimo_in_sottovettore(v, 0, dim-1);
   int i, j;
   
   for (i = 0; i < v[max_value_index]; i++)
   {
      for(j = 0; j < dim; j++ )
      {
         if (v[j] >= (v[max_value_index] - i))
         {
            printf(" * ");
         }
         else
         {
            printf("   ");
         }
      }
      printf("\n");
   }

   for (i = x_axes_min; i <= x_axes_max; i++)
   {
       printf("%2d ", i);
   }
   return;
}

void stampa_istogramma_verticale_testo (int v[], int dim, int quota_massimo_isto_testo)
{
   int i, indice_del_massimo, quota_corrente;
   double fattore_scala;
   char ch;

   indice_del_massimo = massimo_in_sottovettore (v, 0, dim-1);

   if (v[indice_del_massimo] > quota_massimo_isto_testo)
   {
      fattore_scala = v[indice_del_massimo] / (double) quota_massimo_isto_testo;
   }
   else
   {
      fattore_scala = 1;
   }

   printf ("fattore di scala = %f\n", fattore_scala);

   quota_corrente = v[indice_del_massimo];

   while (quota_corrente > 0)
   {
      for (i = 0; i < dim; i++)
      {
         if (v[i] >= quota_corrente)
         {
            printf ("*");
         }
         else
         {
            printf (" ");
         }
      }
      printf ("\n");

      quota_corrente -= fattore_scala;
   }

   for (ch = 'a'; ch <= 'z'; ch++)
   {
      printf ("%c", ch);
   }
   printf ("\n");

   return;
}

void disegna_linea (int lunghezza)
{
   int i;

   for (i = 0; i < lunghezza; i++)
      printf ("*");

   return;
}

double calcola_fattore_di_scala(int max_value, int max_height)
{
   if (max_value > max_height)
   {
      return max_value / (double) max_height;
   }
   else
   {
      return 1.0;
   }
}

int massimo_in_sottovettore(int v[], int inizio, int fine)
{
   int max_index;
   
   max_index = inizio;

   int i;
   
   for(i = inizio; i <= fine ; i++)
   {
       if (v[max_index] < v[i])
       {
           max_index = i;
       }
   }

   return max_index;
}

int cerca_in_sottovettore(int v[], int inizio, int fine, int valore_cercato)
{
   int i;
    for (i = inizio; i <= fine; i++) {
        if (v[i] == valore_cercato) {
            return i;
        }
    }
    return -1;
}

void scorrimento_circolare (int v[], int dim)
{
    int i;
    int temp;
    temp = v[dim - 1];
    for (i = dim - 1; i > 0; i--)
    {
        v[i] = v[i - 1];
    }
    v[0] = temp;
    return;
}
