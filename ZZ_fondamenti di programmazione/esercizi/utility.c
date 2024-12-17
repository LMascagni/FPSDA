#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utility.h"

//swap tra interi
void swap (int *ptr_x, int *ptr_y)
{
   int tmp;
   tmp = *ptr_x;
   *ptr_x = *ptr_y;
   *ptr_y = tmp;
}

//calcolo esponente
double potenza (int esp, double x)
{
   double pot = 1;
   for (int j = 0; j < esp; j++)
   {
      pot *= x;
   }
   return pot;
}

//calcolo fattoriale
int fattoriale (int n)
{
   int fatt = 1;
   for (int i = 1; i <= n; i++)
   {
      fatt *= i;
   }
   return fatt;
}

//calcolo valore assoluto
double val_ass (double x)
{
   return (x >= 0)? x: -x;
}

//calcolo seno di x
double senox(double x, int fatt, double pot, int segno, int esp)
{
   return (potenza(esp, x)*segno)/fattoriale(esp);
}

//volume sfera
long double vsfera (double raggio)
{
   return M_PI*raggio*raggio*raggio*4/3;
}

//volume sfera pi arrotondato
long double vsfera_pi_arr (double raggio, double digits)
{
   double pi;
   pi = arrotondamento(M_PI, digits);
   return pi*raggio*raggio*raggio*4/3;
}

//volume cubo
long double vcubo (double lato)
{
   return lato*lato*lato;
}

//area di un triangolo
long double area_tri (double b, double h)
{
   return b*h/2;
}
//volume parallelepipedo a base triangolare
long double vparall_ret_bas_tri (double b, double h, double h_para)
{
   return area_tri(b, h)*h_para;
}

//arrotondamento a n cifre decimali
double arrotondamento(double x, double digits)
{
   long int tmp = x*pow(10,digits);
   double y = tmp/pow(10, digits);
   return y;
}

//spinta di archimede= peso H2O = g * massaH20 = g * volumeSpostato*densitàH20
double spinta_archimede(double raggio)
{
   return G*DH2O*vsfera_pi_arr(raggio, 6);
}

int MCD (int m, int n)
{
   int m1, n1, mcd;
   n1 = n;
   m1 = m;
   mcd = n; //in caso n = m mcd è uguale a uno dei due
   while( n1 != m1 )
   {
      printf("n1 = %d  m1 = %d\n", n1, m1);
      if( n1 > m1 )
      {
         n1 -= m1;
         mcd = n1;
      }
      if( n1 < m1 )
      {
         m1 -= n1;
         mcd = m1;
      }
   }
   return mcd;
}

//inserimento e controllo semplice: il numero intero deve essere maggiore di n
void inserimento_e_controllo_semplice (int *input, int n)
{
   do
   {
      printf("Inserire un numero > %d\n", n);
      scanf("%d", input); //input : è il puntatore in sè: contenitore

      if(*input <= n) //*input: valore contenuto dal puntatore
      {
         printf("Valore non valido. Inserire un numero maggiore di %d:\n", n);
      }
      
   } while( *input <= n );
   return;
}

//da testare
//inserimento e controllo range: il numero intero deve essere compreso nel range
void inserimento_e_controllo_range (int *input, int MINIMO, int MASSIMO) //costanti o valori inseriti o definiti nel programma chiamante o dall'utente
{
   do
   {
      printf("Inserire un numero compreso tra %d e %d \n", MINIMO, MASSIMO);
      scanf ("%d", input);
      if (!(*input >= MINIMO && *input <= MASSIMO))
      {
         printf("ERRORE: il numero inserito non è compreso tra %d e %d.\n", MINIMO, MASSIMO);
      }
   } while(!(*input >= MINIMO && *input<= MASSIMO));

   return;
}