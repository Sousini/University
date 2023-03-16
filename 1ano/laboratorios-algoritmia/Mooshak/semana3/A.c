#include <stdio.h>
#include <string.h>



int main() {
    char ordem[9];
    char mensagem[1001];

    if (scanf("%s", ordem) != 1) return 1;
    if (scanf("%s", mensagem) != 1) return 1;

    int sizem = strlen(mensagem);
    int sizeo = strlen(ordem);
    int c = 1;
    char new[1000] = "";
    char new2[1000] = "";
    
    for(int i = 1; i <= sizeo; i++) {
        for(int j = 0; j <= sizem; j++){
            if (i == c) {
                new[strlen(new)] = mensagem[j];
            }

            c++;

            if (c > sizeo) {
                c = 1;
            }
        }

        strcat(new2, new); 
        new2[strlen(new2)] = ' ';

        memset(new, 0,strlen(new));

        c = 1;

    }


    char *token = strtok(new2, " ");
    char *a[1000];
    int x = 0;
    

    while (token != NULL) {

        a[x] = token;
        token = strtok (NULL, " ");
        x++;
    }
    int o = 0;

    for (int i = 0; i < sizeo; i++) {
        o = (ordem[i] - '0') - 1;
        printf("%s", a[o]); 
    }
    
    printf("\n");

    return 0;
}