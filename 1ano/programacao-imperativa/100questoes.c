#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


/*
Apresente uma definicao nao recursiva da funcao int length (LInt) que calcula o comprimento de uma lista ligada.
*/

int length(LInt l) {
    LInt atual = l;
    int count = 0;
    while(atual != NULL) {
        count++;
        atual = atual->prox;

    }

    return count;
}

/*
Apresente uma definicao nao recursiva da funcao void freeL (LInt) que liberta o espaco
ocupado por uma lista.
*/

void freeL(LInt l) {

    LInt list = l;
    
    while(l->prox != NULL) {
        list = l->prox;
        free(l);
        l = list;
    }
}


/*
Apresente uma definicao nao recursiva da funcao void imprimeL (LInt) que imprime no
ecran os elementos de uma lista (um por linha).
*/

void imprimeL(LInt l) {
    
    printf("%d ", l->valor);

    do{
        l = l->prox;
        printf("%d ", l->valor);
    } while (l ->prox != NULL);

    printf("\n");
}


/*
Apresente uma definicao nao recursiva da funcao LInt reverseL (LInt) que inverte uma
lista (sem criar uma nova lista)
*/


LInt reverseL(LInt l) {
    // reverses a list (without creating a new list)
    LInt anterior = NULL;
    LInt proximo = NULL;

    while (l != NULL) {
        proximo = l->prox;   
        l->prox = anterior;  
        anterior = l;        
        l = proximo;
    }

    return anterior;
}


/*
Apresente uma definicao nao recursiva da funcao void insertOrd (LInt *, int) que insere
ordenadamente um elemento numa lista ordenada.
*/

void insertOrd(LInt *l, int x) {
    LInt anterior = NULL;
    while (*l != NULL && (*l)->valor < x) {
        anterior = *l;
        l = &((*l)->prox);
    }

    LInt novo = malloc(sizeof(LInt));
    novo->valor = x;
    novo->prox = *l;

    if (anterior == NULL) {
        *l = novo; // Update the pointer to the list
    } else {
        anterior->prox = novo;
    }

}

/*
Apresente uma defini¸c˜ao n˜ao recursiva da fun¸c˜ao int removeOneOrd (LInt *, int) que
remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover n˜ao exista,
0 no outro caso
*/

int removeOneOrd(LInt *l, int x) {
    LInt anterior = NULL;
    LInt temp = NULL;

    if (*l == NULL)
        return 1;

    if ((*l)->valor == x) {
        temp = *l;
        *l = (*l)->prox;
        free(temp);
        return 0;
    }

    anterior = *l;
    while (anterior->prox != NULL && anterior->prox->valor != x) {
        anterior = anterior->prox;
    }

    if (anterior->prox == NULL)
        return 1;
    
    temp = anterior->prox;
    anterior->prox = temp->prox;
    free(temp);
    return 0;
}

