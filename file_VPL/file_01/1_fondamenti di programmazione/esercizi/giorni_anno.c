//numero d'ordine del giorno dell'anno
#include <stdio.h>
#include <stdlib.h>
#include "datelib.h"

int numero_da_inizio_anno(int giorno, int mese, int anno);

int main()
{
    int giorno, mese, anno;
    printf("Inserire la data (gg/mm/aa) di cui calolare il numero d'ordine:");
    scanf("%d %d %d", &giorno, &mese, &anno);

    if(chkdate( giorno, mese, anno) == 0) //falso
    {
        printf("ERRORE: data non valida.");
        return EXIT_FAILURE;
    }

    printf("Il numero d'ordine di %d/%d/%d è: %d\n", giorno, mese, anno, numero_da_inizio_anno(giorno, mese, anno));

    return EXIT_SUCCESS;
}


int numero_da_inizio_anno(int giorno, int mese, int anno)
{
    int numero_ordine, mese_corrente;
    numero_ordine = 0;
    mese_corrente = 1;
    //inrimento: 27/12/2004
    while( mese_corrente < mese ) //calcola il numero di giorni da 01/01 a 01/mese inserito
    {
        numero_ordine += numero_giorni_del_mese (mese_corrente, anno);
        mese_corrente++;
    }
    //partendo dalla data 01/01/anno sono arrivato alla data 01/mese inserito e videvo aggiungere il giorno inserito
    numero_ordine += giorno;
    return numero_ordine;
}