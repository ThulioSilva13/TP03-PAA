/* C Program for Bad Character Heuristic of Boyer
   Moore String Matching Algorithm */
# include <limits.h>
# include <string.h>
# include <stdio.h>
# define NO_OF_CHARS 256
 
int max (int a, int b) { 
   return (a > b)? a: b; 
}
 
void badCharHeuristic( char *str, int size,
                        int badchar[NO_OF_CHARS])
{
    int i;
 
    for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;

    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}
 
int searchBM(char *padrao,char *txt)
{
    int tamanhoPadrao = strlen(padrao);
    int tamanhoTexto = strlen(txt);
    int count = 0;
 
    int badchar[NO_OF_CHARS];

    badCharHeuristic(padrao, tamanhoPadrao, badchar);
 
    int s = 0; 

    while(s <= (tamanhoTexto - tamanhoPadrao ))
    {
        int j = tamanhoPadrao -1;
 
        while(j >= 0 && padrao[j] == txt[s+j])
            j--;
            
         if (j < 0)
         {
               count++;
               s += (s+tamanhoPadrao  < tamanhoTexto)? tamanhoPadrao-badchar[txt[s+tamanhoPadrao]] : 1;  
         }  
         else{
            s += max(1, j - badchar[txt[s+j]]);
         }
                     
    }
    return count;
}
