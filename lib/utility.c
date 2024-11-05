
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"


void swap (int *ptr_a, int *ptr_b)
{
   int t;

   t = *ptr_a;
   *ptr_a = *ptr_b;
   *ptr_b = t;

   return;
}

