#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTI 100
#define MAX_VOTI 50

#define MAX_LEN 32

struct date
{
    int anno;
    int mese;
    int giorno;
};

struct valutazione
{
    int voto;
    struct date data;
};

struct studente
{
    char nome[MAX_LEN];
    char cognome[MAX_LEN];

    struct valutazione valutazioni[MAX_VOTI];
    int nVoti;
};

void parseData(FILE *fp_in, struct studente studenti[MAX_STUDENTI]);
void leggiStringaDaFile(FILE *fp_in, char str[MAX_LEN]);
int cercaStudente(struct studente studenti[MAX_STUDENTI], int n_studenti, char cognome[MAX_LEN], char nome[MAX_LEN]);

int main()
{
    // dichiarazione degli studenti
    struct studente studenti[MAX_STUDENTI];
    int n_studenti;

    n_studenti = 0;

    // apertura dei file
    FILE *fp_in;
    // FILE *fp_out;

    fp_in = fopen("in.txt", "r");
    // fp_out = fopen("out.txt", "w");

    // leggi file e "smista"
    parseData(fp_in, studenti);

    // scrivi il nuovo file con le informazioni degli studenti
    // updateOutput ();

    return EXIT_SUCCESS;
}

void parseData(FILE *fp_in, struct studente studenti[MAX_STUDENTI])
{
    int n_studenti = 0;
    int matricola;
    char nome[MAX_LEN];
    char cognome[MAX_LEN];
    char strData[MAX_LEN];

    matricola = 0;

    // esempio di riga da leggere
    // Della Valle Di Sotto, Luigi, 7/12/2020, 5.

    // while(il file non è finito)
    while (!feof(fp_in))
    {
        // leggi il cognome (stringa)
        leggiStringaDaFile(fp_in, cognome);

        // leggi il nome (stringa)
        leggiStringaDaFile(fp_in, nome);

        // ottieni la matricola
        matricola = cercaStudente(studenti, n_studenti, cognome, nome);

        // salva nome e cognome se la matricola è nuova
        if (matricola > n_studenti)
        {
            strcpy(studenti[matricola-1].cognome, cognome);
            strcpy(studenti[matricola-1].nome, nome);
            n_studenti++;
        }

        // leggi la data (stringa da convertire)
        leggiStringaDaFile(fp_in, strData);
        // converti la data da stringa a numeri
        //

        // leggi la valutazione
        fscanf(fp_in, "%d", &studenti[matricola-1].valutazioni[0].voto); //!!!!!!!!!!!!!!!
        printf("%d\n", n_studenti);

        fgetc(fp_in);
        fgetc(fp_in);
        fgetc(fp_in);
    }
    
    printf("\nsium\n");

    for (matricola = 0; matricola < n_studenti; matricola++)
    {
        printf("---------------\nDATI LETTI\n");
        printf("n: %d\n", matricola);
        printf("cognome: %s\n", studenti[matricola].cognome);
        printf("nome: %s\n", studenti[matricola].nome);
        printf("data: %s\n", strData);
        printf("voto: %d\n", studenti[matricola].valutazioni[0].voto);
    }

    return;
}

void leggiStringaDaFile(FILE *fp_in, char str[MAX_LEN])
{
    // finchè non leggo una virgola metto i caratteri nella stringa

    int i;
    char ch;

    i = 0;

    if ((ch = fgetc(fp_in)) == ' ')
    {
        while ((ch = fgetc(fp_in)) == ' ')
            ;
    }

    while (ch != ',')
    {
        str[i] = ch;

        ch = fgetc(fp_in);

        i++;
    }
    str[i] = '\0';

    // printf("%s", str);
}

int cercaStudente(struct studente studenti[MAX_STUDENTI], int n_studenti, char cognome[MAX_LEN], char nome[MAX_LEN])
{
    int matricola;
    matricola = 0;

    while (matricola <= n_studenti)
    {
        if ((strcmp(cognome, studenti[matricola].cognome) == 0) && (strcmp(nome, studenti[matricola].nome) == 0))
        {
            printf("studente trovato!!");
            return matricola;
        }

        matricola++;
    }

    printf("studente nuovo!!");
    return matricola;
}