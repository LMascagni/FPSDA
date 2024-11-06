#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double mysqrt (double r);
int main()
{
    double r1, r2;

    double eps;
    eps = 25e-17;
    printf("%lf", eps); 

    r1 = sqrt (2.0);
    r2 = mysqrt (2.0);

#ifdef DEBUG
    printf ("DEBUG: diff = %.40lf\n", (r1-r2));
    printf ("DEBUG: eps  = %.40lf\n", eps);
#endif

    if ((r1 - r2) < eps && (r1 - r2) > -eps)
    {
        printf ("OK! Radice di due = %.40lf\n", r1);
    }
    else
    {
        printf ("Bo!? x = %.40f, y = %.40lf\n", r1, r2);
    }
    return EXIT_SUCCESS;
}

double mysqrt (double r)
{
    /* calcola la radice con il metodo di Newton */
    double n1, n2;
    n1 = r;
    n2 = 1;
#ifdef DEBUG
    int cnt;
    cnt = 0;
#endif


    while (n1 - n2 > 0)
    {
        n1 = (n1 + n2) / 2.0;
        n2 = r / (double)n1;
#ifdef DEBUG
        printf("DEBUG %d: n1=%.40lf, n2=%.40lf\n", cnt, n1, n2);
        cnt++;
#endif

    }
    return n1;
}
