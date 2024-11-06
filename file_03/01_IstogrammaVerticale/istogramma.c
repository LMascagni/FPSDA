#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Inserire n: ");
    scanf("%d", &n);

    int v[n];

    int i;
    for (i = 0; i < (sizeof(v)/sizeof(v[0])); i++)
    {
        printf("%d", i);
    }


    return EXIT_SUCCESS;
}