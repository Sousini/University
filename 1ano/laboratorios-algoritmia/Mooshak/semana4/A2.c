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
    int res[N];
    int a2[1010];

    if(scanf("%d", &N) != 1) return 1;

    for(int l = 0; l < N; l++) {
        int r = 0;
        fgets(a2, 1010, stdin); 

        char *p;

        p = strtok(a2, " ");

        while(p != NULL) {
            int size = strlen(p);
            for(int i = 1; i < size - 1; i++){
                if (e_consoante(p[i]) == e_consoante(p[i+1])) {
                    r = 0;
                } else {
                    r += 1;
                }
            }

        for(int x = 0; x < N; x++) {
        res[x] = r;
        }
        r = 0;

        }
    printf("%d\n", res[l]);
    }
}