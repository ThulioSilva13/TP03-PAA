#include "similaridade.h"

double similaridade(long long int* A, long long int* B, int tamanho){

    long long int somatorioProduto = 0;
    for (int i=0; i<tamanho; i++){
        somatorioProduto += A[i]*B[i];
    }
    //printf("\nsomatorioProduto %lld\n",somatorioProduto);


    double somatorioQuadradoA = 0;
    double somatorioQuadradoB = 0;

    for (int i =0; i<tamanho; i++){
        somatorioQuadradoA += pow(A[i],2);
        somatorioQuadradoB += pow(B[i],2);
    }
    //printf("\nsomatorioQuadradoA %lf\n",somatorioQuadradoA);
    //printf("\nsomatorioQuadradoB %lf\n",somatorioQuadradoB);

    double raizA = sqrt(somatorioQuadradoA);
    double raizB = sqrt(somatorioQuadradoB);

    //printf("\nraizA %lf\n",raizA);
    //printf("\nraizB %lf\n",raizB);

    double similaridade = somatorioProduto / (raizA * raizB);
    //printf("\nsimilaridade %lf\n",similaridade);

    return similaridade;
}