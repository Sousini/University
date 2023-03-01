#include <stdio.h>
#include <stdlib.h> 


// 1 

float multInt1(int n, float m) {
    int r = 0;

    while (n > 0) {

        if (n % 2 == 1) {
            r = r + m;
        }

        n = n/2;
        m = m + m;
    }

 return r;
}

// 2

int main() {

    multInt1(14,2.3);
    return 0;
}