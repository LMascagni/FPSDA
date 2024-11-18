#include <stdio.h>
#include <stdlib.h>
#include "str_lib.h"

int main()
{
   char s[100], t[100];

   printf ("Inserisci una stringa: ");
   gets (s);

   printf ("Inserisci un'altra stringa: ");
   gets (t);

   strcopy (t, s);

   printf ("La stringa originale e`: ");
   puts (s);

   printf ("La stringa copiata e`: ");
   puts (t);

   return 0;
}