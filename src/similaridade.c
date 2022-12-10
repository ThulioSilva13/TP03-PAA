#include "similaridade.h"

double similaridade(long long int* A, long long int* B, int tamanho){
//int main() {
    //int tamanho = 1;
    //Repeticoes humano: 19913 16170 21075 13528 
    //Repeticoes chimpanze: 24668 19426 22938 17677 
    //Repeticoes cachorro: 25890 20766 25518 19763
    //long long int A[] ={255395};
    //long long int B[] ={77213};

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
    //return 0;
}