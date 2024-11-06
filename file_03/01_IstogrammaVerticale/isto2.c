#include <stdio.h>
#include <stdlib.h>

void stampa_array(int v[]);

int main()
{
    int n;

    printf("Inserire n: ");
    scanf("%d", &n);

    int v[n];

    int i;
    for (i = 0; i < (sizeof(v)/sizeof(v[0])); i++)
    {
        printf("inserire il %d^ valore: ", i+1);
        scanf("%d", &v[i]);
    }

//controllo dei valori

//conteggio dei valori in v_values[]

//stampa dei risultati

 //stampa dei valori

    stampa_array(v[]);

    return EXIT_SUCCESS;
}

void stampa_array(int v[])
{
    int i;
    for ( i = 0; i <(sizeof(v)/sizeof(v[0]))*4+1 ; i++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < (sizeof(v)/sizeof(v[0])); i++)
    {
        printf("| %d ", v[i]);
    }
    printf("|\n");
    for ( i = 0; i <(sizeof(v)/sizeof(v[0]))*4+1 ; i++)
    {
        printf("-");
    }
    printf("\n");
    return;
}
