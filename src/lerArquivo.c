#include "lerArquivo.h"
#include "KMP.h"
#define MAXLENGTH 10000

void lerArquivoPrincipal(char *fileName, char **arrayText)
{
    int i = 0;
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
        i++;
    }

    fclose(file);
}

