#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
1. Defina uma funcao int contaVogais (char *s) que conta quantas vogais uma string tem.
*/

int isVowel(char s) {
    char vogais[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    int size = strlen(vogais);

    for(int i = 0; i < size; i++) {
        if(s == vogais[i]) return 1;
    }

    return 0;
}


int contaVogais (char *s) {
    int size = strlen(s);
    int count = 0;

    for(int i = 0; i < size; i++) {
        if(isVowel(s[i]) == 1) {
            count++;
        }
    }

    return count;
}

/*Resolvido para funcionar no codeboard*/


/*
Defina uma funcao int retiraVogaisRep (char *s) que remove de uma string todas as repe-
ticoes consecutivas de vogais. A funcao devera retornar o numero de vogais removidas. Por e-
xemplo, se a string a == "Estaa e umaa string coom duuuplicadoos", depois de invocarmos
retiraVogaisRep a, a string a devera ter o valor "Esta e uma string com duplicados".
• Para evitar fazer muitos deslocamentos de caracteres, apresente uma definicao que usa um
array auxiliar onde a string resultante sera construıda. No final tera que copiar essa string
de volta para o array argumento.
• Altere a funcao que definiu acima de forma a nao precisar de usar o array auxiliar.
*/

/*Com array auxiliar temp*/

int retiraVogaisRep2 (char *s) {

    int size = strlen(s);
    int j = 0;
    int count = 0;
    char temp[size];


    for(int i = 0; i < size; i++) {
        if(isVowel(s[i]) == 1) {
            temp[j] = s[i];
            j++;
            int k = i+1;
            while(s[i] == s[k]) {
                count++;
                k++;
                i++;
            }
            
        } else {
            temp[j] = s[i];
            j++;
        }
    }
    
    int size2 = strlen(temp);
   

    for(int n = 0; n < size2; n++) {
        s[n] = temp[n];
        
    }

    if(count < size) {
        s[size - count] = '\0';
    }
 

    return count;

 
}

/*Sem array auxiliar*/

int retiraVogaisRep (char *s) {
    int size = strlen(s);
    int count = 0;


    for(int i = 0; i < size; i++) {
        if(isVowel(s[i]) == 1) {
            int j = i+1;
            while(s[j] == s[i]) {
                s[i] = s[j];
                for(int k = j; k < size; k++) {
                    s[k] = s[k+1];
                }
                
                count++;
                
            }
        }
    }

    if(count < size) {
        s[size-count] = '\0';
    }

    return count;
}






/*
3. Defina uma funcao int duplicaVogais (char *s) que duplica todas as vogais de uma string.
A funcao deve retornar o numero de caracteres acrescentados. Assuma que o array recebido
como argumento tem capacidade para armazenar o resultado pretendido.
• Mais uma vez, e de forma a evitar muitos deslocamentos de caracteres, defina esta funcao
usando um array auxiliar para construir a string resultante.
• Apresente ainda uma definicao alternativa onde nao seja de facto necessario usar o dito
array auxiliar.
*/

/*Quando tem caracteres duplicados elimina os duplicados e duplica 1 vez, porquê? Não sei*/

int duplicaVogais (char *s) {
    int count = 0;
    int size = strlen(s);
    int k = contaVogais(s);
    int size2 = size + k;
    char temp[size2];
    int j = 0;
    


    for(int i = 0; i < size; i++) {
        temp[j] = s[i];

        if(isVowel (s[i])) {
            
            temp[j+1] = s[i];
            j+=2;
            count++;
        } else {
            j++;
        }

    }


    for(int i = 0; i < size2; i++) {
        s[i] = temp[i];
    }
    s[size2] = '\0';

    return count;
} 















int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1); 
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);

    printf ("\nFim dos testes\n");

    return 0;
} 

