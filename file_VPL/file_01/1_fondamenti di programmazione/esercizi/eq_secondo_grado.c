// equazione di secondo grado
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//forse devo includere la libreria math.h
int main()
{
  int a, b, c;
  double x1, x2, delta;
  printf("Inserire i coefficienti dell'equazione di secondo grado in x:\n");
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  delta = b*b - 4*a*c;
  if( delta == 0 )
  {
    x1 = (-b)/(2*a);
    x2 = x1;
    printf("L'equazione ha due soluzioni reali coincidenti:\n x1= %lf\n x2= %lf\n", x1, x2);
  }

  if( delta > 0 )
  {
    x1 = (-b + sqrt(delta))/(double)(2*a);
    x2 = (-b - sqrt(delta))/(double)(2*a);
    printf("L'equazione ha due soluzioni reali distinte:\n x1= %lf\n x2= %lf\n", x1, x2);
  }
  else //delta < 0
  { //verifica la funzione per la parte immaginaria
    x1 = (-b + sqrt(-delta))/(2*a);
    x2 = (-b - sqrt(-delta))/(2*a);
    printf("L'equazione ha due soluzioni complesse distinte:\n x1= %lf\n x2= %lf\n", x1, x2);
  }
  
return EXIT_SUCCESS;
}