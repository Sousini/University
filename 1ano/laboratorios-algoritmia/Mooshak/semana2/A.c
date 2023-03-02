#include <stdio.h>
#include <stdlib.h> 



int main() {
    int x = 0;
    int y = 0; 
    int nc; 
    int j;
    int i; 

    if(scanf("%d", &j) != 1) return 1; 

    
    for(i = 1; i <= j; i++) {
        if(scanf ("%d", &nc) != 1) 
        return 1; 

        if (nc > 0 && nc <= 78) {
            if (nc % 4 == 0) {
                x += 1; 
                y = y;
            } else {
                if (nc % 4 == 3) {
                    x -= 1; 
                    y = y;
                } else {
                    if (nc % 4 == 2) {
                        x = x; 
                        y -= 1;
                    } else {
                        if (nc % 4 == 1) {
                            x = x; 
                            y += 1;
                        }
                    }
                }
            }
        }
    }
   
    printf("%d %d\n", x, y);
    
    return 0; 
}