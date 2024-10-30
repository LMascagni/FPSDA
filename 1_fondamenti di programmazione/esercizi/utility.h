//costanti fisiche
#define G 9.81 //accelerazione di gravità
#define DH2O 1.028 //densità dell'H2O in kg/dm3


void swap (int *ptr_x, int *ptr_y);
double potenza (int esp, double x);
int fattoriale (int n);
double val_ass (double x);
double senox(double x, int fatt, double pot, int segno, int esp);
long double vsfera (double raggio);
long double vcubo (double lato);
long double area_tri (double b, double h);
long double vparall_ret_bas_tri (double b, double h, double h_para);
long double vsfera_pi_arr (double raggio, double digits);
double arrotondamento(double x, double digits);
double spinta_archimede(double raggio);
int MCD (int m, int n);

void inserimento_e_controllo_semplice (int *input, int n);
//DA TESTARE
void inserimento_e_controllo_range (int *input, int MINIMO, int MASSIMO);