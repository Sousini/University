#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  int N;

  //numero de linhas
  if(scanf("%d", &N) != 1) return 1;

  char linha[1001];
  int max_nomes = 40;
  int max_name_len = 21;
  char nomes[max_nomes][max_name_len];


  for(int l = 0; l < N; l++) {
    if(fgets(linha, sizeof(linha), stdin) == NULL) return 1;
    
    int num_nomes = 0;
    char *token = strtok(linha, " ");
    while (token != NULL && num_nomes < max_nomes) {
      sscanf(token, "%s", &nomes[num_nomes]);
      num_nomes++;
      token = strtok(NULL, " ");
    }

    
    

   
    
  
    
 

  }
}

