#include "produtoCartesiano.h"
#include <math.h>
#define MAXLENGTH 10000

void criaProdutoCartesiano(char** produtoCartesiano, int tamanho)
{
    char* criado = (char*)malloc(tamanho + 1);
    int controle = 0, repeticoes = 0;
    criaRecursivo(produtoCartesiano, &controle, criado, repeticoes, tamanho);
    free(criado);

}
void criaRecursivo(char **produtoCartesiano, int* controle, char* criado, int repeticoes, int tamanho)
{
    char bases [] = {'A', 'C', 'T', 'G'};
    if(repeticoes == tamanho)
    {
        criado[tamanho] = '\0';
        strcpy(produtoCartesiano[*controle], criado);
        *controle +=1;
        return;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            criado[repeticoes] = bases[i];
            criaRecursivo(produtoCartesiano, controle, criado, repeticoes+1, tamanho);
        }
    }
}