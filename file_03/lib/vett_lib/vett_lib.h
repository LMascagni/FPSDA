/**
 * @brief Legge un vettore di interi da input.
 * 
 * @param v Array di interi in cui memorizzare i valori letti.
 * @param dim_max Dimensione massima dell'array.
 * @return Il numero di elementi effettivamente letti.
 */
int leggi_vettore (int v[], int dim_max);

/**
 * @brief Stampa un vettore di interi.
 * 
 * @param v Array di interi da stampare.
 * @param dim Dimensione dell'array.
 */
void stampa_vettore (int v[], int dim);

/**
 * @brief Inverte l'ordine degli elementi di un vettore di interi.
 * 
 * @param v Array di interi da invertire.
 * @param dim Dimensione dell'array.
 */
void inverti_vettore (int v[], int dim);

/**
 * @brief Legge una sequenza di valori da input e aggiorna i contatori.
 * 
 * @param contatori Array di contatori da aggiornare.
 * @param val_min Valore minimo della sequenza.
 * @param val_max Valore massimo della sequenza.
 */
void leggi_sequenza_e_aggiorna_i_contatori (int contatori[], int val_min, int val_max);

/**
 * @brief Legge un testo da input e aggiorna i contatori.
 * 
 * @param contatori Array di contatori da aggiornare.
 * @param val_min Valore minimo del testo.
 * @param val_max Valore massimo del testo.
 */
void leggi_testo_e_aggiorna_i_contatori (int contatori[], int val_min, int val_max);

/**
 * @brief Inizializza un vettore di interi con un valore specificato.
 * 
 * @param v Array di interi da inizializzare.
 * @param dim Dimensione dell'array.
 * @param valore_iniziale Valore con cui inizializzare ogni elemento dell'array.
 */
void inizializza_vettore (int v[], int dim, int valore_iniziale);

/**
 * @brief Stampa un istogramma orizzontale basato sui valori di un vettore.
 * 
 * @param v Array di interi da utilizzare per l'istogramma.
 * @param dim Dimensione dell'array.
 */
void stampa_istogramma_orizzontale (int v[], int dim);

/**
 * @brief Stampa un istogramma verticale basato sui valori di un vettore.
 * 
 * @param v Array di interi da utilizzare per l'istogramma.
 * @param dim Dimensione dell'array.
 * @param x_axes_min Valore minimo dell'asse x.
 * @param x_axes_max Valore massimo dell'asse x.
 */
void stampa_istogramma_verticale (int v[], int dim, int x_axes_min, int x_axes_max);

/**
 * @brief Stampa un istogramma verticale basato sui valori di un vettore.
 * 
 * @param v Array di interi da utilizzare per l'istogramma.
 * @param dim Dimensione dell'array.
 * @param quota_massimo_isto_testo Quota massima dell'istogramma in formato testo.
 */
void stampa_istogramma_verticale_testo (int v[], int dim, int quota_massimo_isto_testo);

/**
 * @brief Disegna una linea di una lunghezza specificata.
 * 
 * @param lunghezza Lunghezza della linea da disegnare.
 */
void disegna_linea (int lunghezza);

/**
 * @brief Calcola il fattore di scala per un istogramma.
 * 
 * @param max_value Valore massimo nel vettore.
 * @param max_height Altezza massima dell'istogramma.
 * @return Il fattore di scala calcolato.
 */
double calcola_fattore_di_scala(int max_value, int max_height);

/**
 * @brief Trova il valore massimo in un vettore di interi.
 * 
 * @param v Array di interi.
 * @param dim Dimensione dell'array.
 * @return Il valore massimo trovato nell'array.
 */
int massimo_in_sottovettore(int v[], int inizio, int fine);

/**
 * @brief Cerca un valore specificato in un sottovettore.
 * 
 * @param v Array di interi.
 * @param inizio Indice di inizio del sottovettore.
 * @param fine Indice di fine del sottovettore.
 * @param valore_cercato Valore da cercare nel sottovettore.
 * @return L'indice del valore trovato, o -1 se non trovato.
 */
int cerca_in_sottovettore(int v[], int inizio, int fine, int valore_cercato);

/**
 * @brief Esegue uno scorrimento circolare degli elementi di un vettore.
 * 
 * @param v Array di interi da scorrere.
 * @param dim Dimensione dell'array.
 */
void scorrimento_circolare(int v[], int dim);
