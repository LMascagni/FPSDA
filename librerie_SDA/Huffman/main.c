#include <stdio.h>
#include "huffman.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define N 50

void stampa_codice(void *dato) {
  char* s = (char*)dato;
  printf("%s", s);
}

int main() {
  char testo[64] = "sara' sempre di domenica domani";
  char testo_codificato[128] = "";
  char testo_decodificato[64] = "";
  albero_huffman codice = crea_albero_huffman(testo);
  stampa_tabella_hash(codice.tabella_codifica, stampa_codice);
  /* stampa_albero_huffman(codice); */
  codifica_testo(codice, testo, testo_codificato);
  printf("%s\n", testo_codificato);
  decodifica_testo(codice, testo_codificato, testo_decodificato);
  assert(strcmp(testo, testo_decodificato) == 0);
  
  elimina_albero_huffman(&codice);
    
  return 0;
}

