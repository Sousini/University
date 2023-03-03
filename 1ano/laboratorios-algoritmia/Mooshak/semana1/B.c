#include <stdio.h> 
#include <stdlib.h>


int recebe() {
    int soldado; 
    if (scanf("%d", &soldado) != 1){
        abort();
    } else {
        return soldado;
    }
}


int main() {
    int s1, s2, s3;

    s1 = recebe();
    s2 = recebe();
    s3 = recebe(); 


    if ((s1 == s2 && s2 == s3) || (s1 >= s2 && s2 >= s3 ) || (s1 <= s2 && s2 <= s3)) {
        printf("OK\n");    
    } else {
        printf("NAO\n");
    }


    return 0;
}