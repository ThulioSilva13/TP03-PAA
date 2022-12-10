#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./src/lerArquivo.h"
#include "./src/KMP.h"
#include "./src/produtoCartesiano.h"
#include "./src/similaridade.h"

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

            while(1){

                int tamanho = 0;
                int tamanhoConjunto = 0;
                int qtdRepeticoes =0;

                printf("Entre com o tamanho de cada elemento do conjunto: ") ;
                scanf("%d", &tamanho);
                printf("Entre com a quantidade de elementos do conjunto: ") ;
                scanf("%d", &tamanhoConjunto);
                printf("Entre com a quantidade de vezes que o processo será repetido: ") ;
                scanf("%d", &qtdRepeticoes);

                long long int *repeticoesCachorro =(long long int *)calloc(sizeof(long long int),tamanhoConjunto);
                long long int *repeticoesHumano =(long long int*)calloc(sizeof(long long int ),tamanhoConjunto);
                long long int  *repeticoesChimpanze =(long long int *)calloc(sizeof(long long int ),tamanhoConjunto);
                
                int total = (int)pow(4, tamanho);

                for (int i=0; i<qtdRepeticoes; i++){ 

                    char** produtoCartesiano = (char**)malloc(sizeof(char*)*total);
                    for(int i = 0; i < total; i++) {
                        produtoCartesiano[i] = (char*)malloc(tamanho + 1);
                    }

                    criaProdutoCartesiano(produtoCartesiano, tamanho);

                    char** conjunto = (char**)malloc(sizeof(char*)*4);
                    for(int i = 0; i < tamanhoConjunto; i++){
                        conjunto[i] = (char*)malloc(2);
                    }
                    
                    if (tamanho == 1 && tamanhoConjunto == total){
                        for (int i = 0; i < tamanhoConjunto; i++)
                        {
                            conjunto[i] = produtoCartesiano[i];
                        }
                    }
                    else {
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
                    }
                    printf("\n\nConjunto = ");
                    for (int i = 0; i < tamanhoConjunto; i++)
                    {
                        printf("%s ", conjunto[i]);
                    }
                
                    for(int i = 0; i < strlen(*arrayChimpanzee); i++)
                    {
                        for(int j = 0; j < tamanhoConjunto; j++)
                        {
                            repeticoesChimpanze[j] += BuscaKMP(conjunto[j], arrayChimpanzee[0]);
                            
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
                            repeticoesHumano[j] += BuscaKMP(conjunto[j], arrayHuman[0]);
                            
                        }
                    }
                    // printf("\nRepeticoes humano: ");
                    // for(int h = 0; h < tamanhoConjunto; h++)
                    // {
                    //     printf("%lld ", repeticoesHumano[h]);
                    // }
                    // printf("\nRepeticoes chimpanze: ");
                    // for(int h = 0; h < tamanhoConjunto; h++)
                    // {
                    //     printf("%lld ", repeticoesChimpanze[h]);
                    // }
                    // printf("\nRepeticoes cachorro: "); 
                    // for(int h = 0; h < tamanhoConjunto; h++)
                    // {
                    //     printf("%lld ", repeticoesCachorro[h]);
                    // }
                    
                    double similaridadeHumanoCachorro = similaridade(repeticoesHumano, repeticoesCachorro, tamanhoConjunto);
                    double similaridadeHumanoChimpanze = similaridade(repeticoesHumano, repeticoesChimpanze, tamanhoConjunto);
                    double similaridadeCachorroChimpanze = similaridade(repeticoesCachorro, repeticoesChimpanze, tamanhoConjunto);

                    printf("\nSimilaridade humano-cachorro = %lf",similaridadeHumanoCachorro);
                    printf("\nSimilaridade humano-chimpaze = %lf",similaridadeHumanoChimpanze);
                    printf("\nSimilaridade cachorro-chimpaze = %lf",similaridadeCachorroChimpanze);
                
                    free(produtoCartesiano);
                    free(conjunto);
                }

                int continuar = 0;
                printf("\n\nDeseja escolher outras valores (1-SIM, 0-NAO): ");
                scanf("%d",&continuar);
                if (continuar != 1){
                    break;
                }
            }

        default:
            break;
        }
    }

    return 0;
}
