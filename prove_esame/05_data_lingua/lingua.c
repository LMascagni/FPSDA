#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN_COD 3
#define MAX_LEN_TRAD 10
#define MAX_LEN 32
#define N_MESI 12

struct dict_mese
{
    char cod[MAX_LEN_COD];
    char *traduzioni[MAX_LEN_TRAD];
};

struct dizionario
{
    struct dict_mese mesi[N_MESI];
    int nLingue;
    char *codLingue[MAX_LEN_TRAD];    
};

struct dizionario parseDict(FILE *fp);

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("argomenti non validi!\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp_l;
    FILE *fp_t;

    fp_l = fopen(argv[1], "r");
    fp_t = fopen(argv[2], "r");

    if((fp_l == NULL) || (fp_t == NULL))
    {
        printf("errore nell'apertura dei file!\n");
        exit(EXIT_FAILURE);
    }

    struct dizionario dict;

    dict = parseDict(fp_l);

    fclose(fp_l);
    fclose(fp_t);

    return EXIT_SUCCESS;
}

struct dizionario parseDict(FILE *fp)
{
    struct dizionario dict;
    int i;

    fscanf(fp, "Nlingue %d  ", &dict.nLingue);
    printf("lingue: %d\n", dict.nLingue);
    for(i = 0; i < dict.nLingue; i++)
    {
        fscanf(fp, "%s", dict.codLingue[i]);
        printf("%d: %s\n", i, dict.codLingue[i]);
    }

    return dict;
}