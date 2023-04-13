#include <stdio.h>
#include <stdlib.h>


int main() {
  int N;

  if(scanf("%d", &N) != 1) return 1;

  for(int c = 0; c < N; c++) {
    int K, I;

    if(scanf("%d", &K) != 1) return 1;
    if(scanf("%d", &I) != 1) return 1;

    int guiches[K];

    for(int i = 0; i < K; i++) {
      if(scanf("%d", &guiches[i]) != 1) return 1;
    }
    
    int guiches_percorridos[K];
    guiches_percorridos[0] = I;
    
    int found = 0;
    int x = guiches[I];

    for(int j = 0; j < K; j++) {
      int i = 0;

      if(guiches[j] == guiches_percorridos[i++]) {
        printf("CICLO INFERNAL");
        found = 1;
        break;
      }

      if(!found) {
        guiches_percorridos[j] = guiches[x];
      }
      x = guiches[x];

      printf("%d", guiches_percorridos[j]);
    }

    printf("\n");
  }
}
