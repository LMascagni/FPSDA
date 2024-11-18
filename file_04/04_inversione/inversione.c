#include <stdio.h>
#include <stdlib.h>

void wordreverse (char s[]);

int main() {
   char s[100];

   printf ("Inserisci una stringa: ");
   fgets (s, 100, stdin);

   wordreverse (s);

   printf ("La stringa invertita e`: %s\n", s);



   return 0;
}

void wordreverse (char s[])
{
   char parola[100];

   //while(ci sono ancora caratteri)
   {
      //mettere ogni carattere in parola fin al primo spazio

      //fare l'inverso di parola

      //reinserire la parola sostituita nella stringa originale
   }
}