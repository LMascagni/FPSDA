/*lettura_numero_esadecimale.c*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int val;
    char chr;

    int VAL_ERRATO;
    VAL_ERRATO = 0;

    val = 0;

    printf("inserire un numero esadecimale: ");
    
    while((chr = getchar()) != '\n')
    {
        int digit;
        if(chr >= '0' && chr <= '9')
        {
            digit = chr - '0';
        }
        else if(chr >= 'A' && chr <= 'F')
        {
            digit = chr - 'A' + 10;
        }
        else if(chr >= 'a' && chr <= 'f')
        {
            digit = chr - 'a' + 10;
        }
        else
        {
            //carattere incorretto
            VAL_ERRATO = 1;
        }

        val = val * 16 + digit;
    }
    
    if (VAL_ERRATO == 0)
    {
        printf("il valore decimale è: %d\n", val);
    }
    else
    {
        printf("il valore esadecomale è errato");
        main();
    }

    return EXIT_SUCCESS;
}