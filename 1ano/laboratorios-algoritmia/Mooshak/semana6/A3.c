#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool eh_anagrama(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return false;
    }

    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; i < len1; i++) {
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);

        if (c1 != ' ') {
            count1[(int)c1]++;
        }
        if (c2 != ' ') {
            count2[(int)c2]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    getchar();
    
    for (int i = 0; i < N; i++) {
        int K;
        
        if (scanf("%d", &K) != 1) {
            return 1;
        }
        getchar();
        
        char vilao[101];
        
        if (fgets(vilao, 101, stdin) == 0) {
            return 1;
        }
        
        int resultado[K];
        int contador = 0;
        
        for (int j = 0; j < K; j++) {
            char nome[101];
            
            if (fgets(nome, 101, stdin) == 0) {
                return 1;
            }
            
            if (eh_anagrama(nome, vilao)) {
                resultado[contador] = j + 1;
                contador++;
            }
        }
        
        if (contador == 0) {
            printf("-1 ");
        } else {
            printf("%d", resultado[0]);
            for (int l = 1; l < contador; l++) {
                printf(" %d", resultado[l]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
