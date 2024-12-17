#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strinsert(char t[], char s[]) {
    // Rimuove il newline da s e t, se presente
    if ((strlen(s) > 0) && (s[strlen(s) - 1] == '\n')) {
        s[strlen(s) - 1] = '\0';
    }
    if ((strlen(t) > 0) && (t[strlen(t) - 1] == '\n')) {
        t[strlen(t) - 1] = '\0';
    }

    int len_t = strlen(t);
    int len_s = strlen(s);

    // Sposta la stringa t alla destra per fare spazio per s
    for (int i = len_t; i >= 0; i--) {
        t[i + len_s] = t[i];
    }

    printf(">%s<\n", t);

    // Copia la stringa s all'inizio di t
    for (int i = 0; i < len_s; i++) {
        t[i] = s[i];
    }

    printf(">%s<\n", t);
}

int main() {
    char s[100], t[100];

    printf("prima stringa: ");
    fgets(t, 100, stdin);

    printf("seconda stringa: ");
    fgets(s, 100, stdin);

    strinsert(t, s);

    puts(t);

    return 0;
}