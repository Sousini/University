#include <stdio.h> 
#include <stdlib.h>



int recebe() {
    int s; 
    if (scanf("%d", &s) != 1){
        return 1; 
    } else {
        return s;
    }
}


int main() {
    int s1, s2, s3;

    s1 = recebe(); 
    s2 = recebe(); 
    s3 = recebe(); 

    int a[] = {s1,s2,s3}; 

    int size = sizeof(a)/sizeof(*a);

    for (int x = 0; x < size - 1; x++) {
        
        for (int y = 0; y < size - 1; y++) {

            if(a[y] > a[y+1]) {
                int t = a[y]; 
                a[y] = a [y+1]; 
                a[y+1] = t;  
            }
        }
    }
    
    printf("%d %d %d\n", a[0], a[1], a[2]);


    return 0; 
}