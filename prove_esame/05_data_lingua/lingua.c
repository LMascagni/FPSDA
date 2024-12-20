#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN_COD 3
#define MAX_LEN_TRAD 10
#define MAX_LEN 64
#define N_MESI 12

struct dict_mese
{
   char cod[MAX_LEN_COD + 1];
   char traduzioni[MAX_LEN_TRAD][MAX_LEN];
};

struct dizionario
{
   struct dict_mese mesi[N_MESI];
   int nLingue;
   char codLingue[MAX_LEN_TRAD][MAX_LEN];
};

struct dizionario parseDict(FILE *fp);
void traduciFile(FILE *fp, struct dizionario dict);
void sostituisciCarattere(char str[MAX_LEN], char c_vecchio, char c_nuovo);
void traduciData(char data[MAX_LEN], struct dizionario dict, char cod[MAX_LEN]);
int getCodice(char cod[MAX_LEN], struct dizionario dict);
int getMese(char mese[MAX_LEN], struct dizionario dict);

#ifdef DEBUG
void stampaDict(struct dizionario dict);
#endif

int main(int argc, char *argv[])
{
   // controllo argomenti
   if (argc != 3)
   {
      printf("argomenti non validi!\n");
      exit(EXIT_FAILURE);
   }

   // apertura dei file
   FILE *fp_l;
   FILE *fp_t;

   fp_l = fopen(argv[2], "r");
   fp_t = fopen(argv[1], "r");

   if ((fp_l == NULL) || (fp_t == NULL))
   {
      printf("errore nell'apertura dei file!\n");
      exit(EXIT_FAILURE);
   }

   struct dizionario dict;
   // leggi il dizionario
   dict = parseDict(fp_l);

   // stampa completa del dizionario (per debug)
#ifdef DEBUG
   stampaDict(dict);
#endif

   traduciFile(fp_t, dict);

   fclose(fp_l);
   fclose(fp_t);

   return EXIT_SUCCESS;
}

struct dizionario parseDict(FILE *fp)
{
   struct dizionario dict;
   int i;

   fscanf(fp, "%*s %d  ", &dict.nLingue);
   // printf("nLingue: %d\n", dict.nLingue);
   for (i = 0; i < dict.nLingue; i++)
   {
      fscanf(fp, "%s", dict.codLingue[i]);
      // printf("COD Lingua %d: %s\n", i, dict.codLingue[i]);
   }

   i = 0;

   while (!feof(fp))
   {
      // leggi il codice del mese
      fscanf(fp, "%3s ", dict.mesi[i].cod);
      //printf("COD Mese %d: %s\n", i, dict.mesi[i].cod);
      // leggi le traduzioni del mese
      int j;
      for (j = 0; j < dict.nLingue; j++)
      {
         fscanf(fp, "%s ", dict.mesi[i].traduzioni[j]);
         //printf("traduzione %d: %s\n", j, dict.mesi[i].traduzioni[j]);
         
         //printf("traduzione %d: %s\n", j-1, dict.mesi[i].traduzioni[j-1]);
      }

      i++;
   }

   return dict;
}

void traduciFile(FILE *fp, struct dizionario dict)
{
   char nome[MAX_LEN], cognome[MAX_LEN];
   char data[MAX_LEN];
   char cod[MAX_LEN];
   while (fscanf(fp, "%s %s %s %s", cognome, nome, data, cod) != EOF)
   {
      // togliere gli underscore dal nome e cognome (sostituire il carattere)
      sostituisciCarattere(cognome, '_', ' ');
      sostituisciCarattere(nome, '_', ' ');

      // modificare la stringa data
      traduciData(data, dict, cod);

      // stampa la "traduzione"
      printf("%s %s %s\n", nome, cognome, data);
   }

   return;
}

void sostituisciCarattere(char str[MAX_LEN], char c_vecchio, char c_nuovo)
{
   int i;
   i = 0;

   while (str[i] != '\0')
   {
      if (str[i] == c_vecchio)
      {
         str[i] = c_nuovo;
      }
      i++;
   }
   return;
}

void traduciData(char data[MAX_LEN], struct dizionario dict, char cod[MAX_LEN])
{
   // ottieni l'indirizzo rispettivo al codice
   int i, j;
   i = getCodice(cod, dict);

   // ottievi l'indirizzo rispettivo al mese
   int g, a;
   char mese[MAX_LEN];
   // scomponi la stringa data
   sscanf(data, "%d-%3s-%d", &g, mese, &a);

   j = getMese(mese, dict);

   // ricomponila con il mese tradotto
   sprintf(data, "%d %s %d", g, dict.mesi[j].traduzioni[i], a);

   return;
}

int getCodice(char cod[MAX_LEN], struct dizionario dict)
{
   int i;
   for (i = 0; i < dict.nLingue; i++)
   {
      if (strcmp(cod, dict.codLingue[i]) == 0)
      {
         return i;
      }
   }

   return -1;
}

int getMese(char mese[MAX_LEN], struct dizionario dict)
{
   int i;
   for (i = 0; i < N_MESI; i++)
   {
      if (strcmp(mese, dict.mesi[i].cod) == 0)
      {
         return i;
      }
   }

   return -1;
}

#ifdef DEBUG
void stampaDict(struct dizionario dict)
{
   int i, j;
   printf("--------------------\n");
   printf("nLingue: %d\n", dict.nLingue);
   for (i = 0; i < dict.nLingue; i++)
   {
      printf("COD Lingua %d: %s\n", i, dict.codLingue[i]);
   }

   for (i = 0; i < N_MESI; i++)
   {
      printf("COD Mese %d: %s\n", i, dict.mesi[i].cod);
      for (j = 0; j < dict.nLingue; j++)
      {
         printf("traduzione %d: %s\n", j, dict.mesi[i].traduzioni[j]);
      }
   }

   return;
}
#endif
