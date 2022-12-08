#include "produtoCartesiano.h"
#include <math.h>
#define MAXLENGTH 10000

void permutacao(int tamanho)
{
	int *qtd_caracteres;
    int tam = (int)(pow(4,tamanho));

    char base[] = {"ACTG"};
    char combinacoes[tamanho]; 
    char** resultadoProduto;
    resultadoProduto = (char**) malloc (sizeof(char*) * tam);
    for (int h=0; h<tam;h++){
        resultadoProduto[h] = " ";
    }

    int i, j, posicao;
    int count = 0;

    int tam_base = strlen(base);

    qtd_caracteres = (int *) calloc( (tamanho+1), sizeof(int)) ;

    //para cada caractere da base 
    while ( qtd_caracteres[tamanho] == 0 ) {
        
        for ( i = 0; i < tam_base; i++ ) {

            /* mapeamento */
            for ( j = 0, posicao = tamanho-1; j < tamanho; j++ ) {
                combinacoes[posicao] = base[qtd_caracteres[j]] ;
                printf("\ni=%d ,j=%d, %c", i,j, combinacoes[posicao] );
                posicao-- ;
            }
            /* Mostra o resultado. */
            combinacoes[tamanho] = 0 ;
            
            resultadoProduto[count] = combinacoes;
            //printf("count: %d",count);
            //printf("%s\n", combinacoes) ;
            printf("\n%s\n", resultadoProduto[count]);
            count ++;
            /* incrementa o algarismo menos significativo. */
            qtd_caracteres[0]++ ;
        }
        
        printf("teste: %s\n", resultadoProduto[0]);
        
        //vai pro proximo caractere
        for ( i = 0; i < tamanho; i++ ) {
            if ( qtd_caracteres[i] == tam_base ) {
                 qtd_caracteres[i] = 0 ;
                 qtd_caracteres[i+1]++ ;
            }
        }
    }

    for (int h=0; h<tam;h++){
        //printf("h:%d\n", h);
        printf("%s ",resultadoProduto[h]);
    }
    printf("\n");
}
