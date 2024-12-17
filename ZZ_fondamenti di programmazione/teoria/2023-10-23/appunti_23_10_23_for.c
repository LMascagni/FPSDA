/*
scrivere un'espressione vera se a,b,c,d sono crescenti:
d-(c-(b-a))>0
d-c+b-a>0
a<b && b<c && c<d

se la variabile char ch è una vocale allora l'espressione è vera:
(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
}
*/
/*strutture di controllo del C
FOR:
è un while, ma prevede la presenza un blocco di istruzioni di inizializzazione e uno di aggiornamento delle varibili su cui lavora la condizione.
prima di entrare nel ciclo si inizializzano le variabili e poi si modificano nel ciclo:
(permette di compattare il ciclo while. vantaggio: vedo su una riga tutta la struttura di controllo)

for(istruzione1_inizializzazione; espressione2_condizione; istruzione2_aggiornamento)
{
   blocco di istruzioni;
}
*/
//esempio for

#include <stdio.h>
#include <stdlib.h>

int main ()
{
   //stampare i primi 10 numeri (0-9):
   int i, j;
   #if 0
   printf ("While:\n")
   while(i < 10)
   {
      printf ("%d\n", i);
      i++;
   }
   #endif //disabilito un blocco di codice compreso tra #if e #endif. se metto 0 dopo #if si disabilita, se metto un altro valore, no

   for (i = 0; i < 10; i++)
   {
      printf ("%d\n", i);
   }
   //fermo il ciclo finchè i due numeri i e j sono invertono relazione d'ordine:
   for (i = 0, j = 47; i < j; i++, j--)
   {
      printf ("i= %d, j= %d\n", i, j);
   }
   return EXIT_SUCCESS;
}