#include <stdio.h>
#include <stdlib.h>




/*
1. Implemente a função int perfeito(int x) que testa se um número inteiro é perfeito,
isto é, se é igual à soma dos seus divisores próprios. Por exemplo, 28 é um número
perfeito, uma vez que os seus divisores próprios são 1, 2, 4, 7 e 14 (1+2+4+7+14==28).
*/

int perfeito(int x) {
    int y = x/2;
    int r = 0;

    for(int i = 1; i <= y; i++) {
        if((x%i) == 0) {
            r+=i;
        }
    }
    
    if(r==x) return (-1); //0 se for perfeito, -1 se não for

    return 0;

}


/*
2. Implemente a função void ordena(Ponto pos[], int N) que dado um array com N
pontos ordena esses pontos por ordem crescente da distância à origem. Por exemplo
se o array for {{3,3},{2,1},{-1,0}} depois de ordenado deverá ficar com o
conteúdo {{-1,0},{2,1},{3,3}}. O tipo Ponto é definido da seguinte forma (note
que as coordenadas dos pontos são números inteiros).
*/

typedef struct {
    int x,y;
} Ponto;



void ordena(Ponto pos[], int N) {

    int i = 0;
    

    while(i < N - 1) {
        int xi = pos[i].x;
        int yi = pos[i].y;

        int di = (xi*xi) + (yi*yi);
        int j = 1;

        while(j < N) {
            int xj = pos[j].x;
            int yj = pos[j].y;

            int dj = (xj*xj) + (yj*yj);

            if(di > dj) {
                Ponto temp = pos[i];
                pos[i] = pos[j];
                pos[j] = temp;
                
            }

            j++;
        }
        i++;
    }

}









/*
3. Apresente uma definição da função int depth(ABin a, int x) que devolve o
menor nível a que um elemento x se encontra na árvore (ou -1 se x não se encontra
na árvore). Considere a definição usual do tipo ABin. Considere ainda que a raiz se
encontra no nível 0.
*/


typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} *ABin;


int depth(ABin a, int x) {
    

    if (a == NULL) {
        return (-1);
    }

    if (a->valor == x) 
        return 0;
    

    int esq = depth(a->esq, x);
    int dir = depth(a->dir, x);

    if (esq == -1 && dir == -1) {
        return -1; 
    } else if (esq == -1) {
        return dir + 1; 
    } else if (dir == -1) {
        return esq + 1; 
    } else {
        return esq < dir ? esq + 1 : dir + 1; 
    }
    

} 



/*
4. Implemente a função int wordle(char secreta[], char tentativa[]) que dada
uma palavra secreta que se pretende descobrir e uma tentativa com o mesmo tamanho
devolve o número de caracteres na palavra tentativa em que o utilizador já acertou.
Ambas as palavras só contêm letras minúsculas. A função deve também modificar a
tentativa substituindo todas as letras que não tem correspondente na palavra secreta
por um '*' e convertendo para maiúscula as letras que estão na posição certa. Por
exemplo se a palavra secreta for "laranja" e a tentativa for "cerejas" a função deve
devolver 1 e alterar a tentativa para "**R*ja*" (apenas o 'r' está na posição certa e
os caracteres 'j' e 'a' aparecem no segredo noutras posições). Se a tentativa for
"bananas" a função deve devolver 3 e alterar a tentativa para "*A*ANa*".
*/



int wordle(char secreta[], char tentativa[]) {

    int count = 0;
    int flag = 1;


    for(int i = 0; secreta[i] != '\0'; i++) {
        if(secreta[i] == tentativa[i]) {
            tentativa[i] = secreta[i] + 'A' - 'a';
            count++;
            flag = 0;
        } else {
            for (int j = 0; secreta[j] != '\0'; j++) {
                if(secreta[j] == tentativa[i]) {
                    tentativa[i];
                    flag = 0;
                }
            }
        } 
        
        if(flag) {
            tentativa[i] = '*';
            
        }
        flag = 1;

    }


/*
aparece mais letras do que as que a secreta tem (BUG)
*/
    return count;
}





/*
5. Implemente a função LInt periodica(char s[]) que dada uma string com uma
sequência infinita periódica de dígitos constrói uma lista (circular) com esses dígitos.
Assuma que a parte da sequência que se repete indefinidamente está representada
entre parênteses e aparece sempre no final da string. Assuma também a definição
usual do tipo LInt. Por exemplo, se a string for "34(56)" deverá ser construída a
seguinte lista.
*/


// Pode não estar certa a resolucao

typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;



LInt periodica(char s[]) {

    LInt l = malloc(sizeof(struct lint_nodo));
    LInt ant = NULL;
    LInt inicio = NULL;
    int c = 0;

    for(int i = 0; s[i] != '('; i++) {
        if(inicio == NULL) {
            l->valor = atoi(s[i]);
            l->prox = NULL;
            inicio = l;
        } else {
            ant = l;
            l->valor = atoi(s[i]);
            l->prox = NULL;
            ant->prox = l;
        }
        c = i;
    }

    LInt primeiro = NULL;
    l->prox = primeiro;
    

    for(int i = c; s[i] != ')'; i++) {
        if(primeiro == NULL) {
            primeiro->valor = atoi(s[i]);
            primeiro->prox = NULL;
            l = primeiro;

        } else {
            ant = l;
            l->valor = atoi(s[i]);
            l->prox = NULL;
            ant->prox = l;
        }
    }
    l->prox = primeiro;

    l = inicio;
    return l;
}























int main() {

printf ("\nQuestão 5\n");
   LInt lista;
   char string[20] = "123(456)";
   printf ("%s --> ", string);
   lista = periodica_sol ("123(456)");
   unfoldList (lista, 14); // para ver se funcionou!
   unperiodica (lista,string);
   printf (" --> %s\n", string);
    

    return 0;
}