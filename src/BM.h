#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define NO_OF_CHARS 256
void badCharHeuristic( char *str, int size,int badchar[NO_OF_CHARS]);
int max (int a, int b);
int searchBM(char *padrao,char *txt);