#include <stdio.h> 
#include <stdlib.h> 




int main() {
    int cmdW = 0;
    int inzelW = 0;
    int draw = 0; 
    int n, j;
    char inzel, cmd; 

    if(scanf("%d\n", &n) != 1) return 1; 

    for(j = 0; j < n; j++) {
        if(scanf("\n%c", &inzel) != 1) return 1; 
        if(scanf("%c", &cmd) != 1) return 1; 

        switch ( inzel ) {

            case '@' :
                switch ( cmd ) {
                    case '*':
                        draw += 1;
                        break;
                    
                    case '-':
                        cmdW += 1;
                        break;
                    
                    case '+':
                        inzelW += 1;
                        break;
                }
                break;

            case '|' :
                switch ( cmd ) {
                    case '*':
                        inzelW += 1;
                        break;
                    
                    case '-':
                        draw += 1;
                        break;
                    
                    case '+':
                        cmdW += 1;
                        break;
                }
                break;

            case 'X' :
                switch ( cmd ) {
                    case '*':
                        cmdW += 1;
                        break;

                    case '-':
                        inzelW += 1;
                        break;
                    
                    case '+':
                        draw += 1;
                        break;
                }
                break;
        }
    }

    printf("%d %d %d\n", inzelW, cmdW, draw); 


    return 0;
}