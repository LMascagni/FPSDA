// prototipi della libreria datelib.c
int chkdate (int giorno, int mese, int anno);
int numero_giorni_del_mese (int mese, int anno);
int bisestile (int anno);
void leggi_data( int *puntatore_giorno, int *puntatore_mese, int *puntatore_anno);
void stampa_data( int giorno, int mese, int anno);
int differenza_tra_date( int g1, int m1, int a1, int g2, int m2, int a2);
int confronto_date( int g1, int m1, int a1, int g2, int m2, int a2);
void scambia_date (int *p_g1, int *p_m1, int *p_a1, int *p_g2, int *p_m2, int *p_a2);
int giorno_successivo (int *p_g, int *p_m, int *p_a);