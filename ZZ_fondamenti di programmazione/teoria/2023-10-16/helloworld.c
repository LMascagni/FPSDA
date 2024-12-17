//type hello_world.c
//librerie standard
#include <stdio.h> /*direttiva al preprocessor: include nel programma il file stdio.h che serve per 
utilizzare le funzioni di input (i) e output (o).*/
#include <stdlib.h>

/*programma costituito da una funzione principale main, in caso accompagnata da altre funzioni*/
int main() //intestazione
{//blocco di codice racchiuso tra {}
   printf ("Hello world!\n"); //Nota: \n è A CAPO
   // printf -> OUTPUT print: stampa f:formattata, posso scegliere il formato dei dati di OUTPUT
   // scanf-> INPUT scan: leggi f: formattato
   return EXIT_SUCCESS; /*equivalente a return 0; perchè in tutti sistemi operativi il segnale di 
   esecuzione corretta del programma è EXIT_SUCCESS, e in alcuni sist. op. che usano stdlib.h 
   il valore associato è 0*/
}
/*
gcc -o hello_world.exe hello_word.c
scrivendo questo creo il file eseguibile del file hello_word.c
*/

/*
STRUTTURA DEL PROGRAMMA:
- FUNZIONE: è identificata da un nome: es. main;
            ha un valore di output: es. int;
            possono essere richiamate in vari programmi e si costruirà un programma a blocchi;
- VARIABILE: deve sempre essere DICHIARATA prima di essere usata;
- DICHIARAZIONE: stabilisce il tipo di dato contenuto nella variabile e il nome della stessa: es int numero;
- ARGOMENTI: lista di valori forniti alle funzioni:
es: scanf("%d", numero); -> funzione: scanf(); "%d", numero: lista di valori da stampare e il loro formato
int main(): non si aspetta argomenti, ma può averne.

*/