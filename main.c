#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./src/lerArquivo.h"
#define MAXLENGTH 10000
int menu(int opcao)
{
    printf("\n\n=========== MENU ===========");
    printf("\n0) Sair");
    printf("\n1) Ler arquivos");
    printf("\nEscolha: ");
    scanf("%d",&opcao);
    return opcao;
}

int main(int argc, char **argv)
{
    char *arrayHuman[MAXLENGTH], *arrayChimpanzee[MAXLENGTH], *arrayDog[MAXLENGTH]; 
    int opcao = -1;
    while(opcao != 0)
    {
        opcao = menu(opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            lerArquivoPrincipal("human.txt", arrayHuman);
            lerArquivoPrincipal("dog.txt", arrayDog);
            lerArquivoPrincipal("chimpanzee.txt", arrayChimpanzee);
            printf("%s", arrayHuman[30]);
            printf("%s", arrayDog[30]);
            printf("%s", arrayChimpanzee[30]);
        default:
            break;
        }
    }

    return 0;
}
