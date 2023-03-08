#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, K;
    int r = 0;
    int alt;
    int maior = 0;
    

    if (scanf("%d", &N) != 1) return 1;

    int resultado[N];

    for(int l = 0; l < N; l++) {
        if (scanf("%d", &K) != 1) return 1;

        for(int i = 0; i < K; i++) {
            if (scanf("%d", &alt) != 1) return 1;

            if (alt > maior) {
                r++;
                maior = alt;
            }
        }
    resultado[l] = r;
    r = 0;
    maior = 0;
    }

    for(int l = 0; l < N; l++) {
        printf("%d\n", resultado[l]);
    }

    return 0;
}