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
    char *new_str = malloc(strlen(str) + 1); //alocar dinamicamente memória para uma nova string (new_str)
    if (new_str == NULL) {
        return NULL; // allocation failed
    }
    //vai adicionar a string new_str todos os elementos que não sejam espaços
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) { // se não for espaço (ctype.h)
            new_str[j++] = str[i]; //para o i aumentar e o j não
        }
    }
    new_str[j] = '\0'; //terminar a string com o carater nulo

    return new_str;
}


int main() {
    int N;

    if(scanf("%d", &N) != 1) {
        return 1;
    }
    getchar(); //consume newline char

    for(int i = 0; i < N; i++) {
        int K;

        if(scanf("%d", &K) != 1) {
            return 1;
        }
        getchar();

        int resultado[K];
        char vilao1[101];

        if(fgets(vilao1, 101, stdin) == NULL) {
            return 1;
        }
        

        char *vilao = remove_spaces(vilao1); //remover os espaços do nome do vilao
        if (vilao == NULL) {

            return 1;
        }

        int size_v = strlen(vilao); 
        int aux = 0, contador = 0, found = 0; 

        for(int j = 0; j < K; j++) {
            char nome1[101];

            if(fgets(nome1, 101, stdin) == NULL) {
                return 1;
            }

            char *nome = remove_spaces(nome1); //remover os espaços do nome do "candidato"
            if (nome == NULL) {
                return 1;
            }

            int size = strlen(nome);
        
            if(size != size_v) { // se os tamanhos forem diferentes então é impossível ser um anagrama
                free(nome); //liberar a memória alocada pelo malloc
                continue; // continuar para a próxima iteração do loop
            }

            found = 0;
            for(int c = 0; c < size; c++) {
                found = pertence(nome[c], vilao, size_v); //caso a letra esteja no nome do vilão 1, 0 caso não esteja
                if (!found) break; // se for zero
            }


            if(found) {
                resultado[contador] = j + 1; 
                contador++;
                aux++;
            }

            free(nome); //liberar a memória alocada pelo malloc
            
        }

        free(vilao); //liberar a memória alocada pelo malloc

        if(aux == 0) { // se a aux for = 0, signfica que não houve nenhum anagrama
            printf("-1\n");
        } else {
            printf("%d", resultado[0]); //dar print ao primeiro resultado (presentation error)

            for(int l = 1; l < contador; l++) {
                printf(" %d", resultado[l]);
            }
            printf("\n");
        }
    }

    return 0;
}
