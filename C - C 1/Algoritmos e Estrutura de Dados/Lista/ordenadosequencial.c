#include <stdio.h>

void insereElemento(int vet[], int elem, int *n){
  int tam = 10;
  int maior = 0;

  if(*n == 0){
    vet[*n] = elem;
    *n = *n + 1;
    return;
  } else if(*n == tam){
    printf("Vetor cheio");
    return;
  }

  for(int i = 0; i < *n; i++){
    if(vet[i] > elem){
      maior = i;
      i = *n;
    } else if(vet[i] < elem && *n - 1 == i){
      vet[i+1] = elem;
      *n = *n + 1;
      return;
    }
  }

  for(int i = tam-1; i > maior; i--){
    vet[i] = vet[i-1];
  }

  vet[maior] = elem;
  *n = *n + 1;
}

void removeElemento(int vet[], int elem, int *n){
  int tam = 10, indice;
  if(*n == 0){
    printf("Array vazio");
    return;
  }

  for(int i = 0; i < tam; i++){
    if(vet[i] == elem){
      indice = i;
      i = tam;
    }
    if(i == tam-1 && vet[i] != elem){
      printf("Elemento não está na lista\n\n");
      return;
    }
  }

  for(int i = indice; i < tam-1; i++){
    vet[i] = vet[i+1];
  }

  *n = *n - 1;
}

int main(){
  int vet[10];
  int n = 0;
  insereElemento(vet, 0, &n);
  insereElemento(vet, 2, &n);
  insereElemento(vet, 4, &n);
  insereElemento(vet, 1, &n);
  insereElemento(vet, 3, &n);
  removeElemento(vet, 3, &n);
  removeElemento(vet, 9, &n);
  removeElemento(vet, 0, &n);
  removeElemento(vet, -1, &n);
  removeElemento(vet, 2, &n);
  insereElemento(vet, 2, &n);
  insereElemento(vet, 20, &n);
  insereElemento(vet, 15, &n);

  for(int i = 0; i < n; i++){
    printf("%d -> ", vet[i]);
  }
  return 0;
}