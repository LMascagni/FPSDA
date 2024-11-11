#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"

#define MAX_VAL 100

int main ()
{
    int v[MAX_VAL];

    int dim;

    dim = leggi_interi_vettore(v, MAX_VAL);

    printf("applico lo scorrimento...\n");

    scorrimento_circolare(v, dim);

    stampa_vettore(v, dim);

    return 0;
}