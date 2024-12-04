#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0


#define NPIANI 3
#define NFILE 4
#define NPOSTI 10

#define C_RITIRO 1
#define C_DEPOSITO 2

struct data
{
   int giorno;
   int mese;
   int anno;
};

struct ora
{
   int ore;
   int minuti;
   int secondi;
};

struct data_e_ora
{
   struct data data;
   struct ora ora;
};


struct posto_auto
{
   char trarga[16];
   struct data_e_ora ingresso;
   int occupato;
};


int main()
{
   gestisci_parcheggio();

   return EXIT_SUCCESS;
}

void gestisci_parcheggio(void)
{
   int comando;

   //dichiarazione del vettore multidimensionale
   struct posto_auto parcheggio[NPIANI][NFILE][NPOSTI];

   //inizializzazione del vettore
   inizializza_parcheggio(parcheggio);


   //ciclo infinito per la gestione del parcheggio
   while (true)
   {
      //leggi_comando
      comando = leggi_comando();

      //chiama la funzione in base al comando o richiedi in caso di errore
      switch (comando)
      {
      case C_RITIRO:
         //chiama la funzione di ritiro dell'auto
         break;
      
      case C_DEPOSITO:
         //chiama la funzione di deposito dell'auto
         break;

      default:
         break;
      }

   }
}