#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./src/lerArquivo.h"
#include "./src/produtoCartesiano.h"
#include "./src/simulacao.h"


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

                printf("\n-----------------------------------------------------------------\n");
                printf("Entre com o tamanho de cada elemento do conjunto: ") ;
                scanf("%d", &tamanho);
                printf("Entre com a quantidade de elementos do conjunto: ") ;
                scanf("%d", &tamanhoConjunto);
                printf("Entre com a quantidade de vezes que o processo será repetido: ") ;
                scanf("%d", &qtdRepeticoes);

                int total = (int)pow(4, tamanho);
                if (tamanhoConjunto > total){
                    tamanhoConjunto = total;
                }
                
                char** produtoCartesiano = (char**)malloc(sizeof(char*)*total);
                for(int i = 0; i < total; i++) {
                    produtoCartesiano[i] = (char*)malloc(tamanho + 1);
                }
                criaProdutoCartesiano(produtoCartesiano, tamanho);

                printf("\n\n- Similaridades humano-chimpanze");
                double similaridadeHumanoChimpanze = simulacao(produtoCartesiano,arrayHuman, arrayChimpanzee, tamanho, total, tamanhoConjunto, qtdRepeticoes);

                printf("\n\n- Similaridades humano-cachorro");
                double similaridadeHumanoCachorro = simulacao(produtoCartesiano,arrayHuman, arrayDog, tamanho, total, tamanhoConjunto, qtdRepeticoes);
                
                printf("\n\n- Similaridades cachorro-chimpanze");
                double similaridadeCachorroChimpanze = simulacao(produtoCartesiano,arrayChimpanzee, arrayDog, tamanho, total, tamanhoConjunto, qtdRepeticoes);

                printf("\n\n- Similaridade humano-chimpaze =   %lf",similaridadeHumanoChimpanze);
                printf("\n- Similaridade humano-cachorro =   %lf",similaridadeHumanoCachorro);
                printf("\n- Similaridade cachorro-chimpaze = %lf",similaridadeCachorroChimpanze);
                printf("\n-----------------------------------------------------------------\n");

                int continuar = 0;
                printf("\nDeseja escolher outras valores (1-SIM, 0-NAO): ");
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
