#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
PARTE A
*/

typedef struct slist {
    int valor;
    struct slist *prox;
}   *LInt;


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


/*
Questao 1
*/

int retiraNeg(int v[], int N) {
	int i = 0, pos = 0;
	for(; i < N; i++)
		if (v[i] >= 0)
			v[pos++] = v[i];
	return pos;
}


/*
Questao 2
*/

int difConsecutivos (char s[]) {
    int maior = 0, subString = 0;
    int i = 0, j = 0, lastPos = 0;
    while (s[i] != '\0') {
        j = i+1;
        lastPos = i;
        subString = 1;
        for (; s[j] != '\0' && (s[j] == ' ' || s[j] != s[lastPos]); j++) {
            if (s[j] != ' ') {
                lastPos = j;
                subString++;
            }
        }
        if (s[j] != '\0' && s[j+1] == s[j]) subString--;
        if (subString > maior) maior = subString;
        i++;
    }
    return maior;
}



/*
Questao 3
*/


int maximo(LInt l) {
    int maior = 0;

    while(l) {
        if(l->valor > maior) {
            maior = l->valor;
        } 

        l = l->prox;
    }

    return maior;   
}


/*
Questao 4
*/


int removeAll (LInt *l, int x) {
    int count = 0;
    LInt ant = NULL;
    LInt temp = *l;

    while(temp) {
        if(temp->valor == x) {
            if(ant != NULL) {
                ant->prox = temp->prox;
                free(temp);
                temp = ant->prox;
            } else {
                *l = temp->prox;
                ant = NULL;
                free(temp);
                temp = *l;
            }

            count++;
        } else {
            ant = temp;
            temp = temp->prox;
        }
    }
    
    return count;

}





/*
Questao 5
*/



LInt arrayToList (int v[], int N) {
    
    if(N == 0) return NULL;

    LInt inicio = NULL;
    LInt fim = NULL;    
    
    for(int i = 0; i < N; i++) {
        LInt temp = malloc(sizeof(struct slist));

        temp->valor = v[i];
        temp->prox = NULL;

        if(inicio == NULL) {
            inicio = temp;
            fim = temp;
        } else {
            fim->prox = temp;
            fim = temp;
        }
    }

    return inicio;
}




/*
PARTE B
*/



/*
Questao 1
*/


int minheapOK (ABin a) {

	if (a == NULL) return 0;
	int cond = 0;
	if (a->esq != NULL && a->esq->valor < a->valor) return 1;
	cond = minHeapOK(a->esq);
	if (!cond) {
		if (a->dir != NULL && a->dir->valor < a->valor) return 1;
		cond = minHeapOK(a->dir);
	}
	return cond;

}



/*
Questao 2
*/

int maxHeap (ABin a) {

    int maior = a->valor;

    if(a->esq != NULL) {
        int e = maxHeap(a->esq);
        if(maior < e) {
            maior = e;
        }
    }

    if(a->dir != NULL) {
        int d = maxHeap(a->dir);
        if(d > maior) maior = d;
    }

    return maior;
}



/*
Questao 3
*/

void removeMin (ABin *a) {
    int min = (*a)->valor;


    if(*a) {
        if((*a)->esq == NULL) {
            if((*a)->dir == NULL) {
                free(*a);
                *a = NULL;
            } else {
                ABin temp = *a;
                *a = temp->dir;
                free(temp);
                
            }
        } else {
            if((*a)->dir == NULL) {
                ABin temp = *a;
                *a = temp->esq;
                free(temp);
            } else {
                ABin next = (a->esq->valor < a->dir->valor) ? a->esq : a->dir;
				(*a)->valor = next->valor;
				removeMin(&next);
				(*a)->prox = next;
            }
        }
    }

}


/*
Questao 4
*/

void heapSort(int v[], int N) {
    ABin a = NULL;

    for(int i = 0; i < N; i++) {
        add(&a, v[i]);
    }

    for(int i = 0; i < N; i++) {
        v[i] = a->valor;
        removeMin(&a);
    }
}


/*
Questao 5
*/

int kMaior(int v[], int N, int k) {
	if (N == 0 || k == 0) return -1;
	int lidos = 0;
	ABin arvore = NULL;
	for (int i = 0; i < N; i++) {
		if (lidos < k) {
			add(&arvore, v[i]);
			lidos++;
		} else if (arvore->valor < v[i]) {
			removeMin(&arvore);
			add(&arvore, v[i]);
		}
	}
	return arvore->valor;

}



int main() {


    return 0;
}

















