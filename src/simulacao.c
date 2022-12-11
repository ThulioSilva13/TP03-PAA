#include "simulacao.h"
#include <time.h>

void simulacaoComKMP(char ** produtoCartesiano, char **arrayHumano, char **arrayChimpanze, char **arrayCachorro, int tamanho, int total, int tamanhoConjunto, int qtdRepeticoes) {
    clock_t inicioKMP = clock();
    double tempoKMP = 0.0;
    long long int* repeticoesHumano =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);
    long long int* repeticoesChimpanze =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);
    long long int* repeticoesCachorro =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);

    double* similaridadesHumanoChimpanze =(double*)malloc(sizeof(double)*qtdRepeticoes);
    double* similaridadesHumanoCachorro =(double*)malloc(sizeof(double)*qtdRepeticoes);
    double* similaridadesCachorroChimpanze =(double*)malloc(sizeof(double)*qtdRepeticoes);

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
        

        for(int i = 0; i < 4320; i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesHumano[j] += BuscaKMP(conjunto[j], arrayHumano[i]);    
            }
        }

        for(int i = 0; i < 1682; i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesChimpanze[j] += BuscaKMP(conjunto[j], arrayChimpanze[i]);   
            }
        }

         for(int i = 0; i < 820; i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesCachorro[j] += BuscaKMP(conjunto[j], arrayCachorro[i]);   
            }
        }

        similaridadesHumanoCachorro[i] = similaridade(repeticoesHumano, repeticoesCachorro, tamanhoConjunto);
        similaridadesHumanoChimpanze[i] = similaridade(repeticoesHumano, repeticoesChimpanze, tamanhoConjunto);
        similaridadesCachorroChimpanze[i] = similaridade(repeticoesCachorro, repeticoesChimpanze, tamanhoConjunto);

        free(aux);
        free(conjunto);
    }

    double somaHCh = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaHCh += similaridadesHumanoChimpanze[i];
    }

    double somaHCa = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaHCa += similaridadesHumanoCachorro[i];
    }

    double somaCC = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaCC += similaridadesCachorroChimpanze[i];
    }

    double mediaSimilaridadeHCh = somaHCh/qtdRepeticoes;
    double mediaSimilaridadeHCa = somaHCa/qtdRepeticoes;
    double mediaSimilaridadeCC = somaCC/qtdRepeticoes;


    clock_t fimKMP = clock();
    tempoKMP += (double)(fimKMP - inicioKMP) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execução do algoritmo KMP: %f", tempoKMP);
    printf("\n- Similaridade humano-chimpanze =  %lf",mediaSimilaridadeHCh );
    printf("\n- Similaridade humano-cachorro =   %lf",mediaSimilaridadeHCa);
    printf("\n- Similaridade cachorro-chimpanze = %lf",mediaSimilaridadeCC);

}


void simulacaoComBM(char ** produtoCartesiano, char **arrayHumano, char **arrayChimpanze, char **arrayCachorro, int tamanho, int total, int tamanhoConjunto, int qtdRepeticoes) {
    clock_t inicioBM = clock();
    double tempoBM = 0.0;
    long long int* repeticoesHumano =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);
    long long int* repeticoesChimpanze =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);
    long long int* repeticoesCachorro =(long long int*)calloc(sizeof(long long int), tamanhoConjunto);

    double* similaridadesHumanoChimpanze =(double*)malloc(sizeof(double)*qtdRepeticoes);
    double* similaridadesHumanoCachorro =(double*)malloc(sizeof(double)*qtdRepeticoes);
    double* similaridadesCachorroChimpanze =(double*)malloc(sizeof(double)*qtdRepeticoes);

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
        
        for(int i = 0; i < 4320; i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesHumano[j] += searchBM(conjunto[j], arrayHumano[i]);    
            }
        }

        for(int i = 0; i < 1682; i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesChimpanze[j] += searchBM(conjunto[j], arrayChimpanze[i]);   
            }
        }

         for(int i = 0; i < 820; i++) {
            for(int j = 0; j < tamanhoConjunto; j++) {
                repeticoesCachorro[j] += searchBM(conjunto[j], arrayCachorro[i]);   
            }
        }


        similaridadesHumanoCachorro[i] = similaridade(repeticoesHumano, repeticoesCachorro, tamanhoConjunto);
        similaridadesHumanoChimpanze[i] = similaridade(repeticoesHumano, repeticoesChimpanze, tamanhoConjunto);
        similaridadesCachorroChimpanze[i] = similaridade(repeticoesCachorro, repeticoesChimpanze, tamanhoConjunto);

        free(aux);
        free(conjunto);
    }

    double somaHCh = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaHCh += similaridadesHumanoChimpanze[i];
    }
 
    double somaHCa = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaHCa += similaridadesHumanoCachorro[i];
    }
 
    double somaCC = 0;
    for (int i=0; i<qtdRepeticoes; i++) { 
        somaCC += similaridadesCachorroChimpanze[i];
    }

    double mediaSimilaridadeHCh = somaHCh/qtdRepeticoes;
    double mediaSimilaridadeHCa = somaHCa/qtdRepeticoes;
    double mediaSimilaridadeCC = somaCC/qtdRepeticoes;
    clock_t fimBM = clock();
    tempoBM += (double)(fimBM - inicioBM) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execução do algoritmo BM: %f", tempoBM);
    printf("\n- Similaridade humano-chimpanze =  %lf",mediaSimilaridadeHCh );
    printf("\n- Similaridade humano-cachorro =   %lf",mediaSimilaridadeHCa);
    printf("\n- Similaridade cachorro-chimpanze = %lf",mediaSimilaridadeCC);

}