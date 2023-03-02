#include <stdio.h> 
#include <stdlib.h> 


int main() {
    int ri = 0;
    int rc = 0;
    int e = 0; 
    int n, j;
    char i, c; 

    if(scanf("%d", &n) != 1) return 1; 

    for(j = 0; j < n; j++) {
        if(scanf("%c", &i) != 1) return 1; 
        if(scanf("%c", &c) != 1) return 1; 

        switch ( i ) {

            case '@' :
                switch ( c ) {
                    case '*':
                    

                }
            
            case '|' :



            case 'X' :

        }
    }

    printf("%d %d %d\n", ri, rc, e); 

    return 0;
}