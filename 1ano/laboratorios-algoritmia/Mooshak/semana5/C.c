#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_CHAR 50

int compara(int x, char a[], int N) {
  int freq = 0;
  for (int i = 0; i < N; i++) {
    if (a[x] == a[i]) {
      freq += 1; 
    }
  }
  return freq;
}

int main() {
  int N;
  char a[MAX_N];
  if (scanf("%d", &N) != 1) {
    return 1;
  }
  getchar(); // remove o caractere de nova linha do buffer

  for (int l = 0; l < N; l++) {
    for (int i = 0; i < MAX_CHAR; i++) {
      int c = getchar();
      if (c == EOF || c == '\n') {
        break;
      }
      a[l * MAX_CHAR + i] = c;
    }
  }

  int frequencia[MAX_CHAR] = {0};

  for (int j = 0; j < N * MAX_CHAR; j++) {
    frequencia[j % MAX_CHAR] += compara(j, a, N * MAX_CHAR);
  }

  int index = 0;
  for (int i = 0; i < MAX_CHAR; i++) {
    if (frequencia[i] > frequencia[index]) {
      index = i;
    }
  }

  printf("%s\n", a[index]);

  return 0;
}
