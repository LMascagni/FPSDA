#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALTEZZA_MAX_CAMPO 15
#define LARGHEZZA_MAX_CAMPO 15
#define LUNGHEZZA_MAX_STRINGA 32

int piazzaNave(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO], char tipoNave[LUNGHEZZA_MAX_STRINGA], int xPos, int yPos, char orientamento);
void stampaCampo(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO]);
void inizializzazioneCampo(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO]);
int lunghezzaNave(char tipoNave[LUNGHEZZA_MAX_STRINGA]);
int chkPosizionamento(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO], int xPos, int yPos, char orientamento, int lunghezza);
void riempi_campo_di_battaglia(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO]);
void battaglia_navale(void);


int main()
{
   battaglia_navale();

   return EXIT_SUCCESS;
}


void battaglia_navale(void)
{
   char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO];

   riempi_campo_di_battaglia(campo);

   stampaCampo(campo);

   return;
}

void riempi_campo_di_battaglia(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO])
{
   char tipoNave[LUNGHEZZA_MAX_STRINGA];
   int xPos, yPos;
   char orientamento;

   inizializzazioneCampo(campo);

   int navePiazzata;

   while (scanf("%s %d %d %c", tipoNave, &xPos, &yPos, &orientamento) != EOF)
   {
      if (orientamento != 'V' && orientamento != 'O')
      {
         printf("orientamento sconosciuto: %c\n", orientamento);
         exit(EXIT_FAILURE);
      }

      navePiazzata = piazzaNave(campo, tipoNave, xPos, yPos, orientamento);

      if (navePiazzata == 0)
      {
         printf("errore di caricamento della nave: %s %d %d %c\n", tipoNave, xPos, yPos, orientamento);
         exit(EXIT_FAILURE);
      }
      else if (navePiazzata == -1)
      {
         printf("tipo di nave sconosciuto: %s\n", tipoNave);
         exit(EXIT_FAILURE);
      }
   }

   return;
}


int chkPosizionamento(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO], int xPos, int yPos, char orientamento, int lunghezza)
{
   int i;

   if ((orientamento == 'V' && (yPos + lunghezza) > LARGHEZZA_MAX_CAMPO) || (orientamento == 'O' && (xPos + lunghezza) > ALTEZZA_MAX_CAMPO))
   {
      return 0;
   }

   for (i = 0; i < lunghezza; i++)
   {
      if ((orientamento == 'V' && campo[yPos + i][xPos] != ' ') || (orientamento == 'O' && campo[yPos][xPos + i] != ' '))
      {
         return 0;
      }
   }
   return 1;
}

void inizializzazioneCampo(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO])
{
   int i, j;

   for (i = 0; i < ALTEZZA_MAX_CAMPO; i++)
   {
      for (j = 0; j < LARGHEZZA_MAX_CAMPO; j++)
      {
         campo[i][j] = ' ';
      }
   }
}

int piazzaNave(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO], char tipoNave[LUNGHEZZA_MAX_STRINGA], int xPos, int yPos, char orientamento)
{
   int lunghezza, i;
   lunghezza = lunghezzaNave(tipoNave);

   if (lunghezza == -1)
   {
      return -1;
   }

   if (chkPosizionamento(campo, xPos, yPos, orientamento, lunghezza) == 0)
   {
      return 0;
   }
   
   for (i = 0; i < lunghezza; i++)
   {
      if(orientamento == 'V')
      {
         campo[yPos + i][xPos] = '*';
      }
      else
      {
         campo[yPos][xPos + i] = '*';
      }
   }

   return 1;
}

int lunghezzaNave(char tipoNave[LUNGHEZZA_MAX_STRINGA])
{
   char listaNavi[5][LUNGHEZZA_MAX_STRINGA] =
      {
         {""},
         {"ricognitore"},
         {"incrociatore"},
         {"cacciatorpediniere"},
         {"portaerei"},
      };

   int i;

   for (i = 0; i < 5; i++)
   {
      if (strcmp(tipoNave, listaNavi[i]) == 0)
      {
         return i + 1;
      }
   }
   return -1;
}

void stampaCampo(char campo[ALTEZZA_MAX_CAMPO][LARGHEZZA_MAX_CAMPO])
{
   int i, j;

   for (i = 0; i < ALTEZZA_MAX_CAMPO; i++)
   {
      printf("%2d", ALTEZZA_MAX_CAMPO - i - 1);
      for (j = 0; j < LARGHEZZA_MAX_CAMPO; j++)
      {
         if (campo[ALTEZZA_MAX_CAMPO - i - 1][j] == ' ')
         {
            printf("   ");
         }
         else
         {
            printf(" * ");
         }
      }
      printf("\n");
   }
   printf("  ");
   for (j = 0; j < LARGHEZZA_MAX_CAMPO; j++)
   {
      printf("%2d ", j);
   }
   printf("\n");
}
