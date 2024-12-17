#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Funzione per calcolare il complemento a 2 di una stringa binaria
// Funzione per calcolare il complemento a 2 di una stringa binaria
void complemento_a_2(char *num) {
    int n = strlen(num);
    int i;
    int trovato_uno = 0;

    // Copia i bit fino al primo '1' (compreso) da destra
    for (i = n - 1; i >= 0; i--) {
        if (trovato_uno) {
            num[i] = (num[i] == '0') ? '1' : '0';
        } else {
            if (num[i] == '1') {
                trovato_uno = 1;
            }
        }
    }
}

int main() {
    char num[100];

    printf("Inserire il numero in binario: ");
    scanf("%s", num);

    complemento_a_2(num);

    printf("%s\n", num);

    return 0;
}