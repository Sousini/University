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


//3.2 

void xadrez(int n){
    int i, j, quadrados; 
    quadrados = n * n; 
    i = 0; 

    while(i < quadrados) {
        for(j=0; j < n; j++) {
            if (i % 2 == 0) {
                putchar('#'); 
                i++; 
            } 
            else {
                putchar('_');
                i++;
            }
        }
        printf("\n");
    }
    system("pause");
}

int main(){
    xadrez(5);
    return 0; 
}


//3.3 

void triangulo(int n) {
    
}