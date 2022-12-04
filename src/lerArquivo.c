#include "lerArquivo.h"
#define MAXLENGTH 10000

void lerArquivoPrincipal(char *fileName, char **arrayTextParameter)
{
    int i = 0;
    char line[MAXLENGTH];
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("Falha ao ler o arquivo");
    }
    while (fgets(line, sizeof line, file) != NULL)
    {
        arrayTextParameter[i] = strdup(line);
        
        i++;
    }
    fclose(file);
}

