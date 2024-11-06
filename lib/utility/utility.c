
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

int leggiNumeroConControllo(int min, int max)
{
    int dato;
    do
    {
        printf ("numero: ");
        scanf ("%d", &dato);
        if(dato < min || dato > max)
        {
            printf("!!numero non valido!! \nReinserire il numero\n");
        }
    }while(dato < min || dato > max);
    return dato;
}