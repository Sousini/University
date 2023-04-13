#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;

  if (scanf("%d", &N) != 1) return 1;

  for (int c = 0; c < N; c++) {
    int K, I;

    if (scanf("%d", &K) != 1) return 1;
    if (scanf("%d", &I) != 1) return 1;

    int *guiche = malloc(K * sizeof(int));

    for (int i = 0; i < K; i++) {
      if (scanf("%d", &guiche[i]) != 1) return 1;
    }

    int x = I;
    int guiche_percorrido[K];
    int found = 0;
    int num_iterations = 0;

    while (!found && num_iterations < K) {
      guiche_percorrido[num_iterations] = x;

      x = guiche[x];

      for (int i = 0; i < num_iterations; i++) {
        if (guiche_percorrido[i] == x) {
          found = 1;
          break;
        }
      }

      num_iterations++;
    }

    for (int j = 0; j < num_iterations; j++) {
      printf("%d ", guiche_percorrido[j]);
    }
    printf("\n");

    free(guiche);
  }

  return 0;
}
