#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DATE 40
#define MAX_STR_LEN 32

struct sdata
{
   int g;
   int m;
   int a;
};

struct pasto
{
   struct sdata data;
   char p_c[MAX_STR_LEN];
   int voti;
};

int leggi_file(FILE *fp, struct pasto l_pasti[MAX_DATE]);
//! ERR 3 - nel secondo file la data non ha come separatore '/' ma ha '-'
struct sdata estrai_data(char data[MAX_STR_LEN]);
void conta_voti(FILE *fp, struct pasto l_pasti[MAX_DATE], int n_pasti);
void incrementa_voto(struct pasto l_pasti[MAX_DATE], struct pasto pasto, int n_pasti);
int cerca_pasto(struct pasto l_pasti[MAX_DATE], struct pasto pasto, int n_pasti);
int datecmp(struct sdata d1, struct sdata d2);
void stampa_risultati(struct pasto l_pasti[MAX_DATE], int n_pasti);
int cerca_voto_massimo(struct pasto l_pasti[MAX_DATE], int n_pasti);

int main (int argc, char *argv[])
{
   if(argc != 3)
   {
      fprintf(stderr, "argomenti non validi\n");
      exit(EXIT_FAILURE);
   }

   FILE *fp_date;
   FILE *fp_voti;

   fp_date = fopen(argv[1], "r");
   fp_voti = fopen(argv[2], "r");

   if((fp_date == NULL) || (fp_voti == NULL))
   {
      fprintf(stderr, "errore nell'apertura dei file\n");
      exit(EXIT_FAILURE);
   }

   struct pasto l_pasti[MAX_DATE];
   int n_pasti;

   n_pasti = leggi_file(fp_date, l_pasti);

   conta_voti(fp_voti, l_pasti, n_pasti);

   stampa_risultati(l_pasti, n_pasti);

   fclose(fp_date);
   fclose(fp_voti);

   return EXIT_SUCCESS;
}

int leggi_file(FILE *fp, struct pasto l_pasti[MAX_DATE])
{
   char data[MAX_STR_LEN];
   int i;
   i = 0;

   while(fscanf(fp, "%s %s", l_pasti[i].p_c, data) != EOF)
   {
      l_pasti[i].data = estrai_data(data);
      //printf("%s -> %d %d %d\n", data, l_pasti[i].data.g, l_pasti[i].data.m, l_pasti[i].data.a);
      l_pasti[i].voti = 0;
      i++;
   }

   return i;
}

struct sdata estrai_data(char data[MAX_STR_LEN])
{
   //! ERR 1 - non ho inizializzato la stuttura temporanea
   struct sdata sdata;

   int i;
   i = 0;

   while(data[i] != '/')
   {
      sdata.g = (sdata.g * 10) + (data[i] - '0');
      i++;
   }
   i++;

   while(data[i] != '/')
   {
      sdata.m = (sdata.m * 10) + (data[i] - '0');
      i++;
   }
   i++;

   while(data[i] != '\0')
   {
      sdata.a = (sdata.a * 10) + (data[i] - '0');
      i++;
   }

   return sdata;

}

void conta_voti(FILE *fp, struct pasto l_pasti[MAX_DATE], int n_pasti)
{
   char data[MAX_STR_LEN];
   char p_c[MAX_STR_LEN];
   struct pasto pasto_attuale;

   //! ERR 2 - errore nella lettura del cognome e nome.
   //? basta rimuovere la virgola e i due punti
   
   while(fscanf(fp, "%*s, %*s: %s %s", data, p_c) != EOF)
   {
      pasto_attuale.data = estrai_data(data);
      //printf("%s -> %d %d %d\n", data, pasto_attuale.data.g, pasto_attuale.data.m, pasto_attuale.data.a);
      strcpy(pasto_attuale.p_c, p_c);
      incrementa_voto(l_pasti, pasto_attuale, n_pasti);
   }

   return;
}

void incrementa_voto(struct pasto l_pasti[MAX_DATE], struct pasto pasto, int n_pasti)
{
   int index;
   index = cerca_pasto(l_pasti, pasto, n_pasti);

   if(index == -1)
   {
      return;
   }

   l_pasti[index].voti++;

   return;

}

int cerca_pasto(struct pasto l_pasti[MAX_DATE], struct pasto pasto, int n_pasti)
{
   int index;
   for(index = 0; index < n_pasti; index++)
   {
      if((strcmp(l_pasti[index].p_c, pasto.p_c) == 0) && (datecmp(pasto.data, l_pasti[index].data) == 0))
      {
         return index;
      }
   }

   return -1;
}

int datecmp(struct sdata d1, struct sdata d2)
{
   if(d1.g != d2.g)
   {
      return -1;
   }

   if(d1.m != d2.m)
   {
      return -1;
   }

   if(d1.a != d2.a)
   {
      return -1;
   }

   return 0;
}

void stampa_risultati(struct pasto l_pasti[MAX_DATE], int n_pasti)
{
   int v_max, i_max;

   i_max = cerca_voto_massimo(l_pasti, n_pasti);
   v_max = l_pasti[i_max].voti;

   int i;
   for(i = 0; i < n_pasti; i++)
   {
      if(l_pasti[i].voti == v_max)
      {
         printf("%d/%d/%d a %s: %d persone\n", l_pasti[i].data.g,
                                               l_pasti[i].data.m,
                                               l_pasti[i].data.a,
                                               l_pasti[i].p_c,
                                               l_pasti[i].voti);
      }
   }

   return;
}

int cerca_voto_massimo(struct pasto l_pasti[MAX_DATE], int n_pasti)
{
   int i, index;
   index = 0;
   for(i = 0; i < n_pasti; i++)
   {
      if(l_pasti[i].voti > l_pasti[index].voti)
      {
         index = i;
      }
   }
   return index;
}
