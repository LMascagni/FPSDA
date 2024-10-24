#include <stdio.h>
#include <stdlib.h>

void linea(int l);
void quadrato(int l);
void triangolo(int l);

int main()
{
    char chr, arg;

    while ((chr = getchar()) != '\n')
    {
        arg = getchar() - '0';

        

        switch(chr)
        {
            //quadrato
            case 'Q':
            case 'q':
                quadrato(arg);
                break;
            //triangolo
            case 'T':
            case 't':
                triangolo(arg);
                break;
            //linea
            case 'L':
            case 'l':
                linea(arg);
                break;
        }
        printf("\n");
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