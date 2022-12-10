#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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

    double tempo_HumanoCachorro = 0;
    double tempo_HumanoChimpanze = 0;
    double tempo_CachorroChimpanze = 0;
    clock_t tempo_simulacao;
    
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
                
                // -> calcular similaridade entre Humano e Cachorro
                tempo_simulacao = clock(); //tempo inicial
                double similaridadeHumanoCachorro = simulacao(produtoCartesiano,arrayHuman, arrayDog, tamanho, total, tamanhoConjunto, qtdRepeticoes);
                tempo_simulacao = clock() - tempo_simulacao; //tempo final
                tempo_HumanoCachorro = ((double)tempo_simulacao)/(CLOCKS_PER_SEC);

                // -> calcular similaridade entre Humano e Chimpanze
                tempo_simulacao = clock(); //tempo inicial
                double similaridadeHumanoChimpanze = simulacao(produtoCartesiano,arrayHuman, arrayChimpanzee, tamanho, total, tamanhoConjunto, qtdRepeticoes);
                tempo_simulacao = clock() - tempo_simulacao; //tempo final
                tempo_HumanoChimpanze = ((double)tempo_simulacao)/(CLOCKS_PER_SEC);
                
                // -> calcular similaridade entre Cachorro e Chimpanze
                tempo_simulacao = clock(); //tempo inicial
                double similaridadeCachorroChimpanze = simulacao(produtoCartesiano,arrayChimpanzee, arrayDog, tamanho, total, tamanhoConjunto, qtdRepeticoes);
                tempo_simulacao = clock() - tempo_simulacao; //tempo final
                tempo_CachorroChimpanze = ((double)tempo_simulacao)/(CLOCKS_PER_SEC);

                printf("\n- Similaridade humano-cachorro =   %lf | %lfs",similaridadeHumanoCachorro,tempo_HumanoCachorro);
                printf("\n- Similaridade humano-chimpaze =   %lf | %lfs",similaridadeHumanoChimpanze, tempo_HumanoChimpanze);
                printf("\n- Similaridade cachorro-chimpaze = %lf | %lfs",similaridadeCachorroChimpanze, tempo_CachorroChimpanze);
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
