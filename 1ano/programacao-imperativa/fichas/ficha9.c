#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;



ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}


// 1

/*
(a) int altura (ABin a) que calcula a altura de uma arvore.
*/


int altura (ABin a) {
    
    if(a==NULL) {
        return 0;
    }
    

    int e = altura(a->esq);
    int d = altura(a->dir);

    if(e > d) {
        return e + 1;
    } else {
        return d + 1;
    }

}


/*
b) int nFolhas (ABin a) que calcula o n´umero de folhas (i.e., nodos cujas sub-´arvores s˜ao
ambas vazias).
*/

int nFolhas (ABin a) {
    int r = 0;
    if(a==NULL) {
        return 0;
    }

    if(a->esq == NULL) {
        if(a->dir == NULL) {
            r++;
        } else {
            r = nFolhas(a->dir);
        }
    } else {
        if(a->dir == NULL) {
            r = nFolhas(a->esq);
        } else {
            int e = nFolhas(a->esq);
            int d = nFolhas(a->dir);

            r = e+d;
        }
    }

    return r;
}



/*
(c) ABin maisEsquerda (ABin a) que calcula o nodo mais `a esquerda de uma ´arvore.
*/


ABin maisEsquerda (ABin a) {
    
    if(a==NULL) {
        return NULL;
    }

    while(a->esq) {
        a = a->esq;
    }

    return a;
}


/*
(d) void imprimeNivel (ABin a, int l) que escreve no ecran os elementos da ´arvore que
est˜ao ao n´ıvel l (Considere que a raiz de uma ´arvore se encontra no n´ıvel 0).
*/

void imprimeNivel (ABin a, int l) {


    if(l == 0) {
        printf("%d ", a->valor);
    } else if(l>0) {
        if(a->esq != NULL) imprimeNivel(a->esq, l-1);
        if(a->dir != NULL) imprimeNivel(a->dir, l-1);
    }

   
}


/* 
(e) int procuraE (ABin a, int x) que testa se x ocorre na ´arvore. N˜ao assuma qualquer
propriedade sobre a ´arvore a.
*/


int procuraE (ABin a, int x) {
    if(a==NULL) {
        return 0;
    }

    if(a->valor == x) {
        return 1;
    }

    int e = procuraE(a->esq, x);
    int d = procuraE(a->dir, x);

    if(e || d) return 1;

    return 0;
}


/*
2. Apresente defini¸c˜oes sobre as seguintes fun¸c˜oes sobre ´arvores bin´arias de procura
*/

/*
(f) struct nodo *procura (ABin a, int x) que procura um elemento numa ´arvore. A
fun¸c˜ao dever´a retornar o endere¸co da c´elula onde o elemento ocorre ou NULL caso o ele-
mento n˜ao exista na ´arvore.
*/

struct nodo *procura (ABin a, int x) {
    while (a != NULL && a->valor != x) {
        a = (a->valor > x) ? a->esq : a->dir;
    }
    return a;
}



/*
(g) int nivel (ABin a, int x) que calcula o n´ıvel a que o elemento ocorre na ´arvore (-1
caso n˜ao exista).
*/

int nivel(ABin a, int x) {
    int n = 0;
    while (a != NULL && a->valor != x) {
        a = (a->valor > x) ? a->esq : a->dir;
        n++;
    }
    
    return (a == NULL) ? -1 : n;
}



/*
(h) void imprimeAte (ABin a, int x) que imprime no ecran, por ordem crescente, todos os
elementos da ´arvore que s˜ao (estritamente) menores do que um dado valor.
*/

void imprimeAte (ABin a, int x) {
    
    if(a!=NULL) {
        if(a->esq != NULL) imprimeAte(a->esq, x);
        if(a->valor < x) printf(" %d ", a->valor);
        if(a->dir != NULL) imprimeAte(a->dir, x);
    }
    
}