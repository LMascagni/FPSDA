//controllo_dati_ingresso.c

#include <stdio.h>
#include <stdlib.h>

#define MASSIMO 50
#define MINIMO -50

int leggiNumeroConControllo(int min, int max);

int main()
{
    int contatore, n;
    double media;

    printf ("quanti numeri? ");
    scanf ("%d", &n);

    contatore = 0;
    media = 0;

    while (contatore < n)
    {        
        media = media + leggiNumeroConControllo(MINIMO, MASSIMO);
        contatore = contatore + 1;
    }

    media = media / n;

    printf ("la media e` %.2f\n", media);

    return EXIT_SUCCESS;
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