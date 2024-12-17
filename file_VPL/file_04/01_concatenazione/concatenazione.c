#include <stdio.h>
#include <stdlib.h>
#include "str_lib.h"

int main ()
{
   
   char s[32], t[32];

   printf ("prima stringa: ");
   fgets (s, 32, stdin);

   printf ("seconda stringa: ");
   fgets (t, 32, stdin);

   strcatenate (s, t);

   puts (s);

   return 0;
}