#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BORGHI 15
#define MAX_CONCORRENTI 20
#define MAX_LEN 32


// Struttura per memorizzare le informazioni di un borgo
struct borgo
{
   char nome[MAX_LEN];             // Nome del borgo
   int numero_partecipanti;   // Numero di partecipanti del borgo
   char partecipanti[MAX_CONCORRENTI][MAX_LEN]; // Nomi dei partecipanti del borgo
   int punteggio;             // Punteggio complessivo del borgo
};

int parseData(FILE *fp, struct borgo borghi[MAX_BORGHI]);
void calcolaPunteggi(FILE *file_punteggi, struct borgo borghi[MAX_BORGHI], int num_borghi);
void stampaPunteggi(struct borgo borghi[MAX_BORGHI], int num_borghi);

int main(int argc, char *argv[])
{
   // Dichiarazione delle variabili
   struct borgo borghi[15]; // Array di borghi
   int num_borghi;          // Numero di borghi
   
   // Apertura dei file
   if(argc != 3)
   {
      printf("argomenti non validi\n");
      exit(EXIT_FAILURE);
   }

   FILE *file_partecipanti;
   FILE *file_punteggi;

   file_partecipanti = fopen(argv[1], "r"); // partecipanti.txt
   file_punteggi = fopen(argv[2], "r"); // punteggi.txt

   // Controllo se i file sono stati aperti correttamente
   if (file_partecipanti == NULL || file_punteggi == NULL)
   {
      printf("Errore nell'apertura dei file.\n");
      return EXIT_FAILURE;
   }

   // Lettura dei dati dai file
   // Parsing dei borghi
   num_borghi = parseData(file_partecipanti, borghi);
   
#ifdef DEBUG
   // Stampa di debug per verificare la corretta lettura dei dati
   int i, j;
   
   printf("num_borghi = %d\n", num_borghi);
   
   for (i = 0; i < num_borghi; i++)
   {
      printf("borgo %d: nome: %s\nnumero partecipanti: %d\n", i, borghi[i].nome, borghi[i].numero_partecipanti);
      for (j = 0; j < borghi[i].numero_partecipanti; j++)
      {
         printf("partecipante %d: %s\n", i, borghi[i].partecipanti[j]);
      }
      printf("punteggio: %d\n", borghi[i].punteggio);
   }
#endif

   // Calcolo dei punteggi totali per ciascun borgo
   calcolaPunteggi(file_punteggi, borghi, num_borghi);

   // Stampa dei punteggi totali per ciascun borgo
   stampaPunteggi(borghi, num_borghi);
   
   // Chiusura dei file
   fclose(file_partecipanti);
   fclose(file_punteggi);

   return EXIT_SUCCESS;
}

int parseData(FILE *file_partecipanti, struct borgo borghi[MAX_BORGHI])
{
   int num_borghi;
   int i, j;

   fscanf(file_partecipanti, "%d", &num_borghi);
   
   for (i = 0; i < num_borghi; i++)
   {
      fscanf(file_partecipanti, "%s", borghi[i].nome);
   }

   for (i = 0; i < num_borghi; i++)
   {
      fscanf(file_partecipanti, "%s", borghi[i].nome);
      fscanf(file_partecipanti, "%d", &borghi[i].numero_partecipanti);
      for (j = 0; j < borghi[i].numero_partecipanti; j++)
      {
         fscanf(file_partecipanti, "%s", borghi[i].partecipanti[j]);
      }
      borghi[i].punteggio = 0; // Inizializzazione del punteggio a 0
   }
   return num_borghi;
}

void calcolaPunteggi(FILE *file_punteggi, struct borgo borghi[MAX_BORGHI], int num_borghi)
{
   char partecipante[MAX_LEN];
   int punteggio;
   int i, j;

   while(fscanf(file_punteggi, "%s %d", partecipante, &punteggio) != EOF)
   {
      //printf("%s %d\n", partecipante, punteggio);

      for (i = 0; i < num_borghi; i++)
      {
         for (j = 0; j < borghi[i].numero_partecipanti; j++)
         {
            if (strcmp(partecipante, borghi[i].partecipanti[j]) == 0)
            {
               borghi[i].punteggio += punteggio; // Aggiunta del punteggio al borgo corrispondente
            }
         }
      }
   }
   return;
}

void stampaPunteggi(struct borgo borghi[MAX_BORGHI], int num_borghi)
{
   int i;

   for (i = 0; i <num_borghi; i++)
   {
      printf("%s %3d\n", borghi[i].nome, borghi[i].punteggio);
   }

   return;
}