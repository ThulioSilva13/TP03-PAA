#include "simulacao.h"

double simulacao (char ** produtoCartesiano, char **arrayA, char **arrayB,int tamanho, int total, int tamanhoConjunto, int qtdRepeticoes) {
    
    long long int* repeticoesA =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);
    long long int* repeticoesB =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);

    double* similaridades =(double*)malloc(sizeof(double)*qtdRepeticoes);

    for (int i=0; i<qtdRepeticoes; i++){ 

        char** aux = (char**)malloc(sizeof(char*)*total);
        for(int i = 0; i < total; i++) {
            aux[i] = (char*)malloc(tamanho + 1);
        }

        for (int i = 0; i < total; i++){
            aux[i] = produtoCartesiano[i];
        }
        
        char** conjunto = (char**)malloc(sizeof(char*)*4);
        for (int i = 0; i < tamanhoConjunto; i++){
            conjunto[i] = (char*)malloc(2);
        }
        
        if (tamanho == 1 && tamanhoConjunto == total){
            for (int i = 0; i < tamanhoConjunto; i++)
            {
                conjunto[i] = aux[i];
            }
        }
        else {
            for (int i = 0; i < tamanhoConjunto; i++)
            {
                int aleatorio = rand() % (total-1);
                if(strcmp(aux[aleatorio], "0") != 0)
                {
                    conjunto[i] = aux[aleatorio];
                    aux[aleatorio] = "0";
                }
                else
                {
                    i--;
                }
            }
        }
        
        printf("\n\n    Conjunto = ");
        for (int i = 0; i < tamanhoConjunto; i++) {
            printf("%s ", conjunto[i]);
        }

        for(int i = 0; i < strlen(*arrayA); i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesA[j] += BuscaKMP(conjunto[j], arrayA[i]);    
            }
        }

        for(int i = 0; i < strlen(*arrayB); i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesB[j] += BuscaKMP(conjunto[j], arrayB[i]);   
            }
        }

        printf("\n    Repeticoes A: ");
        for(int h = 0; h < tamanhoConjunto; h++)
        {
            printf("%lld ", repeticoesA[h]);
        }
        printf("\n    Repeticoes B: ");
        for(int h = 0; h < tamanhoConjunto; h++)
        {
            printf("%lld ", repeticoesB[h]);
        }

        similaridades[i] = similaridade(repeticoesA, repeticoesB, tamanhoConjunto);

        free(aux);
        free(conjunto);
    }

    printf("\n\n    Similiaridades: "); 
    double somaTotal = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaTotal += similaridades[i];
        printf("%lf ",similaridades[i]);
    }

    double mediaSimilaridadeAB = somaTotal/qtdRepeticoes;
    //printf("\n Similaridade %lf",mediaSimilaridadeAB);
    return mediaSimilaridadeAB;
}