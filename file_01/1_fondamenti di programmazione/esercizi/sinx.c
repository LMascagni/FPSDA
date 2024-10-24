//sin(x)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double potenza (int esp, double x);
int fattoriale (int n);
double val_ass (double x);
//LA PRECISIONE FUNZIONA...?: BASTA NON METTERE VALORI TROPPO BASSI!
int main()
{
   int fatt, segno, esp;
   double x, precisione, sinx, pot;
   esp = 1;
   segno = 1;
   sinx = 0;

   printf("Inserire x: \n");
   scanf("%lf", &x);
   printf("Inserire la precisione con cui effettuare il calcolo: \n");
   scanf("%lf", &precisione);

   do
   {
      //calcolo esponente
      pot = potenza (esp, x);
      //calcolo fattoriale
      fatt = fattoriale (esp);
      
      sinx += (pot*segno)/fatt;

      esp += 2;
      segno *= (-1);
      pot = 1;

   } while (val_ass(sinx) > precisione);

   printf("sin(%lf) = %lf\n", x, sinx);

   return EXIT_SUCCESS;
}

//calcolo esponente
double potenza (int esp, double x)
{
   double pot = 1;
   for (int j = 0; j < esp; j++)
   {
      pot *= x;
   }
   return pot;
}

//calcolo fattoriale
int fattoriale (int n)
{
   int fatt = 1;
   for (int i = 1; i <= n; i++)
   {
      fatt *= i;
   }
   return fatt;
}

double val_ass (double x)
{
   if (x >= 0)
   {
      return x;
   }
   else
   {
      return -x;
   }

}