#include "huffman.h"
#include "../hash/tabella_hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Funzione di creazione di un nodo dell'albero */
nodo_albero_huffman* crea_nodo_huffman(char simbolo, bool interno, int frequenza) {
  nodo_albero_huffman* n = (nodo_albero_huffman*)malloc(sizeof(nodo_albero_huffman));
  n->simbolo = simbolo;
  n->interno = interno;
  n->frequenza = frequenza;
  n->sinistro = NULL;
  n->destro = NULL;
  return n;
}

/* Funzione di eliminazione di un nodo dell'albero */
void elimina_nodo_huffman(nodo_albero_huffman* n) {
  free(n);
}

/* Funzione di aggregazione di due nodi in un nuovo albero */
nodo_albero_huffman* aggrega_nodi_huffman(nodo_albero_huffman* t1, nodo_albero_huffman* t2) {
  nodo_albero_huffman* radice = crea_nodo_huffman(0, true, t1->frequenza + t2->frequenza);
  if (t1->frequenza <= t2->frequenza) {
    radice->sinistro = t1;
    radice->destro = t2;
  } else {
    radice->sinistro = t2;
    radice->destro = t1;
  }
  return radice;
}

/* Funzione di calcolo delle frequenze dei singoli caratteri */
tabella_hash calcola_frequenze(char* testo_sorgente) {
  tabella_hash frequenze = crea_tabella_hash(128); /* ci aspettiamo al più 128 caratteri */
  char s[2] = "" ;
  int i = 0;
  while (testo_sorgente[i] != '\0') {
    s[0] = testo_sorgente[i]; s[1] = '\0'; /* trasformiamo il carattere in una stringa per usare la tabella hash */
    nodo_tabella_hash* elemento = ricerca_tabella_hash(frequenze, s);
    if (elemento == NULL) { /* il carattere cercato non appariva nella tabella */
      int* f = (int*)malloc(sizeof(int));
      *f = 1;
      inserisci_tabella_hash(&frequenze, s, f);
    } else { /* il carattere cercato appariva già, ne aggiorniamo la frequenza */
      (*(int*)elemento->dato) += 1;
    }
    i++;
  }
  return frequenze;
}

/* Funzioni di utilità per la heap */
int _heap_padre(int i) {
  return (i - 1) / 2;
}

int _heap_sinistro(int i) {
  return 2 * i + 1;
}

int _heap_destro(int i) {
  return 2 * i + 2;
}

void _scambia_heap(nodo_albero_huffman** a, nodo_albero_huffman** b) {
  nodo_albero_huffman* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void inserisci_in_min_heap(nodo_albero_huffman** min_heap, nodo_albero_huffman* nodo, int *heap_size) {
  int i = *heap_size;
  min_heap[i] = nodo;
  (*heap_size)++;
  
  while (i > 0 && min_heap[i]->frequenza < min_heap[_heap_padre(i)]->frequenza) {
    _scambia_heap(&min_heap[i], &min_heap[_heap_padre(i)]);
    i = _heap_padre(i);
  }
}

int migliore_padre_figli_min_heap(nodo_albero_huffman** min_heap, int i, int heap_size) {
  int k = i;
  if (_heap_sinistro(i) < heap_size && min_heap[k]->frequenza > min_heap[_heap_sinistro(i)]->frequenza)
    k = _heap_sinistro(i);
  if (_heap_destro(i) < heap_size && min_heap[k]->frequenza > min_heap[_heap_destro(i)]->frequenza)
    k = _heap_destro(i);
  return k;
}

nodo_albero_huffman* rimuovi_da_heap(nodo_albero_huffman** min_heap, int *heap_size) {
  int i = 0, k;
  nodo_albero_huffman* r = min_heap[0];
  min_heap[0] = min_heap[*heap_size - 1];
  (*heap_size)--;
  k = migliore_padre_figli_min_heap(min_heap, i, *heap_size);
  while (i != k) {
    _scambia_heap(&min_heap[i], &min_heap[k]);
    i = k;
    k = migliore_padre_figli_min_heap(min_heap, i, *heap_size);
  } 
  return r;
}

void _stampa_albero_huffman(nodo_albero_huffman* radice, int indentazione) {
  int i = 0;
  if (radice == NULL)
    return;
  for (i = 0; i < indentazione; i++)
    printf(" ");
  printf("%p ", radice);
  if (!radice->interno)
    printf("[%c] ", radice->simbolo);
  printf("%d ", radice->frequenza);
  if (radice->sinistro)
    printf("sx(%p) ", radice->sinistro);
  if (radice->destro)
    printf("sx(%p) ", radice->destro);
  printf("\n");
  _stampa_albero_huffman(radice->sinistro, indentazione + 1);
  _stampa_albero_huffman(radice->destro, indentazione + 1);
}

void stampa_albero_huffman(albero_huffman codice) {
  _stampa_albero_huffman(codice.radice, 0);
}

void _costruisci_tabella_corrispondenze_r(nodo_albero_huffman* radice, tabella_hash* tabella_codifica, char* acc, int i) {
  if (radice == NULL)
    return;
  if (!radice->interno) {
    char s[2];
    char* tmp = (char*)malloc((i + 1) * sizeof(char));
    s[0] = radice->simbolo; s[1] = '\0';
    acc[i] = '\0';
    strcpy(tmp, acc);
    inserisci_tabella_hash(tabella_codifica, s, tmp);
    return;
  }
  acc[i] = '0';
  _costruisci_tabella_corrispondenze_r(radice->sinistro, tabella_codifica, acc, i + 1);
  acc[i] = '1';
  _costruisci_tabella_corrispondenze_r(radice->destro, tabella_codifica, acc, i + 1);
}

void costruisci_tabella_corrispondenze(nodo_albero_huffman* radice, tabella_hash* tabella_codifica) {
  char accumula[16] = "";
  _costruisci_tabella_corrispondenze_r(radice, tabella_codifica, accumula, 0);
}

albero_huffman crea_albero_huffman(char* testo_sorgente) {
  tabella_hash frequenze = calcola_frequenze(testo_sorgente);
  nodo_albero_huffman** min_heap = (nodo_albero_huffman**)malloc(frequenze.elementi * sizeof(nodo_albero_huffman*));
  albero_huffman codice;
  int min_heap_size = 0, i;
  
  for (i = 0; i < frequenze.d; i++) {
    nodo_tabella_hash* c = frequenze.tabella[i];
    while (c != NULL) {
      /* crea un nodo dell'huffman tree e aggiungilo al min_heap */
      nodo_albero_huffman* nodo = crea_nodo_huffman(c->chiave[0], false, (*(int*)c->dato));
      inserisci_in_min_heap(min_heap, nodo, &min_heap_size);
      c = c->succ;
    }
  }
  codice.tabella_codifica = crea_tabella_hash(frequenze.elementi);
  elimina_tabella_hash(&frequenze);
  while (min_heap_size > 1) {
    nodo_albero_huffman *t1, *t2, *r;
    t1 = rimuovi_da_heap(min_heap, &min_heap_size);
    t2 = rimuovi_da_heap(min_heap, &min_heap_size);
    r = aggrega_nodi_huffman(t1, t2);
    inserisci_in_min_heap(min_heap, r, &min_heap_size);
  }
  codice.radice = min_heap[0];
  
  free(min_heap);
  /* costruisci la tabella di corrispondenza carattere -> codice binario */
  costruisci_tabella_corrispondenze(codice.radice, &codice.tabella_codifica);
  
  return codice;
}


void codifica_testo(albero_huffman codice, char* testo_sorgente, char* testo_codificato) {
  int i = 0;
  testo_codificato[0] = '\0'; // inizializzazione testo_codificato
  while (testo_sorgente[i] != '\0') {
    char s[2];
    nodo_tabella_hash* nodo;
    s[0] = testo_sorgente[i]; s[1] = '\0';
    nodo = ricerca_tabella_hash(codice.tabella_codifica, s);
    assert(nodo != NULL);
    strcat(testo_codificato, (char*)nodo->dato); // sarebbe più efficiente reimplementare la concatenazione
    i++;
  }
}

void _decodifica_testo(nodo_albero_huffman* radice, char* testo_codificato, int* i, char* testo_decodificato) {
  if (radice == NULL)
    return;
  if (!radice->interno) {
    char s[2];
    s[0] = radice->simbolo; s[1] = '\0';
    strcat(testo_decodificato, s);
    return;
  }
  if (testo_codificato[*i] == '0') {
    (*i)++;
    _decodifica_testo(radice->sinistro, testo_codificato, i, testo_decodificato);
  } else { // testo_codificato[*i] == '1'
    (*i)++;
    _decodifica_testo(radice->destro, testo_codificato, i, testo_decodificato);
  }
}

void decodifica_testo(albero_huffman codice, char* testo_codificato, char* testo_decodificato) {
  int i = 0;
  testo_decodificato[0] = '\0';
  while (testo_codificato[i] != '\0')
    _decodifica_testo(codice.radice, testo_codificato, &i, testo_decodificato);
}

void _elimina_albero_huffman_r(nodo_albero_huffman* radice) {
  if (radice == NULL)
    return;
  /* elimina ricorsivamente i sottoalberi destro e sinistro */
  _elimina_albero_huffman_r(radice->destro);
  _elimina_albero_huffman_r(radice->sinistro);  
  free(radice); /* dealloca il nodo radice */
}

void elimina_albero_huffman(albero_huffman* codice) {
  elimina_tabella_hash(&codice->tabella_codifica);
  _elimina_albero_huffman_r(codice->radice);
}
