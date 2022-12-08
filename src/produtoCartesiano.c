#include "produtoCartesiano.h"
#include <math.h>
#define MAXLENGTH 10000

void permutacao(int tamanho)
{
	int *num ;
    /* padrao é a string de entrada, e str
     * receberá cada permutação.
     */ 
    char padrao[] = {"ACTG"};
    char str[MAXLENGTH]; 
    char resultadoProduto[(int)(pow(tamanho,4))+1];
    int n, i, j, k;
    int count = 0;

    n = strlen(padrao);
    /* Cria o nosso número. Ele é um vetor de
     * r+1 posições, sendo que a última é 
     * reservada para indicar quando todos os
     * números de tamanho r foram gerados. */
    num = (int *) calloc( (tamanho+1), sizeof(int)) ;

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[tamanho] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            printf("\n%d",count);
            /* processo de mapeamento. */
            for ( j = 0, k = tamanho-1; j < tamanho; j++ ) {
                str[k] = padrao[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            
            str[tamanho] = 0 ;
            //printf("%s\n", str);
            strcpy(resultadoProduto,str);
            count ++;

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < tamanho; i++ ) {
            if ( num[i] == n ) {
                 num[i] = 0 ;
                 num[i+1]++ ;
            }
        }
    }

    printf("tam= %d",(int)(pow(tamanho,4))+1);

    for (int h = 0; h<(int)(pow(tamanho,4))+1;h++){
        printf("sequencia : %c\n",resultadoProduto[h]);
    }
    printf("\n");
}

