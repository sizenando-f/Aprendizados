#include <stdio.h>
#include <stdlib.h>


int inserir(int pilha[], int n, int topo, int valor){
  if(topo != n){
    topo++;
    pilha[topo] = valor;
    return topo;
  }
  return 0;
}

int remover(int topo){
  if(topo != 0){
    topo--;
    return topo;
  }

  return 0;
}

int main(){
  int n = 10, topo = -1;
  int *pilha = (int*) malloc(n*sizeof(int));

  topo = inserir(pilha, n, topo, 1);
  topo = inserir(pilha, n, topo, 2);
  topo = inserir(pilha, n, topo, 5);
  topo = remover(topo);
  topo = inserir(pilha, n, topo, 3);

  printf("Topo: %d\n", topo+1);
  for(int i = 0; i <= topo; i++){
    printf("%d ", pilha[i]);
  }

  free(pilha);
  return 0;
}