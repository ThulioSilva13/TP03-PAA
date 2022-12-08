#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./src/lerArquivo.h"
#include "./src/KMP.h"
#include "./src/produtoCartesiano.h"
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
    //char *arrayHuman[MAXLENGTH];
    //char *arrayChimpanzee[MAXLENGTH];
    char *arrayDog[MAXLENGTH];
    int opcao = -1;
    while(opcao != 0)
    {
        opcao = menu(opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            //lerArquivoPrincipal("human.txt", arrayHuman);
            lerArquivoPrincipal("dog.txt", arrayDog);
            permutacao(3);
            //lerArquivoPrincipal("chimpanzee.txt", arrayChimpanzee);
            //BuscaKMP("AA", *arrayDog);
            // for(int i = 0; i < strlen(*arrayDog); i++)
            // {
            //     repeticoes += BuscaKMP("TTTCCAAAA", arrayDog[i]);
            // }
          // printf("Repeticoes totais: %d", repeticoes);
            

        default:
            break;
        }
    }

    return 0;
}
