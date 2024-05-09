#include <stdio.h>

void insereDeque(int vet[], int x, int pos, int *esq, int *dir, int *n){
  int tam = 10;
  if(*esq == *dir){
    vet[*esq] = x;
    *dir = *dir + 1;
    *n = *n + 1;
    return;
  }

  if(pos){
    if(*dir == tam){
      printf("Lado direito cheio\n");
      return;
    }
    vet[*dir] = x;
    *dir = *dir + 1;
    *n = *n + 1;
  } else {
    if(*esq == 0){
      printf("Lado esquero está cheio\n");
      return;
    }
    *esq = *esq - 1;
    vet[*esq] = x;
    *n = *n + 1;
  }
}

int main(){
  int vet[10];
  int esq = 0, dir = 0, n = 0;
  insereDeque(vet, 10, 0, &esq, &dir, &n);
  insereDeque(vet, 20, 1, &esq, &dir, &n);

  for(int i = 0; i < n; i++){
    printf("%d -> ", vet[i]);
  }
  return 0;
}