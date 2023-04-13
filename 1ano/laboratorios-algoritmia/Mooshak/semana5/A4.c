#include <stdio.h>
#include <stdlib.h>


int main() {
  int N;

  if(scanf("%d", &N) != 1) return 1;

  for(int c = 0; c < N; c++) {
    int I, K;
    int guiches[K];

    if(scanf("%d", &K) != 1) return 1;
    if(scanf("%d", &I) != 1) return 1;

    for(int i = 0; i < K; i++) {
      if(scanf("%d", &guiches[i]) != 1) return 1;
    }
    int i = 0;
    int guiche_percorrido[K];
    int x;
    x = guiches[I];
    guiche_percorrido[0] = I;
    int index = 1;
    while(guiches[x] != guiche_percorrido[i++] && index < K) {
      
      guiche_percorrido[index] = guiches[x];
      x = guiches[x];
      printf("%d ", guiche_percorrido[index]);
      index++;
      
    }
    
    if(guiches[x] == guiche_percorrido[i++]) {
      printf ("CICLO INFERNAL");
    }
    
    printf("\n");
  }
}
