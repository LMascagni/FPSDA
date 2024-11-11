
#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"
#include "utility.h"



int leggi_interi_vettore (int v[], int dim_max)
{
   int i, dim;

   // leggi la dimensione
   printf ("inserisci il numero di valori da scrivere nel vettore: ");
   scanf ("%d", &dim);

   if (dim > dim_max)
   {
      printf ("sono troppi, potranno essere inseriti %d elementi\n", dim_max);
      dim = dim_max;
   }

   // leggi gli elementi
   for (i = 0; i < dim; i++)
   {
      printf ("v[%d] = ", i);
      // printf ("v[%d] = ", i);
      scanf ("%d", &v[i]);
   }

   return dim;
}

int leggi_testo_vettore (int v[], int dim_max)
{
   int dim;
   dim = 0;
   char chr;


   while ((chr = getchar()) != EOF)
   {
      v[dim] = chr;
      
      dim++;
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
   i = 0;
   j = dim - 1;
   for (i = 0, j = dim - 1;  i < j;  i++, j--)
      swap (&v[i], &v[j]);

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

void stampa_istogramma_verticale (int v[], int dim, int x_axis_min, int x_axis_max, int x_axis_var_type, int enable_norm, int y_axis_min, int y_axis_max)
{
   int max_value_index;
   double scale;

   max_value_index = massimo_in_vettore(v, dim);

   scale = 1.0;

   if (enable_norm)
   {
      scale = calcola_fattore_di_scala(v[max_value_index],y_axis_max); //TODO: also add y_axis_min
   }

   printf("fattore di scala: %lf\n", scale);

   int i, j;
   //stampa degli istogrammi
   for (i = (v[max_value_index] / scale); i >= 0; i--)
   {
      for(j = 0; j < dim; j++ )
      {
         //printf("%d%d ", i, j);
         if (v[j] >= (i * scale))
         {
            switch (x_axis_var_type)
            {
               case 'd':
                  printf(" * ");
                  break;
               case 'c':
                  printf("*");
            }
         }
         else
         {
            switch (x_axis_var_type)
            {
               case 'd':
                  printf("   ");
                  break;
               case 'c':
                  printf(" ");
            }
         }
      }
      printf("\n");
   }
   //stampa numeri fine del grafico
   for (i = x_axis_min; i <= x_axis_max; i++)
   {
      switch (x_axis_var_type)
      {
         case 'd':
            printf("%2d ", i);
            break;
         case 'c':
            printf("%c", i);
      }
   }
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

void disegna_linea (int lunghezza)
{
   int i;

   for (i = 0; i < lunghezza; i++)
      printf ("*");

   return;
}

void aggiorna_contatori (int v[], int dim, int val_min, int val_max, int counters[])
{
   int i;

   inizializza_vettore (counters, val_max - val_min + 1, 0);

   for (i = 0; i < dim; i++)
   {
      if (v[i] < val_min || v[i] > val_max)
      {
         printf("e` stato scartato il voto non valido %d\n", v[i]);
      }
      else
      {
         counters[v[i] - val_min]++;
      }
   }
   return;
}

int massimo_in_vettore(int v[], int dim)
{
   int max_index;
   
   max_index = 0;

   int i;
   
   for(i = 0; i < dim ; i++)
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