#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 40

int main() {
    int N;
    
    if(scanf("%d", &N) != 1) {
        fprintf(stderr, "Error reading N\n");
        return 1;
    }
    
    if(N > MAX_NAMES) {
        fprintf(stderr, "N is too large\n");
        return 1;
    }

    getchar(); // consume newline character
    
    int presencas[MAX_NAMES] = {0}; //número de presencas por cada nome (o numero do presencas[i] representa o nome[i])
    char nomes[MAX_NAMES][21] = {0}; //nomes sem se repetirem

    
    int freq = 0; //quantidade de nomes que aparecem sem repetição

    
    for(int l = 0; l < N; l++) {
    
        char linha[1000];
        fgets(linha, 1000, stdin);
        
        // remove newline character
        linha[strcspn(linha, "\n")] = '\0';

        int size = strlen(linha);

        int i = 0;
        while(i < size) {    
            char nome[21];
            int j = 0;
            while(i < size && linha[i] != ' ' && linha[i] != '\n') {
                nome[j++] = linha[i++];
            }
            nome[j] = '\0';

            int found = 0;
            for(int k = 0; k < freq; k++){
                if(strcmp(nomes[k], nome) == 0) {
                    presencas[k]++;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                strcpy(nomes[freq], nome);
                presencas[freq]++;
                freq++;
            }

            i++;
        }

    }

    int menor = presencas[0];
    for(int j = 0; j < freq; j++) {
        if(presencas[j] < menor) {
            menor = presencas[j];
        }
    }

    for(int j = 0; j < freq; j++) {
        if(presencas[j] == menor) {
            printf("%s\n", nomes[j]);
        }
    }

    return 0;
}
