#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 32
#define MAX_ART 100

struct articolo
{
   char nome[MAX_LEN];
   int q;
};


int leggi_magazzino(FILE *fp, struct articolo articoli[MAX_ART], int max_dim);
struct articolo estrai_dati_articolo(char buf[MAX_LEN]);
void stampa_magazzino (struct articolo articoli[MAX_ART], int n_articoli);
void stampa_componenti_mancanti(FILE *fp, struct articolo articoli[MAX_ART], int dim_max);
int cerca_articolo(struct articolo articoli[MAX_ART], int dim_max, char nome[MAX_LEN]);


int main()
{
   struct articolo articoli[MAX_ART];
   int n_articoli;
   n_articoli  = 0;

   FILE *fp_magazzino;
   FILE *fp_progetto;

   char fileMagazzino[MAX_LEN];
   char fileProgetto[MAX_LEN];


   printf("nome del file magazzino: ");
   scanf("%s", fileMagazzino);

   fp_magazzino = fopen(fileMagazzino, "r");
   if (fp_magazzino == NULL)
   {
      printf("errore nell'apertura del file.\n");
      exit(EXIT_FAILURE);
   }

   printf("nome del file progetto: ");
   scanf("%s", fileProgetto);

   fp_progetto = fopen(fileProgetto, "r");
   if (fp_progetto == NULL)
   {
      printf("errore nell'apertura del file.\n");
      exit(EXIT_FAILURE);
   }

   n_articoli = leggi_magazzino(fp_magazzino, articoli, MAX_ART);

   stampa_componenti_mancanti(fp_progetto, articoli, n_articoli);

   // stampa_magazzino(articoli, n_articoli);

   fclose(fp_magazzino);
   fclose(fp_progetto);

   return EXIT_SUCCESS;
}

int leggi_magazzino(FILE *fp, struct articolo articoli[MAX_ART], int max_dim)
{
   int i;

   char buf[100];

   //controlla che ci siano nuove righe
   while(fgets(buf, 100, fp) != NULL && i < max_dim)
      //leggi i dati
      articoli[i++] = estrai_dati_articolo(buf);

   return i;
}

struct articolo estrai_dati_articolo(char buf[MAX_LEN])
{
   int i, j;
   char num[MAX_LEN];
   i = 0;
   j = 0;

   struct articolo articolo;

   //leggi il nome fino alla prima lettera del nome
   while(buf[i++] != '"');
   
   while(buf[i] != '"')
      articolo.nome[j++] = buf[i++];

   articolo.nome[j] = '\0';

   while(!isdigit(buf[i]))
      i++;

   j = 0;

   while(isdigit(buf[i]))
      num[j++] = buf[i++];

   num[j] = '\0';

   articolo.q = atoi (num);

   return articolo;   
}

void stampa_magazzino (struct articolo articoli[MAX_ART], int n_articoli)
{
   int i;

   for (i = 0; i < n_articoli; i++)
   {
      printf("%s: %d\n", articoli[i].nome, articoli[i].q);
   }

   return;   
}


void stampa_componenti_mancanti(FILE *fp, struct articolo articoli[MAX_ART], int dim_max)
{
   char buf[100];
   struct articolo art;
   int index;

   //se ci sono righe leggi
   while(fgets(buf, 100, fp) != NULL)
   {
      art = estrai_dati_articolo(buf);
      
      index = cerca_articolo(articoli, dim_max, art.nome);

      if(index == -1)
      {
         printf("%s: %d\n", art.nome, art.q);
      }
      else if(articoli[index].q < art.q)
      {
         printf("%s: %d\n", art.nome, (art.q - articoli[index].q));
      }
   }

   return;
}

int cerca_articolo(struct articolo articoli[MAX_ART], int dim_max, char nome[MAX_LEN])
{
   int i;
   i = 0;

   while(i < dim_max)
   {
      if(strcmp(articoli[i].nome, nome) == 0)
      {
         return i;
      }
      i++;
   }
   
   return -1;
}