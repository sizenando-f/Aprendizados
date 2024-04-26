#include <stdio.h>
#include <stdlib.h>
// f = inicio, r = retaguarda, fila vazia f e r = 0, fila cheia r mod M + 1 = f, M = tamanho da fila?

int inserir(int fila[], int n, int *f, int *r, int valor){
  int temp = *r % n + 1;
  if(temp != *f){
    *r = temp;
    fila[*r] = valor;
    if(*f == -1){
      *f = 0;
    }
    return 1;
  }
  return 0;
}

int remover(int n, int *f, int *r){
  if(*f != -1){
    if(*f == *r){
      *f = -1;
      *r = -1;
    } else {
      *f = *f % n + 1;
    }
    return 1;
  }
  return 0;
}

int main(){
  int n = 10, f = -1, r = -1;
  int *fila = (int*) malloc(n*sizeof(int));

  inserir(fila, n, &f, &r, 1);
  inserir(fila, n, &f, &r, 4);
  inserir(fila, n, &f, &r, 2);
  inserir(fila, n, &f, &r, 6);
  remover(n, &f, &r);
  remover(n, &f, &r);

  for(int i = f; i <= r; i++){
    printf("%d ", fila[i]);
  }

  free(fila);
  return 0;
}