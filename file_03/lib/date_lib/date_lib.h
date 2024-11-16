
void leggi_data (int *ptr_g, int *ptr_m, int *ptr_a);
int checkdate (int g, int m, int a);
int giorni_del_mese (int mese, int anno);
int bisestile (int anno);
void scambia_date (int *p_g1, int *p_m1, int *p_a1, 
                   int *p_g2, int *p_m2, int *p_a2);
int differenza_tra_date (int g1, int m1, int a1, int g2, int m2, int a2);
int confronta_date (int g1, int m1, int a1, int g2, int m2, int a2);
void giorno_successivo (int *p_g1, int *p_m1, int *p_a1);
void giorno_precedente (int *p_g1, int *p_m1, int *p_a1);
void somma_n_a_data (int *p_g, int *p_m, int *p_a, int n);
