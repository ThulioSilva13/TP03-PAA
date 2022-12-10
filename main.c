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
    char *arrayHuman[MAXLENGTH];
    char *arrayChimpanzee[MAXLENGTH];
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
            lerArquivoPrincipal("human.txt", arrayHuman);
            lerArquivoPrincipal("dog.txt", arrayDog);
            lerArquivoPrincipal("chimpanzee.txt", arrayChimpanzee);

            int tamanho = 0;
            printf("Entre com o tamanho: ") ;
            scanf("%d", &tamanho);

            int tamanhoConjunto = pow(tamanho,2);

            int *repeticoesCachorro =(int*)calloc(sizeof(int),tamanhoConjunto);
            int *repeticoesHumano =(int*)calloc(sizeof(int),tamanhoConjunto);
            int *repeticoesChimpanze =(int*)calloc(sizeof(int),tamanhoConjunto);
            int total = (int)pow(4, tamanho);
            char** produtoCartesiano = (char**)malloc(sizeof(char*)*total);

            for(int i = 0; i < total; i++)
            {
                produtoCartesiano[i] = (char*)malloc(tamanho + 1);
            }
            
            criaProdutoCartesiano(produtoCartesiano, tamanho);
            
            char** conjunto = (char**)malloc(sizeof(char*)*4);
            
            for(int i = 0; i < tamanhoConjunto; i++)
            {
                conjunto[i] = (char*)malloc(2);
            }


            for (int i = 0; i < tamanhoConjunto; i++)
            {
                int aleatorio = rand() % (total-1);
                if(strcmp(produtoCartesiano[aleatorio], "0") != 0)
                {
                    conjunto[i] = produtoCartesiano[aleatorio];
                    produtoCartesiano[aleatorio] = "0";
                }
                else
                {
                    i--;
                }
            }

            for (int i = 0; i < tamanhoConjunto; i++)
            {
                printf("%s ", conjunto[i]);
            }

            
            for(int i = 0; i < strlen(*arrayChimpanzee); i++)
            {
                for(int j = 0; j < tamanhoConjunto; j++)
                {
                    repeticoesChimpanze[j] += BuscaKMP(conjunto[j], arrayChimpanzee[i]);
                    
                }
            }

            for(int i = 0; i < strlen(*arrayDog); i++)
            {
                for(int j = 0; j < tamanhoConjunto; j++)
                {
                    repeticoesCachorro[j] += BuscaKMP(conjunto[j], arrayDog[i]);
                    
                }
            }

            for(int i = 0; i < strlen(*arrayHuman); i++)
            {
                for(int j = 0; j < tamanhoConjunto; j++)
                {
                    repeticoesHumano[j] += BuscaKMP(conjunto[j], arrayHuman[i]);
                    
                }
            }
            printf("\nRepeticoes humano: ");
            for(int h = 0; h < tamanhoConjunto; h++)
            {
                printf("%d ", repeticoesHumano[h]);
            }
            printf("\nRepeticoes chimpanze: ");
            for(int h = 0; h < tamanhoConjunto; h++)
            {
                printf("%d ", repeticoesChimpanze[h]);
            }
            printf("\nRepeticoes cachorro: ");
            for(int h = 0; h < tamanhoConjunto; h++)
            {
                printf("%d ", repeticoesCachorro[h]);
            }
            //printf("Repeticoes totais: %d", repeticoes);

        default:
            break;
        }
    }

    return 0;
}
