#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct info_cozinheiro {
  char alcunha[20];
  int peso;
  int altura;
};

// A função compare deve receber ponteiros para os elementos que serão comparados
int compare(const void *a, const void *b) {
  // Converte os ponteiros para o tipo correto
  const struct info_cozinheiro *cozinheiro1 = (const struct info_cozinheiro*) a;
  const struct info_cozinheiro *cozinheiro2 = (const struct info_cozinheiro*) b;

  // Calcula as diferenças de peso e altura em relação ao valor desejado
  int d_peso1 = abs(cozinheiro1->peso - 90); 
  int d_peso2 = abs(cozinheiro2->peso - 90);
  int d_alt = abs(cozinheiro2->altura - cozinheiro1->altura);

  // Verifica se os pesos são iguais
  if(d_peso1 == 0 && d_peso2 == 0) {
    // Compara as alturas
    if(d_alt > 0) {
      return cozinheiro2->altura - cozinheiro1->altura; 
    } else {
      // Se as alturas forem iguais, compara as alcunhas
      return strcmp(cozinheiro1->alcunha, cozinheiro2->alcunha);
    }
  } else {
    // Se os pesos são diferentes, retorna a diferença menor
    return d_peso1 - d_peso2;
  }
}

int main() {
  int N; 

  if(scanf("%d", &N) != 1) return 1;
  
  struct info_cozinheiro cozinheiros[100];

  for(int i = 0; i < N; i++) {
    if(scanf("%s %d %d", cozinheiros[i].alcunha, &cozinheiros[i].peso, &cozinheiros[i].altura) != 3) {
      return 1; // Verifica se a leitura foi bem sucedida
    }
  } 

  // Ordena o vetor usando a função compare como critério de ordenação
  qsort(cozinheiros, N, sizeof(struct info_cozinheiro), compare);

  // Imprime o resultado
  for(int i = 0; i < N; i++) {
    printf("%s %d %d \n", cozinheiros[i].alcunha, cozinheiros[i].peso, cozinheiros[i].altura);
  }

  return 0;
}
