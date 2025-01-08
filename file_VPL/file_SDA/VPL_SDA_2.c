#include <stdlib.h>
#include "lista.h"

/* 
La funzione, data una lista rappresentata dal puntatore alla sua testa 
(o, indifferentemente, a un nodo intermedio), deve restituire il puntatore 
al nodo che contiene il valore minimo tra tutti quelli compresi tra il nodo stesso 
e la coda della lista. 
Se il nodo passato alla funzione è NULL, la funzione deve restituire NULL. 
*/

nodo_lista* minimo_lista(nodo_lista* t) {
    if(t == NULL)
        return NULL;

    nodo_lista *min;

    min->dato = t->dato;
    min->succ = t;

    while(t->succ != NULL)
    {
        if(t->dato < min->dato)
        {
            min->dato = t->dato;
            min->succ = t;
        }
        t = t->succ;
    }

    return min;
    
}