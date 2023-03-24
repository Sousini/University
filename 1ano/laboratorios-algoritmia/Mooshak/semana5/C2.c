#include <stdio.h>
#include <string.h>

#define MAX_NOMES 50
#define TAM_NOME 30

int main() {
    char nomes[MAX_NOMES][TAM_NOME];
    int frequencia[MAX_NOMES] = {0};
    int num_nomes, i, j, max_freq, index_max;

    printf("Quantos nomes deseja inserir? ");
    scanf("%d", &num_nomes);

    // leitura dos nomes
    for (i = 0; i < num_nomes; i++) {
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", nomes[i]);
    }

    // contagem da frequência dos nomes
    for (i = 0; i < num_nomes; i++) {
        for (j = i; j < num_nomes; j++) {
            if (strcmp(nomes[i], nomes[j]) == 0) {
                frequencia[i]++;
            }
        }
    }

    // encontra o nome com a frequência mais alta
    max_freq = frequencia[0];
    index_max = 0;
    for (i = 1; i < num_nomes; i++) {
        if (frequencia[i] > max_freq) {
            max_freq = frequencia[i];
            index_max = i;
        }
    }

    printf("O nome mais frequente é: %s\n", nomes[index_max]);

    return 0;
}

