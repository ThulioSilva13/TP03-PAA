#include "lerArquivo.h"
#include "KMP.h"
#define MAXLENGTH 10000

void lerArquivoPrincipal(char *fileName, char **arrayText)
{
    int i = 0;
    int repeticoes;
    char line[MAXLENGTH];
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("Falha ao ler o arquivo");
    }
    while (fgets(line, MAXLENGTH, file) != NULL)
    {
        arrayText[i] = strdup(line);
        repeticoes += BuscaKMP("CT", arrayText[i]);
        i++;
    }
    // for (int j = 0; j < i; j++)
    //     printf("\n%s", arrayText[j]); //Exibi as palavras que estao no vetor.
    //printf("\n%d", repeticoes);

    fclose(file);
}

