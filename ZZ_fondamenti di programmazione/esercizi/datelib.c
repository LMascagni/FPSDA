#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "datelib.h" //per librerie private, create da noi
//NOTA: MANTIENI TUTTI I FILE NELLO STESSO DIRETTORIO

//leggi una data
void leggi_data( int *puntatore_giorno, int *puntatore_mese, int *puntatore_anno)
{
   int g, m, a;
   printf("Inserisci giorno, mese e anno:");
   scanf("%d %d %d", &g, &m, &a);
   //copia i valori letti nelle locazioni di memoria della funzione chiamante
   *puntatore_giorno = g;
   *puntatore_mese = m;
   *puntatore_anno = a;

   return;
}

void stampa_data( int giorno, int mese, int anno)
{
   printf("giorno %d, mese %d, anno %d\n", giorno, mese, anno);
   
   return;
}

//differenza in giorni tra date
int differenza_tra_date( int g1, int m1, int a1, int g2, int m2, int a2)
{
  int contatore;
  contatore = 0;
  if (confronto_date (g1, m1, a1, g2, m2, a2) > 0)
  {
      scambia_date (&g1, &m1, &a1, &g2, &m2, &a2);
  }
  while(confronto_date (g1, m1, a1, g2, m2, a2) < 0)
  {
      //passa al gg successivo con la prima data
      giorno_successivo(&g1, &m1, &a1); //operazione sconsigliabile perchè vado a modificare la data di partenza, ma ora stiamo lavorando su copie create dalla funzione che opera nel programma chiamante
      contatore++;
  }
  return contatore;
}

//confronto le due date:
int confronto_date( int g1, int m1, int a1, int g2, int m2, int a2 )
{
   if (a1 < a2)
      return -1;
   else if (a1 > a2)
      return 1;
   else //anni uguali
   {
      if (m1 < m2)
         return -1;
      else if (m1 > m2)
         return 1;
      else //mesi uguali
      {
         if (g1 < g2)
            return -1;
         else if (g1 > g2)
            return 1;
         else
            return 0; //le date sono uguali

      }
   }
}

//scambio date:
void scambia_date (int *p_g1, int *p_m1, int *p_a1, int *p_g2, int *p_m2, int *p_a2)
{
   //scambia i giorni
   swap(p_g1, p_g2);
   //scambia i mesi
   swap(p_m1, p_m2);
   //scambia i anni
   swap(p_a1, p_a2);
}

//giorno successivo:
int giorno_successivo (int *p_g, int *p_m, int *p_a)
{
   //aggiungo 1 al gg;
   (*p_g)++;
   //if(giorno aggiornato > giorni di quel mese)
   if(*p_g > numero_giorni_del_mese(*p_m, *p_a)) //passo i valori puntati, non i puntatori
   {
      //pongo il giorno a 1;
      *p_g = 1;
      //aggiungo uno al mese;
      (*p_m)++;
      if(*p_m > 12)
      {
         //pongo il mese a 1;
         *p_m = 1;
         //aggiungo uno all'anno;
         (*p_a)++;
      }
   }
   return *p_g;
}

//controllo validità di una data:
int chkdate( int giorno, int mese, int anno)
{
   //se l'anno è precedente all'entrata in vigore del calendario gregoriano, la data non è valida
   if( anno < 1582 )
      return 0; //la funzione esce direttamente: la data non è valida, quindi è falsa
   //controlla se il mese è compreso tra 1 e 12
   if( mese < 1 || mese > 12)
      return 0;
   //controllo de il giorno è valido
   if( giorno < 1 || giorno > numero_giorni_del_mese(mese, anno))
      return 0;
   //ho passato tutti i controlli precedenti: la data è valida

   return 1;
}

int numero_giorni_del_mese (int mese, int anno)
{
   switch (mese)
   {
      case 4: //aprile
      case 6: //giugno
      case 9: //settembre
      case 11: //novembre
         return 30; //non serve il breaperchè la funzione termina con il return, quindi non eseguirebbe la riga successiva con il break
      
      case 2: //febbrario
         return (bisestile(anno)? 29 : 28); //dovrebbe funzionare...

      case 1: //gennaio
      case 3: //marzo
      case 5: //maggio
      case 7: //luglio
      case 8: //agosto
      case 10: //ottobre
      case 12: //dicembre
         return 31;
      
      default:
         printf("nemro_giorni_del_mese: mese %d non valido.\n", mese);
         exit (EXIT_FAILURE);
   }
}

int bisestile (int anno)
{
   return(( ((anno % 4 == 0) && !(anno % 100 == 0)) || (anno % 400 == 0) ));
}