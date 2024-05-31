#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
1. Implemente a função int nesimo(int a[], int N, int i) que dado um array de tamanho N > 0 e um inteiro 0 < i <= N devolve o i-ésimo menor elemento do array. Por exemplo, se i == 1 a função deve retornar o menor elemento do array
*/
int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*) b);
}

int nesimo(int a[], int N, int i) {

    qsort(a, N, sizeof(int), compare);
}


/* 2. Implemente a função LInt removeMaiores(LInt l, int x) que remove de uma
lista ordenada l todos os elementos maiores que x, devolvendo a lista resultante.
Considere a definição usual do tipo LInt. */


typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;




LInt removeMaiores(LInt l, int x) {
    LInt inicio = l;
    LInt anterior = NULL;

    while(l != NULL && l->valor <= x) {
        anterior = l;
        l = l->prox;
    }

    if(l==NULL) {
        return inicio;
    }

    while(l!=NULL) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }

    anterior->prox = NULL;

    return inicio;
}



/* 3. Implemente a função LInt caminho(ABin a, int x) que, dada uma árvore binária
de procura a e um valor x, devolve uma lista com todos os valores desde a raiz até x
(inclusivé). Se x não existir na árvore, deve devolver NULL. Considere a definição usual
do tipo ABin (o tipo LInt foi dado na questão anterior). */



typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;





LInt caminho(ABin a, int x){
    if(a == NULL) return NULL;

    LInt lista = malloc(sizeof(LInt));
    lista->valor = a->valor;
    lista->prox = NULL;

    if(a->valor == x){

        return lista;
    }

    if(a->valor > x){
        lista->prox = caminho(a->esq, x);
    }

    if(a->valor < x) {
        lista->prox = caminho(a->dir, x);
    }

    return NULL;
    
}


/*4. Implemente a função void inc(char s[]) que, dada uma uma string s com um
número em decimal, incrementa esse número numa unidade. Assuma que a string tem
espaço suficiente para armazenar o número resultante. Por exemplo, se a string for
"123" deverá ser modificada para "124". Se for "199" deverá ser modificada para
"200"*/

void inc(char s[]) {
    int size = strlen(s);
    int temp[size + 1]; // +1 para possível carry
    int carry = 0;

    // Convertendo os caracteres de s em inteiros e armazenando em temp
    for (int i = 0; i < size; i++) {
        temp[i] = s[i] - '0';
    }

    // Incrementando o último dígito e verificando carry
    temp[size] = temp[size - 1] + 1;
    if (temp[size] > 9) {
        temp[size] = 0;
        carry = 1;
    }

    // Propagando o carry, se necessário
    for (int i = size - 1; i >= 0 && carry; i--) {
        temp[i]++;
        if (temp[i] > 9) {
            temp[i] = 0;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    // Convertendo os inteiros de temp de volta para caracteres em s
    for (int i = 0; i < size; i++) {
        s[i] = temp[i] + '0';
    }

    printf("%s\n", s);
}


/* 5. Implemente a função int sacos(int p[], int N, int C) que, dado um array com
os pesos de N produtos que se pretende comprar num supermercado, e a capacidade
C dos sacos desse supermercado, determine o número mínimo de sacos necessários
para transportar todos os produtos. Por exemplo, se os pesos dos produtos forem
{3,6,2,1,5,7,2,4,1} e C == 10, então bastam 4 sacos. Se os pesos forem
{3,3,3,3,5,5,11} e C == 11, então bastam 3 sacos. Em geral, para descobrir este
mínimo teria que testar todas as possíveis maneiras de ensacar os produtos. Se não
conseguir implementar essa estratégia óptima, implemente outra que devolva uma
aproximação razoável */



int sacos(int p[], int N, int C) {
    int sacos_necessarios = 0;
    int capacidade_atual = 0;

    for(int i = 0; i < N; i++) {
        if(capacidade_atual + p[i] <= C) {
            capacidade_atual += p[i];
        } else {
            sacos_necessarios++;
            capacidade_atual = p[i];
        }
    }

    if(capacidade_atual > 0) {
        sacos_necessarios++;
    }

    return sacos_necessarios;
}








int main() {
    /* int a[] = {1,2,3,4,5,6};
    int N = 6;
    int i = 2;
    int k = nesimo(a, N, i);

    printf("%d\n", k);*/

    return 0; 
}