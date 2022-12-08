#include "produtoCartesiano.h"
#define MAXLENGTH 10000

void CalculaPlanoCartesiano(int tamanho)
{

	char A = 'A';
	char C = 'C';
	char T = 'T';
	char G = 'G';

	char produtoCartesiano[pow(tamanho,4)];
	
	for(int i = 0; i < tamanho; i++)
	{
		strcat(A, produtoCartesiano);
		
	}
	/*

	[A C T G]

	"AA" "AC" "AT" "AG"  "CA" "CC" "CT" "CG" 
	
	AAA AAC AAT AAG ACA ACC ACT ACG ...

	*/
}

void permutacao()
{
	int *num ;
    /* input é a string de entrada, e str
     * receberá cada permutação.
     */ 
    char input[MAXLENGTH] = "ATCG", str[MAXLENGTH] ;
    int n, r, i, j, k ;

    printf("Entre com o conjunto inicial: ") ;
    scanf("%s", input) ;

    printf("Entre com o r: ") ;
    scanf("%d", &r) ;

    /* Aqui elimina-se caracteres repetidos na entrada.
     * Esse procedimento não faz parte do algoritmo, e
     * só é feito por questões práticas.
     */
    n = strlen(input) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < n; i++ ) {
        if ( strchr(str, input[i]) == NULL ) {
            str[j] = input[i] ;
            j++ ;
            str[j] = 0 ;
        }
    }
    strcpy(input, str) ;
    n = strlen(input) ;

    /* Cria o nosso número. Ele é um vetor de
     * r+1 posições, sendo que a última é 
     * reservada para indicar quando todos os
     * números de tamanho r foram gerados. */
    num = (int *) calloc( (r+1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return -1;
    }

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[r] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = r-1; j < r; j++ ) {
                str[k] = input[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[r] = 0 ;
            printf("%s\n", str) ;

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < r; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }
}

