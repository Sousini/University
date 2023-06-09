#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int N = 0;

    if(scanf("%d", &N) != 1) return 1;

    char r = '0';
    char resultado[N];
    char a[1010];

    for(int l = 0; l < N; l++) {
        
        if(scanf("%s", a) != 1) return 1;
        int size = strlen(a);

        for(int i = 0; i < size - 1; i++) {
            for(int j = i + 1; j < size; j++) {
                if(a[j] == a[i]) {
                    r = a[i];
                }
            }
        }

        resultado[l] = r;
    }


    for(int i = 0; i < N; i++) {
        printf("%c", resultado[i]);
    }

    printf("\n");
}