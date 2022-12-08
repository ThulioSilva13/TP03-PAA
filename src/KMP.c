#include "KMP.h"
#define MAXLENGTH 10000

int BuscaKMP(char *padrao, char *texto)
{
	int contadorRepeticoes;
	int tamanhoPadrao = strlen(padrao);
	int tamanhoTexto = strlen(texto);

	int *prefixoMaisLongo = (int*)malloc(tamanhoPadrao*sizeof(int));
	int j = 0;

	CalculaPrefixoMaisLongo(padrao, tamanhoPadrao, prefixoMaisLongo);
	
	int i = 0;
	while(i < tamanhoTexto)
	{
		if(padrao[j] == texto[i])
		{
			j++;
			i++;
		}
		if(j == tamanhoPadrao)
		{
			contadorRepeticoes++;
			//printf("Padrão encontrado no índice %d\n",i - j);
			j = prefixoMaisLongo[j-1];
		}
		else if(padrao[j] != texto[i])
		{
			if(j != 0)
				j = prefixoMaisLongo[j-1];
			else
				i++;
		}
	}
	//printf("\no padrão foi encontrado %d vezes", contadorRepeticoes);
	free(prefixoMaisLongo);
	return contadorRepeticoes; // return
}
void CalculaPrefixoMaisLongo(char *padrao, int tamanhoPadrao, int *prefixoMaisLongo)
{
	int len = 0;	//lenght of previous longest prefix suffix
	int i ;
	
	prefixoMaisLongo[0] = 0 ;	//prefixoMaisLongo[0] is always 0
	i = 1;

	while(i <  tamanhoPadrao)	//loop calculates prefixoMaisLongo[i] for i = 1 to M-1
	{
		if(padrao[i] == padrao[len])
		{
			len++;
			prefixoMaisLongo[i] = len;
			i++;
		}
		else	//padrao[i] != padrao[len]
		{
			if(len != 0)
			{
				//this is tricky
				//consider the example AAACAAAA and i =7
				len = prefixoMaisLongo[len - 1];
				//we donot increment i here
			}
			else	//if len == 0
			{
				prefixoMaisLongo[i] = 0;
				i++;
			}
		}
	}
}

