/* elevamento_a_potenza_con_errore.c
 Elevamento a potenza mediante
 moltiplicazioni successive */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int base, esponente, potenza;
    printf ("base: ");
    scanf ("%d", &base);
    printf ("esponente: ");
    scanf ("%d", &esponente);
    potenza = 1;
    while (esponente > 0)
    {
        printf("-----------------------------\n");
        printf("1_potenza: %d\n", potenza);
        printf("1_base: %d\n", base);
        printf("1_esponente: %d\n", esponente);
        potenza = potenza * base;
        esponente = esponente - 1;
        printf("2_potenza: %d\n", potenza);
        printf("2_base: %d\n", base);
        printf("2_esponente: %d\n", esponente);
    }
    printf ("il risultato e` %d\n", potenza);
    return EXIT_SUCCESS;
}