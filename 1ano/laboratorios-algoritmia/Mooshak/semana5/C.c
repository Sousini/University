#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int N;
    
    if(scanf("%d", &N) != 1) return 1;    
    getchar(); // elimina newline char
    
    int presencas[40] = {0}; //número de presencas por cada nome (o numero do presencas[i] representa o nome[i])
    char nomes[40][21] = {0}; //nomes sem se repetirem

    
    int freq = 0; //quantidade de nomes que aparecem sem repetição

    
    for(int l = 0; l < N; l++) {
    
        char linha[1000];
        if(fgets(linha, 1000, stdin) == 0) return 1; //obtem a linha l (interessa o tamanho do array)
        
        // remove newline character e substitui pelo '/0' que indica o fim da string (devido ao fgets)
        linha[strcspn(linha, "\n")] = '\0'; //strcspn calcula o número de caracteres(length) até o primeiro \n

        int size = strlen(linha); //tamanho da linha com os nomes

        int i = 0;
        while(i < size) {    
            char nome[21]; 
            int j = 0;
            while(i < size && linha[i] != ' ' && linha[i] != '\n') { //para cada nome (não funciona para os espaços e para o newline)
                nome[j++] = linha[i++]; //copiar os caracteres do array linha para o array nome
            }
            nome[j] = '\0'; //adiciona o '/0' ao fim da string nome

            int found = 0; //se o nome já foi encontrado (found = 1) ou não (found = 0)
            for(int k = 0; k < freq; k++){
                if(strcmp(nomes[k], nome) == 0) { //compara a string nomes com a string nome
                    presencas[k]++; //se forem iguais adiciona 1 à string presenças de index k
                    found = 1; //caso o nome foi encontrado o found vai ser 1  
                    break; //para sair do loop
                }
            }
            if(!found) { //vê se o nome já foi encontrado ou não, se !found é verdadeiro, o nome não foi registado (found = 0)
                strcpy(nomes[freq], nome); //caso não tenha sido encontrado copia-se o nome para a posição freq que corresponde ao fim do array
                presencas[freq]++; //adiciona 1 ao array das presenças na posição do nome
                freq++; //aumenta 1 para passar para o proximo elemento do array
            }

            i++;
        }

    }
    //ver qual é o menor número dentro do array
    int menor = presencas[0];
    for(int j = 0; j < freq; j++) {
        if(presencas[j] < menor) {
            menor = presencas[j];
        }
    }

    //dar print aos nomes com menos presenças
    for(int j = 0; j < freq; j++) {
        if(presencas[j] == menor) {
            printf("%s\n", nomes[j]);
        }
    }

    return 0;
}
