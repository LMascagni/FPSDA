#include "array.h"
#include <assert.h>

/* si scriva la sola funzione di inserimento secondo le seguenti specifiche: 

Dato un vettore dinamico, l'indice di un elemento e un valore, 
la funzione deve estendere il vettore di un elemento e inserire 
il valore specificato all'indice i del vettore.

Ad esempio, se il vettore contiene i seguenti elementi:

{ 1.0, 3.0, 4.1, 2.3, 5.2 } 
i = 2, val = 7.9
il vettore risultante dall'operazione dev'essere

{ 1.0, 3.0, 7.9, 4.1, 2.3, 5.2 }
Qualora l'indice i risulti essere fuori dal vettore (esteso) 
la funzione deve terminare la sua esecuzione e il programma 
attraverso un assert.

Ad esempio: 

{ 1.0, 3.0, 4.1, 2.3, 5.2 } 
i = 9, val = 7.9
deve terminare il programma a seguito di un assert.

Invece:

{ 1.0, 3.0, 4.1, 2.3, 5.2 } 
i = 5, val = 7.9
è da ritenersi corretto e il risultato dev'essere
{ 1.0, 3.0, 4.1, 2.3, 5.2, 7.9 } 

*/

void inserisci_in_posizione(vettore_dinamico* v, int i, float val) {

    //ridimensiona l'array con la nuova dimensione (vecchia dimensione + 1)
    ridimensiona_vettore_dinamico(v, v->dimensione + 1);

    //sposta tutti gli elementi dalla posizione i in poi a destra
    for(int j = v->dimensione; j > i; j--)
    {
        v->dati[j] = v->dati[j - 1];
    }

    //inserisci il valore val nella posizione i
    v->dati[i] = val;

    return;
}