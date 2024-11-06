#include <stdio.h>
#include <stdlib.h>

void stampa_array(int v[], int size);

int main()
{
    int n;
    //lettura del numero di valori
    printf("inserisci il numero di valori da scrivere nel vettore: ");
    scanf("%d", &n);

    int v[n];
    int n_values[21] = {0};

    //lettura dei valori
    int i, j;
    for (i = 0; i < (sizeof(v)/sizeof(v[0])); i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    //controllo dei valori e conteggio dei valori in v_values[]
    for ( i = 0; i < (sizeof(v)/sizeof(v[0])); i++)
    {
        if(v[i] < 0 || v[i] > 20)
        {
            printf("e` stato scartato il voto non valido %d\n", v[i]);
        }
        else
        {
            n_values[v[i]]++;
        }
    }
    
#ifdef DEBUG
    stampa_array(n_values, 21);
#endif
    
//stampa del grafico
    //ricerca del valore massimo di n_values
    int max;
    max = 0;
    for(i = 0; i < 21 ; i++)
    {
        if (max < n_values[i])
        {
            max = n_values[i];
        }
    }

#ifdef DEBUG
    printf("max = %d\n", max);
#endif

    //stampa degli istogrammi
    for (i = 0; i < max; i++)
    {
        for(j = 0; j < 21; j++ )
        {
            //printf("%d%d ", i, j);
            if (n_values[j] > (max - (i + 1)))
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    //stampa numeri fine del grafico
    for (i = 0; i < 21; i++)
    {
        printf("%2d ", i);
    }

    return EXIT_SUCCESS;
}


//void stampa_array(int v[], int size);

void stampa_array(int v[], int size)
{
    printf("\n");
    for (int i = 0; i < size * 5 + 1; i++)
    {
        printf("-");
    }
    printf("\n");
    
    for (int i = 0; i < size; i++)
    {
        printf("| %2d ", v[i]);
    }
    printf("|\n");
    
    for (int i = 0; i < size * 5 + 1; i++)
    {
        printf("-");
    }
    printf("\n");
}


