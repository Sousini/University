#include <stdio.h> 
#include <stdlib.h> 



int main() {

    char nome[25];
    int idade; 
     

    printf("\nDigite o seu primeiro nome:\n");
    scanf("%s", &nome);

    printf("\nDigite a sua idade:\n"); 
    scanf("%d", &idade);
 
    if (idade > 1) {
        if (idade < 75) {
            printf("Ola %s, tudo bem?\nVoce tem %d anos", nome, idade);
        } else {
            printf("Bem... Caro/a senhor(a) %s, foi bom enquanto durou...\n%d aninhos? Ja esta na hora de comecar a ver caixoes, nao", nome); 
        }
        
    } else {
        printf("Ola %s, tudo bem?\nVoce tem %d ano", nome, idade); 
    }


    return 0; 
}