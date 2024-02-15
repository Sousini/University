#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;


/*
1. void libertaLista (Palavras) que liberta todo o espaco (da heap) ocupado pela lista de
palavras.
*/

void libertaLista (Palavras l) {

    if(l != NULL) {
        libertaLista(l->prox);
        free(l);
    }
}



/*
2. Lista quantasP (Palavras l) que calcula quantas palavras (diferentes) existem armazenadas.
*/

int quantasP (Palavras l) {
    int count = 0;


    while(l) {
        count++;
        l = l->prox;
    }

    return count;
}


/*
3. void listaPal (Palavras l) que escreve no ecran, uma por linha, todas as palavras ar-
mazenadas, bem como o numero de ocorrencias.
*/

void listaPal (Palavras l) {
    
    while(l) {
        printf("Palavra:%s | Ocorrencia:%d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}


/*
4. char * ultima (Palavras l) que determina qual a ultima palavra da lista.
*/

char * ultima (Palavras l){
    char *last;

    while(l) {
        if(!(l->prox)) {
            printf("%s", l->palavra);
        }
        l = l->prox;
    }
}



/*
5. Palavras acrescentaInicio (Palavras l, char *p) que acrescenta uma palavra no inıcio
da lista (com 1 como numero de ocorrencias)
*/


Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = l;
    
    return new;

}


/*
Palavras acrescentaFim (Palavras l, char *p) que acrescenta uma palavra no fim da lista
(com 1 como numero de ocorrencias).
*/

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras temp = l;
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = NULL;

    if(l==NULL) {
        l = new;
    } else {
        while(temp->prox) {
            temp = temp->prox
        } 
        temp->prox = new;
    }

    return l;
}



/*
7. Palavras acrescenta (Palavras l, char *p) que regista mais uma ocorrencia da palavra p.
Se a palavra ja existir, o numero de ocorrencias deve ser incrementado. No outro caso deve ser
inserida uma nova celula.
A insercao de uma nova celula pode ser feita no inıcio da lista ou ordenadamente, assumindo
que a lista esta armazenada por ordem alfabetica.
*/


Palavras acrescenta (Palavras l, char *p) {

    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;
    new->prox = NULL;
    Palavras move = l;
    Palavras anterior = l;

    if(l == NULL) {
        l = new;
    } else {
        while(move->prox != NULL && strcmp(p, move->palavra) < 0) {
            anterior = move;
            move = move->prox;
        }

        if(strcmp(p,move->palavra) == 0) {
            move->ocorr++;
            break
        } else if(move->prox == NULL) {
            move->prox == new;
        } else {
            nova->prox = move;
            anterior->prox = nova;
        }
    }


    return l;

}



/*
8. struct celula * maisFreq (Palavras l) que calcula a celula correspondente a palavra mais
frequente.
*/


struct celula * maisFreq (Palavras l) {
    Palavras maisfreq = malloc(sizeof(struct celula));
    int maior = 0;

    while(l) {
        if(l->ocorr > maior) {
            maisfreq = l;
            maior = l->ocorr;
        } 

        l = l->prox;
    }

    return maisfreq;
}

