#include <stdio.h>
#include <stdlib.h>

#define VERO 1
#define FALSO 0

void linea(int l);
void quadrato(int l);
void triangolo(int l);

int main()
{
#ifdef DEBUG
    printf("DEBUG ATTIVO\n");
#endif

    char chr, arg;
    int flagErrore;

    printf("Inserire i comandi nel formato CnCnCn... : ");

    while ((chr = getchar()) != '\n')
    {
        flagErrore = FALSO;

        arg = getchar() - '0';

#ifdef DEBUG
        printf("DEBUG: ");
        printf("chr: %c,arg: %d\n", chr, arg);
#endif

        if (arg < 0 || arg > 9)
        {
            printf("ERRORE: argomento errato!\n");
            printf("inserire un argomento tra 0 e 9\n");
            flagErrore = VERO;
        }
        

        printf("\n");

        switch(chr)
        {
            //quadrato
            case 'Q':
            case 'q':
                if (!flagErrore)
                {
                    quadrato(arg);
                }
                break;
            //triangolo
            case 'T':
            case 't':
                if (!flagErrore)
                {
                    triangolo(arg);
                }
                break;
            //linea
            case 'L':
            case 'l':
                if (!flagErrore)
                {
                    linea(arg);
                }
                break;
            default:
                printf("ERRORE: comando %c non esistente\n", chr);
        }
    }

    return EXIT_SUCCESS;
}

void linea(int l)
{
    int i;
    for(i = 0; i < l; i++)
    {
        printf("*");
    }
    printf("\n");
    return;
}

void quadrato(int l)
{
    int i;
    for(i = 0; i < l; i++)
    {
        linea(l);
    }
    return;
}

void triangolo(int l)
{
    int i;
    for(i = 0; i < l; i++)
    {
        linea(i+1);
    }
    return;
}