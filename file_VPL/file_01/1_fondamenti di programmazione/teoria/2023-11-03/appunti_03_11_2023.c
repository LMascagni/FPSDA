/*
controllo della data:
chkdate: funzione che restituisce vero o falso in funzione della validità della data (se è giusta restituisce != 0 se è sbagliata = 0)
definiamo l'algoritmo non solo con cosa fa il sottoproblema 
ma anche che dati gli servono e che dati deve restituire:

chkdate: restituisce 0 (falso) se la data non è valida e un valore != 0 (vero) se è valida
(abbiamo definito il risultato dell'algoritmo del sottoproblema)
riceve 3 numeri interi giorno, mese, anno.
^ definizione dell'interfaccia tra la funzione e il resto del mondo.

1) cosa restituisce la funzione
2) cosa riceve
3) scriviamo il  prototipo
*/
int chkdate( int giorno, int mese, int anno);
int chkdate( int giorno, int mese, int anno)
{
   //se l'anno è precedente all'entrata in vigore del calendario gregoriano, la data non è valida
   if( anno < 1582 )
   {
      return 0; //la funzione esce direttamente: la data non è valida, quindi è falsa
   }
   //controlla se il mese è compreso tra 1 e 12
   if( mese < 1 || mese > 12)
   {
      return 0;
   }
   //controllo de il giorno è valido
   if( giorno < 1 || giorno > numero_giorni_del_mese(mese, anno);
   {
      return 0;
   }
   //ho passato tutti i controlli precedenti: la data è valida

   return 1;
}


//funzione che mi dice quanti giorni ha un mese
int numero_giorni_del_mese (int mese, int anno);

int numero_giorni_del_mese (int mese, int anno)
{
   switch (mese)
   {
      case 4: //aprile
      case 6: //giugno
      case 9: //settembre
      case 11: //novembre
         return 30; //non serve il breaperchè la funzione termina con il return, quindi non eseguirebbe la riga successiva con il break
      
      case 2: //febbrario
         if( bisestile(anno))
         {
            return 29;
         }
         else
         {
            return 28;
         }

      case 1: //gennaio
      case 3: //marzo
      case 5: //maggio
      case 7: //luglio
      case 8: //agosto
      case 10: //ottobre
      case 12: //dicembre
         return 31;
      
      default:
         printf("nemro_giorni_del_mese: mese %d non valido.\n", mese);
         exit (EXIT_FAILURE); //fa abortire completamente il programma, se mettessi il return EXIT_FAILURE ciò restituirebbe 0 o un valore alla funzione chkdate che continuerebbe comunque, facendo exit(EXIT_FAIULRE) termino il programma completamente
      /*non posso basarmi sui controlli precedenti, 
      deve essere autonoma nei controlli. così la rendo modulare, 
      se si basa sul controllo dei mesi fatto prima la funzione 
      diventa dipendante dal codice del programma*/
   }
}

//bisestile restituisce VERO se l'anno è bisestile, FALSO altrimenti
//questa funzione non serve a sapere se febbrario ha 28 o 29 gg
//mi serve per sapere se l'anno è bisestile: mi potrebbe servire
//in una funzione a cui non interessano i giorni di febbraio
int bisestile (int anno);
int bisestile (int anno)
{
   //eventuale controllo sull'anno del calendario gregoriano
   //per il problema della precessione degli equinozi
   //un anno è bisestile se: è divisibile per 4 e non è multiplo di 100, eccetto i multipli di 400.

   if( ((anno % 4 == 0) && !(anno % 100 == 0)) || (anno % 400 == 0) )
   {
      return 1;
   }
   else
   {
      return 0;
   }
   //variante nerd
//   return(( ((anno % 4 == 0) && !(anno % 100 == 0)) || (anno % 400 == 0) ) ? 1: 0);

   //variante ultra nerd
//   return(( ((anno % 4 == 0) && !(anno % 100 == 0)) || (anno % 400 == 0) ));
   //cioè: l'espressione dentro l'if restituisce un valore logico (VERO o FALSO)
   //e cosa mi serve restituire nella funzione bisestile? VERO o FALSO
   //che coincide con il valore dell'espressione. per questo posso restituire il valore dell'espressione

}

/*
NOTA: 
sintassi:

(condizione)? VERO : FALSO;

*/

/*
LIBRERIE:

struttura dei nostri programmi fino ad ora:
1)prototipi + define
2) main
3) funzioni

struttura dei nostri programmi d'ora in poi:
3 file diversi:
   1)prototipi + define -> libreria.h
   2) main -> programma.c
   3) funzioni -> libreria.c
nota: per includere nel main (programma.c) il programma di libreria.h si usa il solito #include<>
*/

//CHIEDI COME FARE:
//gcc -o -c datelib.o datelib.c  -> crea file oggetto della libreria
//gcc -Wall -o checkdate checkdate.c datelib.o -> apro il file oggetto creato prima

// gcc -Wall -o checkdate checkdate.c datelib.c -> compila la libreria e il file contemporaneamente


/*
Quanto giorni hai?
in generale: DIFFERENZA TRA DATE
es: ticket dei parcheggi: lascio la macchina in un parcheggio a lungo termine e pago in proporzione al numero di giorni che sono passati
*/

/*
p = &x;
&: fornisce l'INDIRIZZO di memoria di un oggetto (in questo caso x)
PUNTATORE: variabile che contiene l'indirizzo di memoria
dichiarabile così:
   int *p;
   (tipo di variabile da puntare *identificativo;)
   (il tipo è " int * ")
con p = &x estraiamo il valore dell'indirizzo di memoria di x e lo copiamo dentro il puntatore p

così facendo accediamo all'indirizzo di memoria della varibale attraverso il puntatore non con il nome della variabile
NOTA: RIVEDI LEZIONE A 4:00h

l'espressione *p è equivalente a scrivere x
*p = valore; <=> x = valore;

y = *p; do a y il valore contenuto nel puntatore *p

double *dp; -> dp è un puntatore a double
char *ch; -> ch è un puntatore a char
*ip = *ip + 10;

INCREMENTO DI 1 IL VALORE ALL'INTERNO DEL PUNTATORE:
   ++*ip;
   (*ip)++;

INCREMENTO DI 1 IL VALORE DEL PUNTATORE:
   *ip++;
   es. *ip = 1000
       *ip++ = 1001

con i puntatori posso modificare una variabile senza averne il nome, basta l'indirizzo di memoria
tutti gli operatori funzionano anche con i puntatori (+, -, *, /...)
*/

/*
C passa alle funzioni i valori degli argomenti (by value)
quindi la funzione lavora con copie dei valori delle variabili

per usare direttamente le variabili e modificarne il valore in memoria
si devono usare i puntatori e passare gli argomenti in sè, non copie dei valori (by reference)

SWAP: funzione che scambia 2 valori 
se la implemento così non funziona:
   swap (a, b); //nel main
   ...
   void swap (int x, int y)
   {
      int tmp;
      tmp = x;
      x = y;
      y = tmp;
   }
STO LAVORANDO SU COPIE, QUINDI NON MODIFICO I VALORI IN MEMORIA, MA SOLO LE COPIE TEMPORANEE CREATE PER ESEGUIRE LA FUNZIONE

SE PASSO A swap I PUNTATORI AVVIENE REGOLARMENTE, SCAMBIO LE VARIABILI, NON LE LORO COPIE TEMPORANEE
swap (&a, &b); //nel main
   ...
   void swap (int *ptr_x, int *ptr_y)
   {
      int tmp;
      tmp = *ptr_x;
      *ptr_x = *ptr_y;
      *ptr_y = tmp;
   }
*/