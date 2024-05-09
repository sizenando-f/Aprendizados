#include <stdio.h>

void insereElemento(int vet[], int elem, int *n){
  int tam = 10;
  if(*n == 0){
    vet[*n] = elem;
    *n++;
    return;
  }

  for(int i = 0; i < *n; i++){
    
  }
}

int main(){
  int vet[10];
  int n = 0;
  insereElemento(vet, 0, &n);
  return 0;
}