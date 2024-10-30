/*
SWITCH:
l'espressione che controlla lo switch è INTERA, NON Dà RISULTATI NON INTERI. l'unico risultato è un INTERO SCALARE 
(un solo risultato intero, diverso dal quello VETTORIALE che dà più riusltati... è un vettore)

switch (espressione) //non è vero o falso, ma dà un NUMERO
{
   case val_int1: istruzione1;
                  break;
   case val_int2: istruzione2;
                  break;
...
   default:       istruzione_default;
                  break;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
   //contiamo i votanti favorevoli, astenuti e contrari:
   //inseriemento di ogni voto con invio
   int favorevoli, contrari, astenuti;
   char voto;
   favorevoli = 0;
   contrari = 0;
   astenuti = 0;
   while ((voto = getchar()) != 'X')
   {
      switch (voto)
      {
         /*ho vari case per cui devo eseguire la stessa istruzione, quindi scrivo così perchè finchè non incontra break non si ferma, 
         quindi eseguirà di certo le istruzioni precedenti al break.*/
         case 'Y':
         case 'y':
         case 's':
         case 'F':
         case 'f': favorevoli++;
                   break;
         case 'N':
         case 'n':
         case 'C':
         case 'c': contrari++;
                   break;
         case '-':
         case 'A':
         case 'a': astenuti++;
                   break;
         case '\n': break; /*il getchar legge il buffer della tastiera: legge il carattere aumenta il contatore, ricomincia il ciclo: legge INVIO (\n) che non 
         rientra in nessun case quindi va nel case default. soluzione banale e limitata: facendo case '\n': break; il programma legge il '\n' e non fa nulla (break;)*/
         default:  printf ("Voto non riconosciuto."); //posso anche non mettere il default se non mi serve fare qualcosa nel caso in cui non rientri nei casi dei case
                   break; //il default non ha bisogno del break perchè è l'ultima istruzione dello switch quindi ovviamente esce dalla funzione.
      }
   }
   printf ("favorevoli: %d, contrari: %d, astenuti: %d\n", favorevoli, contrari, astenuti);
   return EXIT_SUCCESS;
}