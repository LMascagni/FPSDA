#include <stdio.h>
#include <stdlib.h>

int checkdate (int g, int m, int a);
int giorni_del_mese (int mese, int anno);
int bisestile (int anno);

int countdays(int g, int m, int a);

int main()
{

#ifdef DEBUG
	 printf("DEBUG ATTIVO");
#endif

	int giorno, mese, anno;

	// leggi la data
	printf ("inserisci la data (g, m, a): ");
	scanf ("%d %d %d", &giorno, &mese, &anno);

	if (countdays(giorno, mese, anno))
		printf("numero di giorni = %d", countdays(giorno, mese, anno));
	else
		printf("ERRORE: data errata");

	return EXIT_SUCCESS;
}


//FUNZIONE COUNTDAYS
/*
Questa funzione resistuisce il numero di giorni dall'inizio dell'anno
Se la data è errata allora restituisce 0.
*/
int countdays(int g, int m, int a)
{
	if(!checkdate(g,m,a))
	{
#ifdef DEBUG
	printf("DEBUG: ");
	printf("la data e' errata");
#endif
		return 0;
	}
	
	int nGiorni, meseCorrente;
	nGiorni = 0;
	meseCorrente = 1;

	while(meseCorrente < m)
	{
		nGiorni += giorni_del_mese (m, a);
		meseCorrente++;
	}

	nGiorni += g;

	return nGiorni;
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

	/* 
	if ( ( (anno % 4 == 0) && (anno % 100 != 0) ) || (anno % 400 == 0) )
		return 1;
	else
		return 0;
	*/
}