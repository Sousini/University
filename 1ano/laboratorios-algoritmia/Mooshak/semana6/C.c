#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct info_pedido {
    char dificuldade;
    int ordem;
    int preco;
};

// A função compare deve receber ponteiros para os elementos que serão comparados
int compare(const void *a, const void *b) {
  //converte os ponteiros para ponteiros do tipo struct info_pedido
  const struct info_pedido *pedido1 = (const struct info_pedido*) a;
  const struct info_pedido *pedido2 = (const struct info_pedido*) b;
  //diferença entre os preços de 2 pedidos
  int d_preco = (pedido1 -> preco - pedido2 -> preco);

  if(d_preco != 0) { // != 0 -> retorna o valor negativo para o pedido com maior preço ficar em primeiro
    return -d_preco; // + -> pedido 1 < pedido 2; - -> pedido 1 > pedido 2
  } else if(pedido1 -> dificuldade != pedido2 -> dificuldade) { // caso o preço não seja igual verifica se a dificuldade é diferente
    return pedido1 -> dificuldade - pedido2 -> dificuldade; // retorna a diferença para o com menor dificuldade ficar em primeiro na ordenação (+ -> pedido 1 > 2)
          } else {
              return pedido1 -> ordem - pedido2 -> ordem; // se o preço e a dificuldade forem iguais retorna a diferença entre as ordens para ficar o pedido mais antigo em cima
          } 
}

int main() {
    int N;

    if(scanf("%d", &N) != 1) return 1;

    struct info_pedido pedidos[100]; // array pedidos do tipo struct info_pedido

    for(int i = 0; i < N; i++) {
        if(scanf("%d %c %d", &pedidos[i].ordem, &pedidos[i].dificuldade, &pedidos[i].preco) != 3) { 
            return 1; // Verifica se a leitura foi bem sucedida
        }
    }

    // Ordena o vetor usando a função compare como critério de ordenação
    qsort(pedidos, N, sizeof(struct info_pedido), compare);

    // Imprime o resultado
    for(int i = 0; i < N; i++) {
        printf("%d %c %d\n", pedidos[i].ordem, pedidos[i].dificuldade, pedidos[i].preco);
    }

    return 0;
}
