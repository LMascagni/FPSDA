#include "lista.h"
#include <assert.h>
#include <stdlib.h>

/*
    La funzione, dati due descrittori di lista l1 e l2 (cha assumiamo) ordinate di valori di tipo float deve restituire una nuova lista contenente l'intersezione degli elementi delle due liste (ovvero gli elementi che appaiono in entrambe).

    Si vuole utilizzare uno schema ricorsivo: la funzione dovrebbe comportarsi come funzione di interfaccia per una funzione ricorsiva. Ovvero, la funzione intersezione() dovrebbe preparare adeguatamente la lista risultato e chiamare una funzione ricorsiva che, a partire dai nodi di testa delle due liste riempia la lista nuova con delle copie dei nodi che appaiono in entrambe.
*/

void _itersezione_ricorsiva(lista *l, nodo_lista *s1, nodo_lista *s2)
{
   /* caso base: almeno una lista è arrivata alla fine, non possono esserci più valori comuni */
   if (s1 == NULL || s2 == NULL)
   {
      return;
   }
   else
   {
      // se il dato corrente è uguale sulle due liste
      if (s1->dato == s2->dato)
      {
         // aggiungilo alla nuova lista
         aggiungi_in_coda(l, s1->dato);
         // e chiama ricorsivamente la funzione sugli elementi rimanenti di s1 e s2 (s1->succ, s2->succ)
         _itersezione_ricorsiva(l, s1->succ, s2->succ);
      }
      else
      {
         // se il dato è diverso
         if (s1->dato < s2->dato)
         {
            // chiama ricorsivamente la funzione sugli elementi rimanenti di s1 ma lascia invariato s2 (perché è più grande)
            _itersezione_ricorsiva(l, s1->succ, s2);
         }
         else
         {
            // chiama ricorsivamente la funzione sugli elementi rimanenti di s2 ma lascia invariato s1 (perché è più grande)
            _itersezione_ricorsiva(l, s1, s2->succ);
         }
      }
   }
}

lista intersezione(lista l1, lista l2)
{
   lista l = crea_lista();
   _itersezione_ricorsiva(&l, l1.testa, l2.testa);
   return l;
}