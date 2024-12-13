#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 32

struct articolo
{
   char nome[MAX_LEN];
   int q;
};


int leggi_magazzino(FILE *fp, struct articolo articoli[], int max_dim);
struct articolo estrai_dati_articolo(char buf[MAX_LEN]);
void stampa_magazzino (struct articolo articoli[100], int n_articoli);


int main()
{
   struct articolo articoli[100];
   int n_articoli;
   n_articoli  = 0;

   FILE *fp;
   fp = fopen("in.txt", "r");
   if (fp == NULL)
   {
      printf("F in chat\n");
      exit(EXIT_FAILURE);
   }

   n_articoli = leggi_magazzino(fp, articoli, 100);

   stampa_magazzino(articoli, n_articoli);

   return EXIT_SUCCESS;
}

int leggi_magazzino(FILE *fp, struct articolo articoli[], int max_dim)
{
   int i;

   char buf[100];

   //controlla che ci siano nuove righe
   while(fgets(buf, 100, fp) != NULL && i < max_dim)
   {
      articoli[i] = estrai_dati_articolo(buf);
      i++;
   }
      //leggi i dati

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

void stampa_magazzino (struct articolo articoli[100], int n_articoli)
{
   int i;

   for (i = 0; i < n_articoli; i++)
   {
      printf("%s: %d\n", articoli[i].nome, articoli[i].q);
   }

   return;   
}