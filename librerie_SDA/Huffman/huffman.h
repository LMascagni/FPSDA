#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <stdbool.h>
#include "../hash/tabella_hash.h"

typedef struct _nodo_albero_huffman {
  char simbolo;
  bool interno;
  int frequenza;
  struct _nodo_albero_huffman* sinistro;
  struct _nodo_albero_huffman* destro;
} nodo_albero_huffman;

typedef struct {
  nodo_albero_huffman* radice;
  tabella_hash tabella_codifica;
} albero_huffman;

albero_huffman crea_albero_huffman(char* testo_sorgente);
void stampa_albero_huffman(albero_huffman codice);
void codifica_testo(albero_huffman codice, char* testo_sorgente, char* testo_codificato);
void decodifica_testo(albero_huffman codice, char* testo_codificato, char* testo_decodificato);
void elimina_albero_huffman(albero_huffman* codice);

#endif
