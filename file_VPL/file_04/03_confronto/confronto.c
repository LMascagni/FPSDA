#include <stdio.h>
#include <stdlib.h>
#include "str_lib.h"

int main() {
   
   char s[32], t[32];

   printf ("Inserisci la prima stringa: ");
   fgets (s, 32, stdin);

   printf ("Inserisci la seconda stringa: ");
   fgets (t, 32, stdin);

   printf ("strcompare ha restituito %d\n", strcompare (s, t));

   return 0;
}