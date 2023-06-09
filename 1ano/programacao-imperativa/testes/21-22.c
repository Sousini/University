#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*1. Implemente a função int nesimo(int a[], int N, int i) que dado um array de
tamanho N > 0 e um inteiro 0 < i <= N devolve o i-ésimo menor elemento do array.
Por exemplo, se i == 1 a função deve retornar o menor elemento do array*/


int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*) b);
}

int nesimo(int a[], int N, int i) {

    qsort(a, N, sizeof(int), compare);

    return a[i-1];

}


/*Implemente a função LInt removeMaiores(LInt l, int x) que remove de uma
lista ordenada l todos os elementos maiores que x, devolvendo a lista resultante.
Considere a definição usual do tipo LInt.*/


typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

void freeLInt(LInt l) {
    LInt *aux;

    while(l != NULL) {
        aux = l; 
        l = l -> prox;
        free(aux);
    }
}


LInt removeMaiores(LInt l, int x) {

    while(l != NULL) {
        if(l -> valor > x) {
            
            freeLInt(l);
            l = l -> prox;
        } else {
            l = l -> prox;
        }
    }

    return l;
}



/*3. Implemente a função LInt caminho(ABin a, int x) que, dada uma árvore binária
de procura a e um valor x, devolve uma lista com todos os valores desde a raiz até x
(inclusivé). Se x não existir na árvore, deve devolver NULL. Considere a definição usual
do tipo ABin (o tipo LInt foi dado na questão anterior).*/

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;


LInt caminho(ABin a, int x) {

    if (a == NULL) {
        return NULL;
    }

    if (a->valor == x) {
        LInt r = malloc(sizeof(struct LInt_nodo));
        r->valor = x;
        r->prox = NULL;
        return r;
    }

    if (a->valor > x) {
        LInt caminho_esq = caminho(a->esq, x);
        if (caminho_esq != NULL) {
            LInt r = malloc(sizeof(struct LInt_nodo));
            r->valor = a->valor;
            r->prox = caminho_esq;
            return r;
        }
    }

    if (a->valor < x) {
        LInt caminho_dir = caminho(a->dir, x);
        if (caminho_dir != NULL) {
            LInt r = malloc(sizeof(struct LInt_nodo));
            r->valor = a->valor;
            r->prox = caminho_dir;
            return r;
        }
    }

    return NULL;


}


/*4. Implemente a função void inc(char s[]) que, dada uma uma string s com um
número em decimal, incrementa esse número numa unidade. Assuma que a string tem
espaço suficiente para armazenar o número resultante. Por exemplo, se a string for
"123" deverá ser modificada para "124". Se for "199" deverá ser modificada para
"200".*/



void inc(char s[]) {

    int size = strlen(s);
    int temp[size];


    for(int i = 0; i < size; i++) {
        temp[i] = s[i] -'0';

    }



    temp[size]++;

    char res[size];
    sprintf(res, "%d", );
    printf("%s", res);
}







int main() {

    char *s = "123";

    inc(s);
    return 0;
}