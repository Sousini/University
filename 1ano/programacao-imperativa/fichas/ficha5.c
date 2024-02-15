#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;


/*
1. Defina uma funcao int nota (Aluno a) que calcula a nota de um aluno (de acordo com as
regras definidas para Programacao Imperativa). A funcao devera retornar 0 se o aluno nao tiver
aproveitamento.
*/


int nota (Aluno a) {

    int mt;

    for(int i = 0; i < 6; i++) {
        mt += a.miniT[i];
    }

    float permt = mt * 0.2;

    float t = a.teste * 0.8;

    float final = mt + t;

    if(final >= 9.5) {
        return final;
    }

    return 0;

}















void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}
void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}




int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;
    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");
    
    // ordenaPorNum (Turma1, 7);

    // printf ("procura 5555: %d \n", procuraNum (5555, Turma1, 7));
    // printf ("procura 9999:%d \n", procuraNum (9999, Turma1, 7));

    for (i=0; i<7; imprimeAluno (Turma1 + i++));
    
    // criaIndPorNum (Turma1, 7, indNum);
    
    // criaIndPorNome (Turma1, 7, indNome);

    // imprimeTurmaInd (indNum, Turma1, 7);
    // imprimeTurmaInd (indNome, Turma1, 7);

    // printf ("procura 5555:%d \n",  procuraNumInd (5555, indNum, Turma1, 7));
    // printf ("procura 9999:%d \n",  procuraNumInd (9999, indNum, Turma1, 7));

    printf ("\n---------- Fim dos Testes ----------\n");
    
    return 0;
}