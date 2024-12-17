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
   int i, j, k;
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
#endif
   // Aggiorna l'array in base al file rifornimento

   // Scrivere le informazioni dell'array sul terzo file

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