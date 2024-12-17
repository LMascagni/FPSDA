#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converti_data(char data1[], char data2[])
{
   int anno = 0, mese = 0, giorno = 0;
   char *mesi[] = {"", "gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
   int i = 0;

   // Estrai anno
   while (data1[i] != '-')
   {
      anno = anno * 10 + (data1[i] - '0');
      i++;
   }
   i++; // Salta il '-'

   // Estrai mese
   while (data1[i] != '-')
   {
      mese = mese * 10 + (data1[i] - '0');
      i++;
   }
   i++; // Salta il '-'

   // Estrai giorno
   while (data1[i] != '\0')
   {
      giorno = giorno * 10 + (data1[i] - '0');
      i++;
   }

   // Costruisci la stringa data2 nel formato richiesto
   sprintf(data2, "%d %s dell'anno %d", giorno, mesi[mese], anno);
}

int main()
{
   char data1[32];
   char data2[64];

   // Leggi la data in formato aaaa-mm-gg
   fgets(data1, 32, stdin);

   // Rimuovi il carattere di newline se presente
   data1[strcspn(data1, "\n")] = '\0';

   // Converti la data
   converti_data(data1, data2);

   // Stampa la data convertita
   puts(data2);

   return 0;
}