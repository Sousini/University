#include <stdio.h>
#include <string.h>


/*
7 8 9
4 5 6
1 2 3
*/



int main() {
    int N = 0, i = 0;
    int s = 5; 
    char string[20];
    

    if(scanf("%d\n", &N) != 1) return 1; 
    int resultado[N];

    for(i = 0; i < N; i++){
         if(scanf("%s", string) > 20)
            return 1;
        int size = strlen(string);

        for(int j = 0; j < size; j++) {

            if(string[j] == 'C' && s < 7){
                s += 3;
            } else {
                if(string[j] == 'B' && s > 3) {
                    s -= 3;
                } else {
                    if(string[j] == 'E' && s != 1 && s != 4 && s != 7) {
                        s -= 1;
                    } else {
                        if(string[j] == 'D' && s != 3 && s != 6 && s != 9) {
                            s += 1;
                        }
                    }
                }
            }
        }
    resultado[i] = s;
    }
     
    for(i = 0; i < N; i++){
        printf("%d", resultado[i]);
    }
    printf ("\n");
}