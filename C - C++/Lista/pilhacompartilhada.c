#include <stdio.h>

void inicializa(int vet[]){
  int tam = 10;
  for(int i = 0; i < tam; i++){
    vet[i] = 0;
  }
}

void insereLista(int vet[], int pilha, int x, int *topo1, int *topo2){
  if(*topo1 == *topo2){
    printf("Pilha cheia");
    return;
  }

  if(pilha){ // 1 = Esquerda
    *topo1 = *topo1 + 1;
    vet[*topo1] = x;
  }else{  // 0 = Direita
    vet[*topo2] = x;
    *topo2 = *topo2 - 1;
  }
}

int main(){
  int tam = 10;
  int vet[tam];
  int topo1 = -1, topo2 = tam - 1;
  inicializa(vet);

  insereLista(vet, 0, 10, &topo1, &topo2);
  insereLista(vet, 0, 12, &topo1, &topo2);
  insereLista(vet, 1, 2, &topo1, &topo2);
  insereLista(vet, 1, 9, &topo1, &topo2);
  insereLista(vet, 1, 1, &topo1, &topo2);
  insereLista(vet, 1, 29, &topo1, &topo2);
  insereLista(vet, 1, 3, &topo1, &topo2);
  insereLista(vet, 1, 5, &topo1, &topo2);
  insereLista(vet, 1, 7, &topo1, &topo2);
  insereLista(vet, 1, 99, &topo1, &topo2);


  for(int i = 0; i < tam; i++){
    printf("%d - ", vet[i]);
  }
  return 0;
}