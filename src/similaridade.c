#include "similaridade.h"

double similaridade(long long int* A, long long int* B, int tamanho){
    long long int somatorioProduto = 0;
    
    for (int i=0; i<tamanho; i++){
        somatorioProduto += A[i]*B[i];
    }

    double somatorioQuadradoA = 0;
    double somatorioQuadradoB = 0;

    for (int i =0; i<tamanho; i++){
        somatorioQuadradoA += pow(A[i],2);
        somatorioQuadradoB += pow(B[i],2);
    }

    double raizA = sqrt(somatorioQuadradoA);
    double raizB = sqrt(somatorioQuadradoB);

    double similaridade = somatorioProduto / (raizA * raizB);

    return similaridade;
}