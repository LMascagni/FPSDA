//controllo_dati_ingresso.c

#include <stdio.h>
#include <stdlib.h>

#define MASSIMO 50
#define MINIMO -50

int main()
{
    int contatore, n, dato;
    double media;

    printf ("quanti numeri? ");
    scanf ("%d", &n);

    contatore = 0;
    media = 0;

    while (contatore < n)
    {
        do
        {
            printf ("numero: ");
            scanf ("%d", &dato);
            if(dato < MINIMO || dato > MASSIMO)
            {
                printf("!!numero non valido!! \nReinserire il numero\n");
            }

        }while(dato < MINIMO || dato > MASSIMO);
        
        media = media + dato;
        contatore = contatore + 1;
    }

    media = media / n;

    printf ("la media e` %.2f\n", media);

    return EXIT_SUCCESS;
}