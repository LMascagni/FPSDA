/*
scrivere il codice per calcolare la data di scadenza:

usiamo una funzione data++ che somma 1 alla data (funzione già fatta e chiamata giorno_successivo)
e la mettiamo in un ciclo che la ripete n volte. sapendo che n è il numero di giorni dopo cui il cibo scade:
*/

//somma n a data:

inizializza contatore a 0;

while (contatore < 0)
{
   giorno_successivo (&g, &m, &a);
   
   incrementa il contatore;
}

/*
ci possono essere problemi di conversione:
es: double x;
   int f(x);
   ...
   void f(int n) -> in questo caso la funzione richiede un int n = double x, e quindi viene usata la parte intera di x, o per lo meno la parte di x che sta nello spazio di memoria di un int
   {
      ...
   }

PUNTATORI:
permettono di modificare delle variabili in f(x) o pezzi di programmi che richiamano un'altra f(x).
la memoria è organizzata in byte e ogni byte ha un suo indirizzo.
a int n il compilatore assegna uno spazio in memoria casuale (dove c'è abbastanza spazio per contenerla)
il compilatore riserva uno spazio in memoria per int*ptr (se dichiarato lol)

se scrivo ptr = &n; in ptr ho l'indirizzo di memoria di n
se scrivo *ptr = 8;
è equivalente a scrivere n = 8;
n = 8; lo posso fare solo nell'ambito dello scope di n, cioè dalla { prima della dichiarazione alla } corrispondente
fuori da quelle due {} il nome di n è sconosciuto e per modificarla devo obbligatoriamente usare il suo indirizzo

es:
f(&n); //NEL MAIN

void f(int *p) //FUORI DAL MAIN: in f(int *p) accade: p = &n;
{
   *p = 8;
}

INDIRIZZO: se siamo FUORI dallo scope della variabile
NOME: se siamo DENTRO lo scope della variabile


nel printf:
%x.ylf
   x: cifre prima della virgola
   y: cifre decimali
*/

/*
STRINGHE E VETTORI:
   spesso abbiamo sotto mano sequenza ordinare di numeri o codici ascii (che sono numeri)
   VETTORE/ARRAY: insieme oridinato di dati omogenei (tutti int o tutti char o tutti double etc)
      permettono di identificare tutto l'insieme con un solo identificatore.
      i singoli elementi del vettore sono identificati con un indice (che parte da 0).
      ogni casella è grande solo quanto serve per contenere 1 elemento e basta.
      il vettore è dichiarato con:
         tipo identificatore [lunghezza]; ---> int v[10]; (vettore v lungo 10 elementi interi)
      singoli elementi del vettore: v[0], v[1], ... , v[9].

      esempio:
      for( i = 0; i < dim; i++)
      {
         printf("%d\n", v[i]);
      }

   i vettori possono essere inizializzati con delle costanti (come le variabili):
      int v[5] = {30, 2, 34, 9, 15}; INIZIALIZZATO SOLO NELLA DEINIZIONE (non a metà del codice)

   N.B.: IL COMPILATORE NON PUO' VERIFICARE SE L'INDICE ECCEDE LA LUNGHEZZA DEL VETTORE
      IL COMPILATORE USA AREE DI MEMORIA GIA' USATE (GENERA DATI SBAGLIATI SENZA DARE ERRORI) 
      O A CUI NON PUO' ACCEDERE (ABORTISCE IL PROGRAMMA).

*/

/*
DIFFERENZA TAR FOR E WHILE:
   FOR: so il numero di iterazioni da fare
   WHILE: non conosco il numero di iterazioni, ma solo la condizione di uscita
*/