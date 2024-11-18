#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_lib.h"

void mygets (char s[])
{
   int i;
   char carattere_letto;

   i = 0;

   while ( (carattere_letto = getchar()) != '\n')
   {
      s[i] = carattere_letto;
      i++;
   } 

   s[i] = '\0';

   return;
}

void myputs (char s[])
{
   int i;

   i = 0;

   while (s[i] != '\0')
   {
      putchar (s[i]);
      i++;
   } 

   putchar ('\n');

   return;
}

int mystrlen (char s[])
{
   int i;
   i = 0;

   while (s[i] != '\0')
   {
      i++;
   }

   return i;
}

void strcatenate (char t[], char s[])
{
   int indice_di_t, indice_di_s;

   indice_di_t = mystrlen (t);

   indice_di_s = 0;

   while (s[indice_di_s] != '\0')
   {
      t[indice_di_t] = s[indice_di_s];
      indice_di_s++;
      indice_di_t++;
   }

   t[indice_di_t] = '\0';

   return;
}

void supersomma (char a[], char b[], char c[])
{
   int i_a, i_b, i_c, riporto, risultato_somma;
   int na, nb;

   i_a = strlen (a) - 1;
   i_b = strlen (b) - 1;

   i_c = (i_a > i_b) ? i_a : i_b;

   c[i_c+1] = '\0';

   riporto = 0;

   while ( ! (i_a < 0 && i_b < 0) )
   {
      if (i_a >= 0)
      {
         na = a[i_a] - '0';
      }
      else
      {
         na = 0;
      }

      if (i_b >= 0)
      {
         nb = b[i_b] - '0';
      }
      else
      {
         nb = 0;
      }

      risultato_somma = na + nb + riporto;

      c[i_c] = risultato_somma % 10 + '0';

      riporto = risultato_somma / 10;

      i_a--;
      i_b--;
      i_c--;
   }

   if (riporto > 0)
   {
      printf ("c'e` anche il riporto!\n");
   }

   return;
}
