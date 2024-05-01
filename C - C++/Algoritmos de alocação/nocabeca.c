#include <stdio.h>
#include <stdlib.h>

struct Lista {
  int chave;
  struct Lista *prox;
};

void buscaEnc(int x, struct Lista **L, struct Lista **ant, struct Lista **pont){
  *ant = *L;
  *pont = NULL;
  struct Lista *ptr = (*L)->prox;
  while(ptr != NULL){
    if(ptr->chave < x){
      *ant = ptr;
      ptr = ptr->prox;
    } else if(ptr->chave == x){
      *pont = ptr;
    } else {
      ptr = NULL;
    }
  }
}

void insereNo(int x, struct Lista **L){
  struct Lista *ant, *pont;
  buscaEnc(x, L, &ant, &pont);
  if(pont == NULL){
    struct Lista *pt = malloc(sizeof(struct Lista));
    pt->chave = x;
    pt->prox = ant->prox;
    ant->prox = pt;
  } else {
    printf("Elemento ja esta na tabela\n");
  }
}

int main(){
  struct Lista *inicio;
  struct Lista no;
  no->
  return 0;
}