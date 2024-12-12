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

int parseData(FILE *fp_in, struct studente studenti[MAX_STUDENTI]);
void leggiStringaDaFile(FILE *fp_in, char str[MAX_LEN]);
int cercaStudente(struct studente studenti[MAX_STUDENTI], int n_studenti, char cognome[MAX_LEN], char nome[MAX_LEN]);
struct date convertiData(char str[MAX_LEN]);
void updateOutput (FILE *fp_out, struct studente studenti[MAX_STUDENTI], int n_studenti);

#ifdef DEBUG
void stampaDatiDebug(struct studente studenti[MAX_STUDENTI], int n_studenti);
#endif

int main()
{
   // dichiarazione degli studenti
   struct studente studenti[MAX_STUDENTI];
   int n_studenti;

   n_studenti = 0;

   // apertura dei file
   FILE *fp_in;
   FILE *fp_out;

   fp_in = fopen("in2.txt", "r");
   fp_out = fopen("out.txt", "w");

   if((fp_in == NULL) || (fp_out == NULL))
   {
      printf("errore nell'apertura dei file");
      exit(EXIT_FAILURE);
   }

   // leggi file e "smista"
   n_studenti = parseData(fp_in, studenti);

#ifdef DEBUG
   // per debug stampa i dati su terminale
   stampaDatiDebug(studenti, n_studenti);
#endif

   // scrivi il nuovo file con le informazioni degli studenti
   updateOutput (fp_out, studenti, n_studenti);

   //chiusura dei file
   fclose(fp_in);
   fclose(fp_out);

   return EXIT_SUCCESS;
}

int parseData(FILE *fp_in, struct studente studenti[MAX_STUDENTI])
{
   int n_studenti;
   int matricola;
   char ch;
   char nome[MAX_LEN];
   char cognome[MAX_LEN];
   char strData[MAX_LEN];

   n_studenti = 0;
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

      //printf("matricola Studente di %s %s: %d\n", cognome, nome, matricola);

      // salva nome e cognome se la matricola è nuova
      if (matricola >= n_studenti)
      {
         strcpy(studenti[matricola].cognome, cognome);
         strcpy(studenti[matricola].nome, nome);
         n_studenti++;
      }

      // leggi la data (stringa da convertire)
      leggiStringaDaFile(fp_in, strData);
      // converti la data da stringa a numeri
      studenti[matricola].valutazioni[studenti[matricola].nVoti].data = convertiData(strData);
      
      // leggi la valutazione
      fscanf(fp_in, "%d", &studenti[matricola].valutazioni[studenti[matricola].nVoti].voto);
      studenti[matricola].nVoti++;
      
      //printf("\nn_studenti = %d\n\n", n_studenti);

      while ((ch = fgetc(fp_in)) == '.');
      //fgetc(fp_in);
   }

   return n_studenti;
}

struct date convertiData(char str[MAX_LEN])
{
   struct date data;

   sscanf(str, "%d/%d/%d", &data.giorno, &data.mese, &data.anno);

   return data;
}

void leggiStringaDaFile(FILE *fp_in, char str[MAX_LEN])
{
      int i;
   char ch;

   i = 0;

   // salto gli spazi iniziali
   if ((ch = fgetc(fp_in)) == ' ')
   {
      while ((ch = fgetc(fp_in)) == ' ');
   }

   // finchè non leggo una virgola metto i caratteri nella stringa
   while (ch != ',')
   {
      str[i] = ch;

      ch = fgetc(fp_in);

      i++;
   }
   str[i] = '\0';
}

int cercaStudente(struct studente studenti[MAX_STUDENTI], int n_studenti, char cognome[MAX_LEN], char nome[MAX_LEN])
{
   int matricola;
   matricola = 0;

   while (matricola < n_studenti)
   {
      if ((strcmp(cognome, studenti[matricola].cognome) == 0) && (strcmp(nome, studenti[matricola].nome) == 0))
      {
         //studente trovato
         return matricola;
      }

      matricola++;
   }

   //nuovo studente
   return matricola;
}

#ifdef DEBUG
void stampaDatiDebug(struct studente studenti[MAX_STUDENTI], int n_studenti)
{
   printf("\nDATI STRUTTURA");
   for (int matricola = 0; matricola < n_studenti; matricola++)
   {
      printf("\n---------------\n");
      printf("matricola: %d\n", matricola);
      printf("cognome: %s\n", studenti[matricola].cognome);
      printf("nome: %s\n", studenti[matricola].nome);
      for (int i = 0; i < studenti[matricola].nVoti; i++)
      {
         printf("data: %d/%d/%d  \t|\t", studenti[matricola].valutazioni[i].data.giorno, 
                                        studenti[matricola].valutazioni[i].data.mese, 
                                        studenti[matricola].valutazioni[i].data.anno);
         printf("voto: %d\n", studenti[matricola].valutazioni[i].voto);
      }
   }
}
#endif

void updateOutput (FILE *fp_out, struct studente studenti[MAX_STUDENTI], int n_studenti)
{
   double media;
   for (int matricola = 0; matricola < n_studenti; matricola++)
   {
      media = 0;
      //stampa nome e cognome
      fprintf(fp_out, "%s %s\n", studenti[matricola].nome, studenti[matricola].cognome);
      //stampa data e voto (per ogni voto), calcola la media
      for (int i = 0; i < studenti[matricola].nVoti; i++)
      {
         fprintf(fp_out, "%d-%d-%d %d\n", studenti[matricola].valutazioni[i].data.anno, 
                                          studenti[matricola].valutazioni[i].data.mese, 
                                          studenti[matricola].valutazioni[i].data.giorno, 
                                          studenti[matricola].valutazioni[i].voto);
         media += studenti[matricola].valutazioni[i].voto;
      }
      //MEDIA: ...
      media = media / studenti[matricola].nVoti;
      fprintf(fp_out, "MEDIA: %.1lf\n\n", media);
   }
}