#include <stdio.h>
#include <stdlib.h>




// 3.1

void quadrado(int n) {
    int l, c; 
    for (l = 0; l < n; l++){
        for (c = 0; c < n; c++){
            putchar('#');
        }
        printf("\n");
    }
    system("pause");  
}

int main() {
    quadrado(5);
    return 0;
}