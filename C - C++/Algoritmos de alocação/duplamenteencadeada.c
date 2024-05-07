#include <stdio.h>
#include <stdlib.h>

struct Lista {
  int chave;
  struct Lista *ant;
  struct Lista *prox;
};

void insereNo(struct Lista **L, int x){
  struct Lista *ptr = *L;
  if(ptr == NULL){
    ptr->ant = NULL;
    ptr->chave = x;
    ptr->prox = NULL;
    return;
  }

  while(ptr->prox != NULL){
    ptr = ptr->prox;
  }
  struct Lista *p = (struct Lista *) malloc(sizeof(struct Lista));
  p->ant = ptr;
  p->chave = x;
  p->prox = NULL;
}

void desaloca(struct Lista **L){
  struct Lista *ptr = *L, *temp;
  while(ptr != NULL){
    temp = ptr;
    ptr = ptr->prox;
    free(temp);
  }
}

int main(){
  struct Lista *L = NULL;

  insereNo(&L, 10);

  struct Lista *ptr = L;
  
  while(ptr != NULL){
    printf("Entrou");
    printf("%d -> ", ptr->chave);
  }

  desaloca(&L);
  return 0;
}