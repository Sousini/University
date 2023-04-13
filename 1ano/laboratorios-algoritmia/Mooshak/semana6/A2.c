#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pertence(char c, char v[], int size) {
    int x = 0;

    for(int i = 0; i < size; i++) {
        if(c == v[i]) {
            x = 1;
            break;
        }
    }

    return x;
}

char *remove_spaces(char *str) {
    int i, j;
    char *new_str = malloc(strlen(str) + 1);
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';

    return new_str;
}


int main() {
    int N;

    if(scanf("%d", &N) != 1) return 1;
    getchar();

    for(int i = 0; i < N; i++) {
        
        int K;

        if(scanf("%d", &K) != 1) return 1;
        getchar();

        int resultado[K];
        
        char vilao1[101];
        

        if(fgets(vilao1, 101, stdin) == 0) return 1;

        char *vilao = remove_spaces(vilao1);

        int size_v = strlen(vilao);
        int aux, contador, found; 
        aux = contador = found = 0;

        for(int j = 0; j < K; j++) {

            char nome1[101];
            

            if(fgets(nome1, 101, stdin) == 0) return 1;

            char *nome = remove_spaces(nome1);

            int size = strlen(nome);

            if(size != size_v) break;

            for(int c = 0; c < size; c++) {
                found = pertence(nome[c], vilao, size_v);
            }

            if(found) {
                resultado[contador] = j + 1;
                contador++;
                aux++;
            }
        }

        if(aux == 0) {
            printf("-1");
        } else {
            printf("%d", resultado[0]);

            for(int l = 1; l < contador; l++) {
                printf(" %d", resultado[l]);
            }
        }

        printf("\n");
    }
}