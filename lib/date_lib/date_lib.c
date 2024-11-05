
#include <stdio.h>
#include <stdlib.h>
#include "date_lib.h"
#include "utility.h"


void leggi_data (int *ptr_g, int *ptr_m, int *ptr_a)
{
   #if 0
   int giorno, mese, anno;

   printf ("inserisci la data (g, m, a): ");
   scanf ("%d %d %d", &giorno, &mese, &anno);

   // ora scrivi i valori nelle variabili del programma che ti ha chiamata
   *ptr_g = giorno;
   *ptr_m = mese;
   *ptr_a = anno;
   #endif

   // versione da nerd!
   printf ("inserisci la data (g, m, a): ");
   scanf ("%d %d %d", ptr_g, ptr_m, ptr_a); // passo direttamente gli indirizzi delle variabili del main

   if (!checkdate (*ptr_g, *ptr_m, *ptr_a))
   {
      printf ("la data %d %d %d non e` valida!\n",
              *ptr_g, *ptr_m, *ptr_a);
      exit (EXIT_FAILURE);
   }

   return;
}


int differenza_tra_date (int g1, int m1, int a1, int g2, int m2, int a2)
{
   int contatore;

   // inizializza il contatore a zero;
   contatore = 0;

   // parti con una data corrente dalla data anteriore;
   if (confronta_date (g1, m1, a1, g2, m2, a2) > 0)
   {
      // scambia le date
      scambia_date (&g1, &m1, &a1, &g2, &m2, &a2);
   }

   // while (la data corrente viene prima della data di destinazione)
   while (confronta_date (g1, m1, a1, g2, m2, a2) < 0)
   {
      // aggiorna data corrente al giorno successivo;
      giorno_successivo (&g1, &m1, &a1);

      // incrementa il contatore;
      contatore++;
   }

   return contatore;
}

int confronta_date (int g1, int m1, int a1, int g2, int m2, int a2)
{
   /* restituisce:
      0  se le date sono uguali
      -1 se data1 viene prima di data2
      +1 se data1 viene dopo data 2
   */

   if (a1 < a2)
      return -1;
   else if (a1 > a2)
      return +1;
   else
   {
      // a1 e` uguale ad a2

      if (m1 < m2)
         return -1;
      else if (m1 > m2)
         return +1;
      else
      {
         // anche i mesi sono uguali

         if (g1 < g2)
            return -1;
         else if (g1 > g2)
            return +1;
         else  // anche i giorni sono uguali
            return 0;
      }
   }
}

void scambia_date (int *p_g1, int *p_m1, int *p_a1, 
                  int *p_g2, int *p_m2, int *p_a2)
{
   swap (p_g1, p_g2);
   swap (p_m1, p_m2);
   swap (p_a1, p_a2);

   return;
}

void giorno_successivo (int *p_g1, int *p_m1, int *p_a1)
{
   // giorno = giorno + 1;
   (*p_g1)++;   // oppure    *p_g1 = *p_g1 + 1;

   // if (giorno e` maggiore dei giorni di quel mese)
   if (*p_g1 > giorni_del_mese (*p_m1, *p_a1))
   {
      // il giorno ritorna ad 1;
      *p_g1 = 1;
      // mese = mese + 1;
      (*p_m1)++;

      // if (mese > 12)
      if (*p_m1 > 12)
      {
         // il mese ritorna ad 1;
         *p_m1 = 1;
         // incrementa anno di uno;
         (*p_a1)++;
      }
   }

   return;
}

void giorno_precedente (int *p_g1, int *p_m1, int *p_a1)
{
   // giorno = giorno - 1;
   (*p_g1)--;   // oppure    *p_g1 = *p_g1 - 1;

   // if (giorno e` minore di 1)
   if (*p_g1 < 1)
   {
      // mese = mese - 1;
      (*p_m1)--;

      // if (mese < 1)
      if (*p_m1 < 1)
      {
         // mese diventa 12 e l'anno diminuisce
         *p_m1 = 12;
         (*p_a1)--;
      }

      // il giorno va al numero di giorni del mese precedente;
      *p_g1 = giorni_del_mese (*p_m1, *p_a1);
   }

   return;
}


int checkdate (int g, int m, int a)
{
   // controlla anno
   if (a < 1582)
      return 0;

   // controlla mese (se non compreso tra 1 e 12)
   if ( !(m >= 1 && m <= 12) )
      return 0;

   // controlla giorno (non compreso tra 1 e i giorni di quel mese)
   if ( !(g >= 1 && g <= giorni_del_mese (m, a)) )
      return 0;

   // se la funzione non e` terminata prima, la data e` valida
   return 1;
}


int giorni_del_mese (int mese, int anno)
{
   // filastrocca...

   switch (mese)
   {
      case 11:
      case 4:
      case 6:
      case 9:  return 30;

      case 2:  if (bisestile (anno))
                  return 29;
               else
                  return 28;

      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12: return 31;

      default:  printf ("mese %d non valido!\n", mese);
                exit (EXIT_FAILURE);
   }
}

int bisestile (int anno)
{
   return ( (anno % 4 == 0) && (anno % 100 != 0) )
             || (anno % 400 == 0);

   /* 
   if ( ( (anno % 4 == 0) && (anno % 100 != 0) ) || (anno % 400 == 0) )
      return 1;
   else
      return 0;
   */
}

void somma_n_a_data (int *p_g, int *p_m, int *p_a, int n)
{
   int contatore;

   // se n >= 0
   if (n >= 0)
   {
      // chiama n volte giorno_successivo
      for (contatore = 0; contatore < n; contatore++)
      {
         giorno_successivo (p_g, p_m, p_a);
      }
   }
   else    // altrimenti
   {
      // chiama n volte giorno_precedente (n e` negativo)
      for (contatore = 0; contatore < -n; contatore++)
      {
         giorno_precedente (p_g, p_m, p_a);
      }
   }

   return;
}

