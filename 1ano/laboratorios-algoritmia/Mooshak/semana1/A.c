
#include <stdio.h>  
#include <stdlib.h> 


#define ve_maior(posicaovalor) {\
    if (scanf("%d", &valor) != 1) abort ();\
    if (valor > maior) {\
        maior = valor;\
        ordem = posicaovalor;\
    }\
}


int main() {
    int maior = 0;
    int ordem = 0;
    int valor; 

    ve_maior(1);
    ve_maior(2);
    ve_maior(3);
    ve_maior(4);
    ve_maior(5); 

    printf("%d\n", ordem); 
    
    return 0;
}