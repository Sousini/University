#include <stdio.h>
#include <stdlib.h>


// 1

int sumhtpo (int n) {
    int i, max = 0;

    for (i = 1; n != 1; i++) {
        if (n > max) max = n;

        n = (n%2 == 0) ? n/2 : 1+(3*n);
    }

    return (i < 100) ? -1 : max;
}


// 2


int moda(int v[], int N, int *m) {

    int freq[N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(v[i] == v[j]) {
                freq[i]++;
            } else {
                freq[i] = 1;
            }
        }
    }

    int maior = 0;
    int c;

    for(int i = 0; i < N; i++) {
        if(freq[i] > maior) {
            maior = freq[i];
            c = i;
        }
    }

    *m = v[c];

    for(int i = 0; i < N; i++) {
        if(maior == freq[i] || maior == 0) return 0;
    }

    return maior;
}




// 3

int procura (LInt *l, int x) {
    int r = 0;
    LInt inicio = *l;
    LInt ant = NULL;

    while(*l) {
        if((*l)->valor != x) {
            ant = *l;
            *l = (*l)->prox;
        } else {
            ant->prox = (*l)->prox;
            (*l)->prox = inicio;
            r = 1;

        }
    }

    return r;
}


// 4

typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;

int freeAB(ABin a) {
    
    if(a==NULL) return 0;

    int ret = freeAB(a->esq) + freeAB(a->dir) + 1;
    free(a);

    return ret;

}


// 5

void caminho (ABin a) {
    if(a == NULL || a->pai == NULL) return;

    caminho(a->pai);

    if(a->pai->esq == a) {
        printf("esq ");
    } else {
        printf("dir ");
    }
}