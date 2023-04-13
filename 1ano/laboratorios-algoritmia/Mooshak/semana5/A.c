#include <stdio.h>

int main() {
    int N;
    if(scanf("%d", &N) != 1) return 1;

    for(int c = 0; c < N; c++) {
        int K, I;
        if(scanf("%d", &K) != 1) return 1;
        if(scanf("%d", &I) != 1) return 1;

        int guiches[100];
        for(int i = 0; i < K; i++) {
            if(scanf("%d", &guiches[i]) != 1) return 1;
        }

        int percorrido[100] = {0}; //guiches percorridos
        int posicao = I - 1; //guiches ordenados a partir de 1 mas o array é indexado a partir do 0 ; posicao atual em que o codigo vai 
        int i = 0;
        int found_loop = 0;

        int primeiro_guiche = 1;

        while(i < K && !percorrido[posicao] && !found_loop) { // enquanto percorrido e o found loop forem falsos e o i < K
            percorrido[posicao] = 1; //indica que esta posicao ja foi visitada

            if (primeiro_guiche) { // para dar print ao primeiro guiche antes dos outros (presentation error)
                printf("%d", posicao + 1);
                primeiro_guiche = 0;
            }
            else {
                printf(" %d", posicao + 1);
            }
            posicao = guiches[posicao] - 1; // guiches ordenados a partir de 1 mas o array é indexado a partir do 0

            if(posicao < 0 || posicao >= K) { // verifica se a nova posicao esta dentro dos limites do array (caso o guiche "mande" para o guiche 0)
                found_loop = 0;
                break;
            }
            i++;
            if (percorrido[posicao]) { // verifica se este guiche já foi visitado
                found_loop = 1;
            }
        }

        if(found_loop) {
            printf(" CICLO INFERNAL");
        }
        printf("\n");
    }
    return 0;
}
