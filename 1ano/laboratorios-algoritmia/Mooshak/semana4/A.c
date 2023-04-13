#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e_consoante(char c) {
    char a[] = "AEIOUY";

    if(c == ' ') return 2;
    // 1 para vogal, 0 para consoante
    for(int i = 0; i < 6; i++) {
        if(c == a[i]) return 1;
    } 
    return 0;
}

int main() {
    int N = 0;
    char a2[1010];

    if (scanf("%d", &N) != 1) abort();

    for(int l = 0; l < N; l++) {
        int r = 0;

        fgets(a2, 1010, stdin);

        int size = strlen(a2);
        for(int i = 0; i < size - 1; i++) {

            if(e_consoante(a2[i] == 2)) r = r;
            if(e_consoante(a2[i]) != e_consoante(a2[i+1])) {
                r += 1;
            } else {
                r = 0;
                break;
            }

        }
    
        printf("%d\n", r);
    }

    printf("\n");

    return 0;
}
