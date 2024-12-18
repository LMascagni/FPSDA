#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 32

#define MAX_NF 30
#define MAX_NP 7
#define MAX_NZ 50

struct sezione
{
   char codice[MAX_LEN];
   int Ne;     // numero di confezioni attualmente esposte
   int Nmax;   // numero massimo di confezioni che possono essere esposte
   int Nmag;   // numero di confezioni in magazzino
};

struct dimensioni
{
   int nf;
   int np;
   int nz;
};

struct dimensioni parseData(FILE *fp, struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ]);
void aggiornaSupermercato(FILE *fp, struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim);
struct dimensioni cercaProdotto(struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim, char cod[MAX_LEN]);
void aggiornaProdotto(struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim, struct dimensioni pos, int n);
void aggiornaFileDisposizione(FILE *fp, struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim);

#ifdef DEBUG
void stampaSupermercato(struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim);
#endif

int main(int argc, char *argv[])
{
   // Controllo argomenti
   if (argc != 4)
   {
      printf("argomenti non validi!\n");
      exit(EXIT_FAILURE);
   }

   // Apertura dei file
   FILE *fp_sm;   // fp supermercato
   FILE *fp_r;    // fp rifornimento
   FILE *fp_sma;  // fp supermercato aggiornato

   fp_sm = fopen(argv[1], "r");
   fp_r = fopen(argv[2], "r");
   fp_sma = fopen(argv[3], "w");

   if ((fp_sm == NULL) || (fp_r == NULL) || (fp_sma == NULL))
   {
      printf("errore nell'apertura dei file!\n");
      exit(EXIT_FAILURE);
   }

   struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ];
   struct dimensioni dim;

   // Leggere il file del supermercato e salvare i dati nell'array
   dim = parseData(fp_sm, scaffali);

   // Stampa di debug per verificare la corretta lettura dei dati
#ifdef DEBUG
   stampaSupermercato(scaffali, dim);
#endif
   // Aggiorna l'array in base al file rifornimento
   aggiornaSupermercato(fp_r, scaffali, dim);

#ifdef DEBUG
   stampaSupermercato(scaffali, dim);
#endif

   // Scrivere le informazioni dell'array sul terzo file
   aggiornaFileDisposizione(fp_sma, scaffali, dim);

   fclose(fp_sm);
   fclose(fp_r);
   fclose(fp_sma);

   return EXIT_SUCCESS;
}

struct dimensioni parseData(FILE *fp, struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ])
{
   struct dimensioni dim;

   // Leggi la prima riga per le "dimensioni del supermercato"
   fscanf(fp, "%d %d %d", &dim.nf, &dim.np, &dim.nz);
#ifdef DEBUG
   printf("DATI LETTI\n");
   printf("Numero di file: %d\n", dim.nf);
   printf("Numero di pile: %d\n", dim.np);
   printf("Numero di zone: %d\n", dim.nz);
#endif

   int nf, np, nz, Ne, Nmax, Nmag;
   char cod[MAX_LEN];
   while (fscanf(fp, "%d %d %d %s %d %d %d", &nf, &np, &nz, cod, &Ne, &Nmax, &Nmag) != EOF)
   {
      strcpy(scaffali[nf][np][nz].codice, cod);
      scaffali[nf][np][nz].Ne = Ne;
      scaffali[nf][np][nz].Nmax = Nmax;
      scaffali[nf][np][nz].Nmag = Nmag;
#ifdef DEBUG
      printf("%d %d %d %s %d %d %d\n", nf, np, nz, scaffali[nf][np][nz].codice, scaffali[nf][np][nz].Ne, scaffali[nf][np][nz].Nmax, scaffali[nf][np][nz].Nmag);
#endif
   }

   return dim;
}

void aggiornaSupermercato(FILE *fp, struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim)
{
   int n;
   char cod[MAX_LEN];
   struct dimensioni posizione;

   while(fscanf(fp, "%s %d", cod, &n) != EOF)
   {
      posizione = cercaProdotto(scaffali, dim, cod);
      aggiornaProdotto(scaffali, dim, posizione, n);
   }

   return;
}

struct dimensioni cercaProdotto(struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim, char cod[MAX_LEN])
{
   struct dimensioni pos;
   for(pos.nf = 0; pos.nf < dim.nf; pos.nf++)
   {
      for(pos.np = 0; pos.np < dim.np; pos.np++)
      {
         for(pos.nz = 0; pos.nz < dim.nz; pos.nz++)
         {
            if(strcmp(cod, scaffali[pos.nf][pos.np][pos.nz].codice) == 0)
            {
               return pos;
            }
         }
      }
   }

   return pos;
}

void aggiornaProdotto(struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim, struct dimensioni pos, int n)
{
   scaffali[pos.nf][pos.np][pos.nz].Ne += n;

   if(scaffali[pos.nf][pos.np][pos.nz].Ne > scaffali[pos.nf][pos.np][pos.nz].Nmax)
   {
      scaffali[pos.nf][pos.np][pos.nz].Nmag += (scaffali[pos.nf][pos.np][pos.nz].Ne - scaffali[pos.nf][pos.np][pos.nz].Nmax);
      scaffali[pos.nf][pos.np][pos.nz].Ne = scaffali[pos.nf][pos.np][pos.nz].Nmax;
   }
   return;
}

void aggiornaFileDisposizione(FILE *fp, struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim)
{
   //stampa delle dimensioni del supermercato
   fprintf(fp, "%d %d %d\n", dim.nf, dim.np, dim.nz);

   int i, j, k;

   for (i = 0; i < dim.nf; i++)
   {
      for (j = 0; j < dim.np; j++)
      {
         for (k = 0; k < dim.nz; k++)
         {
            if(strcmp(scaffali[i][j][k].codice, "") != 0)
            {
               fprintf(fp, "%d %d %d %s %d %d %d\n", i, j, k, scaffali[i][j][k].codice, scaffali[i][j][k].Ne, scaffali[i][j][k].Nmax, scaffali[i][j][k].Nmag);
            }
         }
      }
   }

   return;
}

#ifdef DEBUG
void stampaSupermercato(struct sezione scaffali[MAX_NF][MAX_NP][MAX_NZ], struct dimensioni dim)
{
   int i, j, k;

   printf("\nSTAMPA DELLA STRUTTURA\n");

   for (i = 0; i < dim.nf; i++)
   {
      for (j = 0; j < dim.np; j++)
      {
         for (k = 0; k < dim.nz; k++)
         {
            if(strcmp(scaffali[i][j][k].codice, "") != 0)
            {
               printf("%d %d %d | %s  \t| %d %d %d\n", i, j, k, scaffali[i][j][k].codice, scaffali[i][j][k].Ne, scaffali[i][j][k].Nmax, scaffali[i][j][k].Nmag);
            }
            else
            {
               printf("%d %d %d | ------\n", i, j, k);
            }
         }
      }
   }
   return;
}
#endif