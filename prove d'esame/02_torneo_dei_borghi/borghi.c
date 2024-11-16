#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* Struttura per memorizzare le informazioni di un borgo
struct borgo
{
   char nome[32];             // Nome del borgo
   int numero_partecipanti;   // Numero di partecipanti del borgo
   char partecipanti[20][32]; // Nomi dei partecipanti del borgo
   int punteggio;             // Punteggio complessivo del borgo
};

int main()
{
   //* Dichiarazione delle variabili
   struct borgo borghi[15]; // Array di borghi
   int num_borghi;          // Numero di borghi
   int i, j;
   char partecipante[32];
   int punteggio;

   //* Apertura dei file
   FILE *file_partecipanti;
   FILE *file_punteggi;

   file_partecipanti = fopen("partecipanti.txt", "r");
   file_punteggi = fopen("punteggi.txt", "r");

   //* Controllo se i file sono stati aperti correttamente
   if (file_partecipanti == NULL || file_punteggi == NULL)
   {
      printf("Errore nell'apertura dei file.\n");
      return EXIT_FAILURE;
   }

   //* Lettura dei dati dai file
   // Parsing dei borghi
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
      borghi[i].punteggio = 0;
   }
   
#ifdef DEBUG
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
   while(fscanf(file_punteggi, "%s %d", partecipante, &punteggio) != EOF)
   {
      //printf("%s %d\n", partecipante, punteggio);

      for (i = 0; i < num_borghi; i++)
      {
         for (j = 0; j < borghi[i].numero_partecipanti; j++)
         {
            if (strcmp(partecipante, borghi[i].partecipanti[j]) == 0)
            {
               borghi[i].punteggio += punteggio;
            }
         }
         
      }
      
   }

   // Stampa dei punteggi totali per ciascun borgo
   for (i = 0; i <num_borghi; i++)
   {
      printf("%s %3d\n", borghi[i].nome, borghi[i].punteggio);
   }
   

   // Chiusura dei file
   fclose(file_partecipanti);
   fclose(file_punteggi);

   return EXIT_SUCCESS;
}