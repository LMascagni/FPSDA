#include <stdio.h>
#include <stdlib.h>

int checkdate (int g, int m, int a);
int giorni_del_mese (int mese, int anno);
int bisestile (int anno);

void sommaData(int *ptr_g, int *ptr_m, int *ptr_a, int n);


int main()
{
#ifdef DEBUG
    printf("DEBUG ATTIVO\n");
#endif

    int g, m, a;
    int n;
    do
    {
        //printf("inserisci giorno, mese e anno: ");
        scanf("%d %d %d", &g, &m, &a);
        // controllo della data
        if(!checkdate(g, m, a))
        {
            //printf("ERRORE: Data inserita errata\n");
            printf("non corretta");
        }
    } while (!checkdate(g, m, a));
    
    printf("inserisci n: ");
    scanf("%d", &n);

#ifdef DEBUG
    printf("DEBUG: Valori inseriti\n");
    printf("g: %d, m: %d, a: %d, n: %d\n", g, m, a, n);
#endif

    sommaData(&g, &m, &a, n);

    printf("%d/%d/%d", g, m, a);

    return EXIT_SUCCESS;
}


void sommaData(int *ptr_g, int *ptr_m, int *ptr_a, int n)
{
    *ptr_g += n;

    while (*ptr_g > giorni_del_mese(*ptr_m, *ptr_a))
    {
        *ptr_g -= giorni_del_mese(*ptr_m, *ptr_a);
        (*ptr_m)++;
        if (*ptr_m > 12)
        {
            *ptr_m = 1;
            (*ptr_a)++;
        }
    }

    while (*ptr_g < 1)
    {
        (*ptr_m)--;
        if(*ptr_m < 1)
        {
            *ptr_m = 12;
            (*ptr_a)--;
        }
        *ptr_g += giorni_del_mese(*ptr_m, *ptr_a);
    }
}




//FUNZIONE CHECKDATE
/*
Questa funzione restituisce 1 se la data inserita è corretta,
mentre restituisce 0 se la data è errata.
*/
int checkdate (int g, int m, int a)
{
	// controlla anno
	if (a < 1582)
		return 0;

	// controlla mese (se non compreso tra 1 e 12)
	if ( !(m >= 1 && m <= 12) )
		return 0;

	// controlla giorno (non compreso tra 1 e i giorni di quel mese)
	if ( !(g >= 1 && g <= giorni_del_mese (m, a)) )
		return 0;

	// se la funzione non e` terminata prima, la data e` valida
	return 1;
}

//FUNZIONE GIORNI_DEL_MESE
/*
Questa funzione restituisce il numero di giorni del mese
considerando anche gli anni bisestili
*/
int giorni_del_mese (int mese, int anno)
{
	switch (mese)
	{
		case 11:
		case 4:
		case 6:
		case 9:  return 30;

		case 2:  if (bisestile (anno))
						return 29;
					else
						return 28;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: return 31;

		default:  printf ("mese %d non valido!\n", mese);
					 exit (EXIT_FAILURE);
	}
}

//FUNZIONE BISESTILE
/*
Questa funzione restituisce 1 se l'anno inserito è bisestile,
mentre restituisce 0 se non lo è.
*/
int bisestile (int anno)
{
	return ( (anno % 4 == 0) && (anno % 100 != 0) ) || (anno % 400 == 0);
}