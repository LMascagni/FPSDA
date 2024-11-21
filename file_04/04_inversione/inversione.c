#include <stdio.h>
#include <stdlib.h>

void wordreverse(char s[]);

int main()
{
   char s[100];

   // printf("Inserisci una stringa: ");
   fgets(s, 100, stdin);

   wordreverse(s);

   puts(s);

   return 0;
}

void wordreverse(char s[])
{
   int i = 0;
   while (s[i] != '\0')
   {
      // Trova l'inizio della parola
      // Ignora gli spazi e i caratteri di invio a capo
      // while ((s[i] == ' ' || s[i] == '\n') && s[i] != '\0')
      while (s[i] <= ' ' && s[i] != '\0')
      {
         i++;
      }
      int start = i;

      // Trova la fine della parola
      //while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
      while (s[i] > ' ' && s[i] != '\0')
      {
         i++;
      }
      int end = i - 1;

      // Inverte la parola
      while (start < end)
      {
         char temp = s[start];
         s[start] = s[end];
         s[end] = temp;
         start++;
         end--;
      }
   }
   return;
}