#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct info_cozinheiro {
  char alcunha[20];
  int peso;
  int altura;
};

// A função compare recebe ponteiros para os elementos que serão comparados
int compare(const void *a, const void *b) {
  const struct info_cozinheiro *cozinheiro1 = (const struct info_cozinheiro*) a;
  const struct info_cozinheiro *cozinheiro2 = (const struct info_cozinheiro*) b;

  //calcular a diferença entre o peso do cozinheiro e o peso ideal
  int d_peso1 = abs(cozinheiro1->peso - 90); 
  int d_peso2 = abs(cozinheiro2->peso - 90);
  
  
  if(d_peso1 == d_peso2) { // pesos iguais
    if(cozinheiro1->altura == cozinheiro2->altura) { // alturas iguais
      return strcmp(cozinheiro1->alcunha, cozinheiro2->alcunha); // se ambos o peso e a altura forem iguais compara as alcunhas
    }
    else { // alturas diferentes
      return cozinheiro2->altura - cozinheiro1->altura; //se for positivo cozinheiro1, se for negativo cozinheiro2
    }
  } 
  else { // pesos diferentes
    return d_peso1 - d_peso2; //se for positivo cozinheiro1, se for negativo cozinheiro2
  }
}


int main() {
  int N; 

  if(scanf("%d", &N) != 1) return 1;
  
  struct info_cozinheiro cozinheiros[100]; //array do tipo struct info_cozinheiros

  for(int i = 0; i < N; i++) {
    if(scanf("%s %d %d", cozinheiros[i].alcunha, &cozinheiros[i].peso, &cozinheiros[i].altura) != 3) {
      return 1; // Verifica se a leitura foi bem sucedida
    }
  } 

  // Ordena usando a função compare como critério de ordenação
  qsort(cozinheiros, N, sizeof(struct info_cozinheiro), compare);

  // Imprime o resultado
  for(int i = 0; i < N; i++) {
    printf("%s %d %d\n", cozinheiros[i].alcunha, cozinheiros[i].peso, cozinheiros[i].altura);
  }

  return 0;
}
