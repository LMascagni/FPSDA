#ifndef _GRAFI_H
#define _GRAFI_H

#include <stdbool.h>

typedef struct _nodo_adiacenza {
    int vertice;
    float peso;
    struct _nodo_adiacenza* succ;
} nodo_adiacenza;

typedef struct {
    int n;
    nodo_adiacenza **adiacenti;
    bool diretto;
} grafo;

#define PEROGNI_VICINO(g, u, e, v) \
for (e = g.adiacenti[u], v = (e != NULL ? e->vertice : -1); e != NULL; e = e->succ, v = (e != NULL ? e->vertice : -1))


grafo crea_grafo(int n, bool diretto);
void aggiungi_arco(grafo* g, int u, int v, float peso);
void elimina_arco(grafo* g, int u, int v);
void elimina_grafo(grafo* g);

typedef struct {
    float distanza;
    int pred;
} cammini;

cammini* visita_in_ampiezza(grafo g, int s);
void stampa_cammino(grafo g, cammini* cammini, int s, int d);

void applica_in_ampiezza(grafo g, int s, void f(grafo, int)); /* la funzione prende come parametro una funzione da applicare a ciascun nodo*/
void applica_in_profondita(grafo g, int s, void f(grafo, int));

int* ordinamento_topologico(grafo g);

cammini* dijkstra(grafo g, int s);
cammini* bellman_ford(grafo g, int s);

#endif
