#include <stdio.h> 
#include <stdlib.h> 

int main() {
    int c, a, n, i; 

    if(scanf("%d", &c) != 1) return 1; 
    if(scanf("%d", &a) != 1) return 1; 
    if(scanf("%d", &n) != 1) return 1; 

    for(i = 0; i < n; i++){
        int x;

        if(scanf("%d", &x) != 1) return 1; 

        if(x == -1 && c != 0){
            c -= 1;
        }

        if( x == 1 && c < a ) 
            c += 1;
    }

    printf("%d\n", c); 

    return 0;
}