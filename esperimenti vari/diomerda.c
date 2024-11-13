#include <stdio.h>
#include <stdlib.h>

int main ()
{

    int n;
    scanf("%d", &n);

    int v[n];

    printf("numero di elementi: %ld\n", (sizeof(v)/sizeof(v[0])));

    
    return 1;
}
