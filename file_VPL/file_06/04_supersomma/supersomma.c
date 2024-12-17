#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM_LEN 1000

void supersomma_da_file(FILE *fp);
void rshift (char s[], int n);
void supersomma (char a[], char b[], char c[]);

int main(int argc, char *argv[])
{
	FILE *fp;
	char file[32];
	
	printf("nome del file di input: ");
	scanf("%s", file);
	
	fp = fopen(file, "r");
	
	if (fp == NULL)
	{
		printf("errore nella'apertura del file\n");
		exit(EXIT_FAILURE);
	}
	
	supersomma_da_file(fp);
	
   fclose(fp);

	return EXIT_SUCCESS;
}

void supersomma_da_file(FILE *fp)
{
	char n1[MAX_NUM_LEN], n2[MAX_NUM_LEN], r[MAX_NUM_LEN + 1];
	while(fscanf(fp, "%s %*s %s %*s", n1, n2) != EOF)
	{
		supersomma(n1, n2, r);
		printf("%s + %s = %s\n", n1, n2, r);
	}
	return;
}

void supersomma (char a[], char b[], char c[])
{
   int i_a, i_b, i_c, riporto, risultato_somma;

   // posizionati sull'ultimo carattere di ciascuna delle due stringhe
   i_a = strlen (a) - 1;
   i_b = strlen (b) - 1;

   // i_c va inizlizzato al massimo tra i_a e i_b
   i_c = (i_a > i_b) ? i_a : i_b;

   // termina la stringa c con '\0'
   c[i_c+1] = '\0';

   // inizializza il riporto a zero
   riporto = 0;

   // while (ci sono cifre da sommare, cioe` entrambi gli indici non sono ancora minori di zero)
   while ( ! (i_a < 0 && i_b < 0) )  // oppure  while (i_a >= 0 || i_b >= 0)
   {
      // somma;
      // if (ci sono ancora cifre in entrambe le stringhe)
      if (i_a >= 0 && i_b >= 0)
      {
         // somma le cifre e il riporto;
         risultato_somma = (a[i_a] - '0') + (b[i_b] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';   // codice ASCII che rappresenta a cifra ottenuta
         riporto = risultato_somma / 10;  // divisione intera con troncamento   
      }
      // else if (ci sono solo cifre in a)
      else if (i_a >= 0 && i_b < 0)
      {
         // somma la cifra di a con il riporto;
         risultato_somma = (a[i_a] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';   // codice ASCII che rappresenta a cifra ottenuta
         riporto = risultato_somma / 10;  // divisione intera con troncamento   
      }
      // else // ci sono solo cifre in b
      else // if (i_b >= 0 && i_a < 0)
      {
         // somma la cifra in b con il riporto;
         risultato_somma = (b[i_b] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';   // codice ASCII che rappresenta a cifra ottenuta
         riporto = risultato_somma / 10;  // divisione intera con troncamento   
      }

      // passa alla cifra precedente in ciascuna stringa;
      i_a--;
      i_b--;
      i_c--;
   }

   // if (il riporto non e` zero)
   if (riporto > 0)
   {
      // sposta tutto c a destra di una posizione e scrivi il riporto
      rshift (c, 1);
      c[0] = riporto + '0';
   }

   return;
}

void rshift (char s[], int n)
{
   int i;

   if (n < 0)
   {
      printf ("rshift - errore: n negativo (%d)\n", n);
      exit (EXIT_FAILURE);
   }

   // posizionati al fondo della stringa
   for (i = 0; s[i] != '\0'; i++);  // avanza soltanto

   // i punta a '\0': inizia spostandolo
   do
   {
      s[i+n] = s[i];
      i--;  // passa al carattere precedente
   } while (i >= 0);

   return;
}
