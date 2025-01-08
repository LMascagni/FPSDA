#include <stdio.h>
#include "grafi.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

#define N 40

void verifica_distanze(grafo g, cammini* cammini_1, cammini* cammini_2) {
    int i;
    for (i = 0; i < g.n; i++)
        if (cammini_1[i].distanza != cammini_2[i].distanza)
            printf("Errore nel calcolo: %d %g %g\n", i, cammini_1[i].distanza, cammini_2[i].distanza);
}

void stampa(grafo g, int u) {
    printf("%d ", u);
}

int main() {
    grafo g = crea_grafo(N, false);
    cammini *cammini, *cammini_bf;
    int i, u, v;
    
    for (u = 0; u < N; u++)
        for (v = u + 1; v < N; v++)
            aggiungi_arco(&g, u, v, 1.0);
    printf("Applica in ampiezza: ");
    applica_in_ampiezza(g, 0, stampa); /* Dovrebbe stampare tutti i valori da 0 a N - 1 */
    printf("\n");
    printf("Applica in profondita: ");
    applica_in_profondita(g, 0, stampa); /* Dovrebbe stampare tutti i valori da N - 1 a 0 */
    printf("\n");
    
    for (i = 0; i < N * (N - 1) / 3; i++) {
        u = rand() % N;
        v = rand() % N;
        if (u == v)
            v = (v + 1) % N;
        elimina_arco(&g, u, v);
    }
    printf("Cammini minimi: ----\n");
    cammini = visita_in_ampiezza(g, 0);
    for (i = 0; i < N; i++)
        stampa_cammino(g, cammini, 0, i);
    free(cammini);
    elimina_grafo(&g);
    
    srand(0);    
    g = crea_grafo(N, true);
    for (i = 0; i < N * (N - 1) / 3; i++) {
        u = rand() % N;
        v = rand() % N;
        if (u == v)
            v = (v + 1) % N;
        aggiungi_arco(&g, u, v, 5 + rand() % 10);
    }
    
    printf("Ordinamento topologico: ----\n");
    int* o = ordinamento_topologico(g);
    for (i = 0; i < N; i++)
        printf("ordine[%d] = %d\n", i, o[i]);
    free(o);
    
    printf("Dijkstra: ----\n");
    cammini = dijkstra(g, 0);
    for (i = 0; i < N; i++)
        stampa_cammino(g, cammini, 0, i);
    
    printf("Bellman-Ford: ----\n");
    cammini_bf = bellman_ford(g, 0);
    for (i = 0; i < N; i++)
        stampa_cammino(g, cammini_bf, 0, i);
    verifica_distanze(g, cammini, cammini_bf);
    free(cammini_bf);
    free(cammini);
    elimina_grafo(&g);
    
    return 0;
}

