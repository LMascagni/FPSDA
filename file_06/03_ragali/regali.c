#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 32

struct parallelepipedo
{
   double l, w, h;
};

struct scatola
{
   struct parallelepipedo dim;
   char stato[MAX_LEN];
};

struct regalo
{
   char nome[MAX_LEN];
   struct scatola scatola;
};



double carta_per_regalo(struct regalo regalo, double percentuale);
double area_parallelepipedo(struct parallelepipedo p);


int main()
{
   struct regalo regalo;

   char file[MAX_LEN];

   double carta;  //in m^2
   carta = 0;

   FILE *fp;

   printf("nome del file dei regali: ");
   scanf("%s", file);

   fp = fopen(file, "r");

   if(fp == NULL)
   {
      printf("errore nell'apertura del file");
      exit(EXIT_FAILURE);
   }

   while(fscanf(fp, "%s %lf %lf %lf %s", regalo.nome, &regalo.scatola.dim.l, &regalo.scatola.dim.w, &regalo.scatola.dim.h, regalo.scatola.stato) != EOF)
   {
      carta += carta_per_regalo(regalo, 15);
   }

   printf("servono %lf metri quadrati di carta da regalo\n", carta);

   fclose(fp);

   return EXIT_SUCCESS;
}

double carta_per_regalo(struct regalo regalo, double percentuale)
{
   if(strcmp(regalo.scatola.stato, "grezza") == 0)
   {
      return area_parallelepipedo(regalo.scatola.dim) * (1 + (percentuale / 100)) / 10000;
   }

   return 0;
}

double area_parallelepipedo(struct parallelepipedo p)
{
   return 2 * ((p.h * p.l) + (p.l * p.w) + (p.w * p.h));
}