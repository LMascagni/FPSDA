#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    long long int nfatt;  // Modificato il tipo di dato a "long long int"
    printf("inserisci n: ");
    scanf("%d", &n);
    i = 1;
    nfatt = 1;
    while (i <= n)
    {
        nfatt = nfatt * i;
        i++;
    }
    printf("n! = %lld\n", nfatt);  // Modificato il formato di stampa a "%lld"
    return EXIT_SUCCESS;
}
