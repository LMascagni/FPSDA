#include <stdio.h>
#include <stdlib.h>

void nome_abbreviato(char s[], char t[]);

int main()
{

   char s[100];
   char t[100];

   fgets(t, 100, stdin);

   nome_abbreviato(s, t);

   printf(">%s<\n", s);

   return 0;
}

void nome_abbreviato(char t[], char s[])
{
   int is = 0, it = 0;
   int inparola = 0;

   // Posizionati sulla virgola e salta la virgola
   while (s[is] != ',' && s[is] != '\0') is++;
   if (s[is] == ',') is++;

   // Processa il nome
   while (s[is] != '\0')
   {
      if (s[is] != ' ')
      {
         if (!inparola)
         {
            t[it++] = s[is];
            t[it++] = '.';
            t[it++] = ' ';
            inparola = 1;
         }
      }
      else
      {
         inparola = 0;
      }
      is++;
   }

   // Copia il cognome
   is = 0;
   while (s[is] != ',' && s[is] != '\0')
   {
      t[it++] = s[is++];
   }

   // Termina la stringa t
   t[it] = '\0';
}
