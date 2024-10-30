#include <stdio.h>
#include <stdlib.h>

#define pi 3.141592
#define densH2O 1.028
#define g 9.81

double calcolo_spinta_sfera(double raggio);
double volume_sfera(double raggio);

int main()
{
#ifdef DEBUG
    printf("DEBUG ATTIVO\n");
#endif

    double raggio, spinta;

    printf("inserire il raggio della sfera: ");
    scanf("%lf", &raggio);

#ifdef DEBUG
    printf("DEBUG: ");
    printf("raggio: %lf", raggio);
#endif

    spinta = calcolo_spinta_sfera(raggio);

    printf("spinta = %lf", spinta);

    return EXIT_SUCCESS;
}

double calcolo_spinta_sfera(double raggio)
{
    double vol;
    vol = volume_sfera(raggio);

    return g*vol*densH2O;
}

double volume_sfera(double raggio)
{
    return pi*raggio*raggio*raggio*4.0/3.0;
}