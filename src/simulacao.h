#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "BM.h"
#include "KMP.h"
#include "similaridade.h"


void simulacaoComKMP(char ** produtoCartesiano, char **arrayHumano, char **arrayChimpanze, char **arrayCachorro, int tamanho, int total, int tamanhoConjunto, int qtdRepeticoes);
void simulacaoComBM(char ** produtoCartesiano, char **arrayHumano, char **arrayChimpanze, char **arrayCachorro, int tamanho, int total, int tamanhoConjunto, int qtdRepeticoes);