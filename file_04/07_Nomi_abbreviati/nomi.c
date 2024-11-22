#include <stdio.h>
#include <stdlib.h>

void nome_abbreviato(char s[], char t[]);

int main()
{

   char s[100];
   char t[100];

   fgets(t, 100, stdin);

   nome_abbreviato(s, t);

   printf("%s", s);

   return 0;
}

void nome_abbreviato(char s[], char t[])
{
   int i, j;
   i = 0;
   j = 0;

   // salta il cognome e la virgola
   while (t[i] != ',' && t[i++] != '\0');
   i++;

   printf("s[%d]: %c\n", i, t[i]);

   // cerca il primo carattere del nome
   while (t[i] != '\0')
   {
      //salta gli spazi e cerca il primo carattere del nome
      while (t[i] <= ' ' && t[i++] != '\0');

      //printf("s[%d]: %c\n", i, t[i]);

      // prendi il primo carattere del nome e scrivilo in s[]
      s[j++] = t[i];
      s[j++] = '.';
      s[j++] = ' ';

      // cerca la fine del nome
      while (t[i] > ' ' && t[i++] != '\0');

      //printf("s[%d]: %c\n", i, t[i]);
      //printf("successivo s[%d]: %c\n", i + 1, t[i + 1]);
      // prendi il primo carattere della parola e scrivila in s[] e passa a quella successiva
   }

   // aggiungi il cognome

   i = 0;
	printf("j=%d", j);
   while (t[i] != ',')
   {
      printf("t_%c\n",t[i]);
      s[j] = t[i];
      
      i++;
      j++;
   }
}