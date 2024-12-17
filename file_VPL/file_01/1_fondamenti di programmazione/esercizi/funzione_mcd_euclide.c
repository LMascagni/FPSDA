#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void inserimento_e_controllo_semplice (int *input);
int main()
{
   int m, n, mcd;

//USA I PUNTATORI: PROBLEMI NEL CONTROLLO_SU_INSERIMENTO (= INFUNZIONE_MCD_DECREMENTI)
//l'unico problema è passare con i puntatori i valori a controllo_su_inserimento
   printf("Inserire m > 0:\n");
   inserimento_e_controllo_semplice (&m); //passo l'indirizzo di m alla funzione che riceve un puntatore

   printf("Inserire n > 0:\n");
   inserimento_e_controllo_semplice (&n);

//calcolo MCD
   mcd = MCD(m, n);

//stampa risultato
   if( mcd == 1 )
   {
      printf("%d e %d sono primi tra loro.\n", m, n);
   }
   else
   {
      printf("MCD(%d, %d) = %d\n", m, n, mcd);
   }

   return EXIT_SUCCESS;
}

// printf("Inserire m > 0:\n");
//    scanf("%d", &m);
//    controllo_su_inserimento (&m);

// void inserimento_e_controllo_semplice (int *pa)
// {
//    int a;
//    while( !(*pa > range) )
//    {
//       printf("Valore non valido. Inserire un numero maggiore di 0:\n");
//       //così:
//       scanf("%d", &a);
//       *pa = a;
//       //oppure così:
//       scanf("%d", *pa);
//    }

//    return;
// }

// void inserimento_e_controllo_range (int *pa, int range)


void inserimento_e_controllo_semplice (int *input)
{
   // pa = &a; //il puntatore pa contiene l'indirizzo di a
   //*pa = a; //la cella puntata da pa viene valorizzata con a
   // &a : indirizzo di a
   // *p : contenuto della cella puntata
   
   do
   {
      scanf("%d", input); //input : è il puntatore in sè: contenitore

      if(*input <= 0) //*input: valore contenuto dal puntatore
      {
         printf("Valore non valido. Inserire un numero maggiore di 0:\n");
      }
      
      // //così:
      // scanf("%d", &input);
      // *p = input;
      // //oppure così:
      
   } while( *input <= 0 );

   return;
}