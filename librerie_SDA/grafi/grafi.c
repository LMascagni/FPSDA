#include "grafi.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "coda.h"
#include "pila.h"
#include "coda_priorita_int.h"

nodo_adiacenza* _trova_nodo_adiacente(nodo_adiacenza* t, int vertice) {
    nodo_adiacenza* c = t;
    if (t == NULL)
        return NULL;
    while (c != NULL) {
        if (c->vertice == vertice)
            return c;
        c = c->succ;
    }
    return NULL;
}

nodo_adiacenza* _alloca_nodo_adiacenza(int vertice, float peso) {
    nodo_adiacenza* e = (nodo_adiacenza*)malloc(sizeof(nodo_adiacenza));
    assert(e != NULL);
    e->vertice = vertice;
    e->peso = peso;
    e->succ = NULL;
    return e;
}

void _dealloca_nodo_adiacenza(nodo_adiacenza* e) {
    free(e);
}

nodo_adiacenza* _aggiungi_in_testa_adiacenza(nodo_adiacenza* t, nodo_adiacenza* e) {
    e->succ = t;
    return e;
}

nodo_adiacenza* _togli_nodo_adiacenza(nodo_adiacenza* t, nodo_adiacenza* e) {
    nodo_adiacenza* c = t;
    if (t == NULL)
        return NULL;
    if (t == e)
        return t->succ;
    while (c && c->succ != e)
        c = c->succ;
    if (c != NULL)
        c->succ = e->succ;
    return t;
}

void _elimina_lista_adiacenza(nodo_adiacenza* t) {
    nodo_adiacenza* c = t;
    while (c != NULL) {
        nodo_adiacenza* d = c;
        c = c->succ;
        free(d);
    }
}


grafo crea_grafo(int n, bool diretto) {
    int i;
    grafo g;
    g.n = n;
    g.adiacenti = (nodo_adiacenza**)malloc(n * sizeof(nodo_adiacenza*));
    for (i = 0; i < n; i++)
        g.adiacenti[i] = NULL;
    g.diretto = diretto;
    return g;
}

void aggiungi_arco(grafo* g, int u, int v, float peso) {
    if (_trova_nodo_adiacente(g->adiacenti[u], v) == NULL) { /* l'arco non esiste */
        g->adiacenti[u] = _aggiungi_in_testa_adiacenza(g->adiacenti[u], _alloca_nodo_adiacenza(v, peso));
        if (!g->diretto)
            g->adiacenti[v] = _aggiungi_in_testa_adiacenza(g->adiacenti[v], _alloca_nodo_adiacenza(u, peso));
    }
}

void elimina_arco(grafo* g, int u, int v) {
    nodo_adiacenza* e = _trova_nodo_adiacente(g->adiacenti[u], v);
    if (e != NULL) {
        g->adiacenti[u] = _togli_nodo_adiacenza(g->adiacenti[u], e);
        _dealloca_nodo_adiacenza(e);
        if (!g->diretto) {
            e = _trova_nodo_adiacente(g->adiacenti[v], u);
            assert(e != NULL);
            g->adiacenti[v] = _togli_nodo_adiacenza(g->adiacenti[v], e);
            _dealloca_nodo_adiacenza(e);
        }
    }
}

void elimina_grafo(grafo* g) {
    int i;
    for (i = 0; i < g->n; i++)
        if (g->adiacenti[i] != NULL)
            _elimina_lista_adiacenza(g->adiacenti[i]);
    free(g->adiacenti);
}

cammini* visita_in_ampiezza(grafo g, int s) {
    bool* raggiunto = (bool*)malloc(g.n * sizeof(bool));
    cammini* cammini = malloc(g.n * sizeof(cammini));
    int u, v;
    for (u = 0; u < g.n; u++) {
        raggiunto[u] = false;
        cammini[u].distanza = INFINITY;
        cammini[u].pred = -1;
    }
    coda q = crea_coda();
    enqueue(&q, s);
    cammini[s].pred = s;
    cammini[s].distanza = 0;
    while (!empty(q)) {
        nodo_adiacenza* e;
        u = first(q);
        dequeue(&q);
        if (!raggiunto[u]) {
            raggiunto[u] = true;
            PEROGNI_VICINO(g, u, e, v) {
                if (!raggiunto[v]) {
                    cammini[v].distanza = cammini[u].distanza + 1;
                    cammini[v].pred = u;
                    enqueue(&q, v);
                }
            }
        }
    }
    
    elimina_coda(&q);
    free(raggiunto);
    return cammini;
}

void stampa_cammino(grafo g, cammini* cammini, int s, int d) {
    int u = d;
    printf("distanza: %f, cammino: ", cammini[d].distanza);
    if (cammini[d].distanza >= INFINITY) {/* d è irragiungibile da s */
        printf("Nessuno\n");
        return;
    }
    printf("%d", d);
    while (u != s) {
        printf(" -> %d", cammini[u].pred);
        u = cammini[u].pred;
    }
    printf("\n");
}

void applica_in_ampiezza(grafo g, int s, void f(grafo, int))  {
    bool* raggiunto = (bool*)malloc(g.n * sizeof(bool));
    int u, v;
    coda q = crea_coda();
    for (u = 0; u < g.n; u++)
        raggiunto[u] = false;
    enqueue(&q, s);
    while (!empty(q)) {
        u = first(q);
        nodo_adiacenza* e;
        dequeue(&q);
        if (!raggiunto[u]) {
            raggiunto[u] = true;
            f(g, u);
            PEROGNI_VICINO(g, u, e, v) {
                if (!raggiunto[v])
                    enqueue(&q, v);
            }
        }
    }
    
    elimina_coda(&q);
    free(raggiunto);
}

void applica_in_profondita(grafo g, int s, void f(grafo, int)) {
    bool* raggiunto = (bool*)malloc(g.n * sizeof(bool));
    int u, v;
    pila p = crea_pila();
    nodo_adiacenza* e;
    for (u = 0; u < g.n; u++)
        raggiunto[u] = false;
    push(&p, s);
    while (!empty(p)) {
        u = top(p);
        pop(&p);
        if (!raggiunto[u]) {
            raggiunto[u] = true;
            f(g, u);
            PEROGNI_VICINO(g, u, e, v) {
                if (!raggiunto[v])
                    push(&p, v);
            }
        }
    }
}

void _visita_in_profondita_ricorsiva_ordina(grafo g, int u, bool raggiunto[], int eta[], int* p_contatore) {
    nodo_adiacenza* e;
    int v;
    raggiunto[u] = true;
    PEROGNI_VICINO(g, u, e, v) {
        if (!raggiunto[v])
            _visita_in_profondita_ricorsiva_ordina(g, v, raggiunto, eta, p_contatore);
    }
    eta[u] = *p_contatore;
    *p_contatore = *p_contatore - 1;
}

int* ordinamento_topologico(grafo g) {
    bool* raggiunto = (bool*)malloc(g.n * sizeof(bool));
    int* eta = (int*)malloc(g.n * sizeof(int));
    int s;
    int contatore = g.n - 1;
    
    for (s = 0; s < g.n; s++)
        raggiunto[s] = false;
    
    for (s = 0; s < g.n;  s++)
        if (!raggiunto[s])
            _visita_in_profondita_ricorsiva_ordina(g, s, raggiunto, eta, &contatore);
    
    free(raggiunto);
    return eta;
}

cammini* dijkstra(grafo g, int s) {
    int u, v;
    cammini* cammini = malloc(g.n * sizeof(cammini));
    coda_priorita_int q = crea_coda_priorita_int();
    for (u = 0; u < g.n; u++) {
        cammini[u].distanza = INFINITY;
        cammini[u].pred = -1;
    }
    cammini[s].pred = s;
    cammini[s].distanza = 0.0;
    for (u = 0; u < g.n; u++)
        enqueue_priorita_int(&q, u, -cammini[u].distanza); /* La coda è una max-heap */
    while (!empty_priorita_int(q)) {
        nodo_adiacenza* e;
        elemento_coda_priorita_int ep = first_priorita_int(q);
        dequeue_priorita_int(&q);
        u = ep.dato;
        PEROGNI_VICINO(g, u, e, v) {
            if (cammini[v].distanza > cammini[u].distanza + e->peso) {
                cammini[v].distanza = cammini[u].distanza + e->peso;
                cammini[v].pred = u;
                aggiorna_priorita_int(&q, v, -cammini[v].distanza);
            }
        }
    }
    return cammini;
}

cammini* bellman_ford(grafo g, int s) {
    int i, u, v;
    nodo_adiacenza* e;
    cammini* cammini = malloc(g.n * sizeof(cammini));
    for (u = 0; u < g.n; u++) {
        cammini[u].distanza = INFINITY;
        cammini[u].pred = -1;
    }
    cammini[s].pred = s;
    cammini[s].distanza = 0.0;
    for (i = 0; i < g.n; i++) {
        for (u = 0; u < g.n; u++)
            PEROGNI_VICINO(g, u, e, v) {
                if (cammini[v].distanza > cammini[u].distanza + e->peso) {
                    cammini[v].distanza = cammini[u].distanza + e->peso;
                    cammini[v].pred = u;
                }
            }
    }
    return cammini;
}

