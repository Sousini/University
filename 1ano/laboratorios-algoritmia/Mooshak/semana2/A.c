#include <stdio.h>
#include <stdlib.h> 




int main() {
    int n, i, c;
    int x = 0;
    int y = 0;

    if(scanf("%d",&n) != 1) return 1; // numero de linhas

    for(i = 0; i < n; i++){
        if(scanf("%d", &c) != 1) return 1; //numero da carta
        
        if (c > 0 && c <= 78){                          //baralho com 78 cartas (1-78)
            if(c % 4 == 0) x += 1; else             //direita
                if(c % 4 == 3) x -= 1; else         //esquerda
                    if(c % 4 == 2) y += 1; else     //baixo
                        if(c % 4 == 1) y -= 1;      //cima
        }
    }



    printf("%d %d\n", x, y);
    

    return 0; 
}