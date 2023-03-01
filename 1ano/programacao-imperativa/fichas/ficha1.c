#include <stdio.h>
#include <stdlib.h>
#include <math.h> 




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

/*int main() {
    quadrado(5);
    return 0;
}*/ 


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

/*int main(){
    xadrez(5);
    return 0; 
}*/


//3.3 


void trianguloA() {
    int x = 0; 
    int y = 1; 
    int altura;
    int topo = 0;

    printf("\nDigite um numero para a altura do triangulo: \n");
    scanf("%d", &altura);

    while (x <= altura) {
        x++;
        if (y < x) {
            break;
        }
        printf("#");
        
        
        if (x == altura) {
            printf("\n");
            topo = 1;
            y--;
            x = 0;
        }

        if (x == y) {
            if (topo == 0) {
                printf("\n");
                y++;
                x = 0;
            } else {
                printf("\n");
                y--;
                x = 0;
            }
        }
    }
}





/*
int main(){
    trianguloB();
    return 0;
}
*/

void trianguloB(int n) {
    int linha, symbol, espaco, x; 
    x = 1;

    for (linha = 1; linha < n + 1; linha ++){
        for (espaco = n - linha; espaco != 0; espaco--) {
            putchar(' ');
        }
        for (symbol = 0; symbol < x; symbol++) {
            putchar('#');
        }
        printf("\n"); 
        x += 2; 
    }
}



int main(){
    trianguloB(5);
    return 0;
}