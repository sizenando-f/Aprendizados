#include <stdio.h>
#include <stdlib.h>

struct Lista {
  int valor;
  struct Lista *prox;
};


void inserir(struct Lista **inicio, int num){
  struct Lista *no = (struct Lista *) malloc(sizeof(struct Lista));
  no->valor = num;
  no->prox = NULL;

  if((*inicio) == NULL){
    (*inicio) = no;
    no->prox = (*inicio);
    return;
  }

  struct Lista *temp = (*inicio);
  while(temp->prox != (*inicio)){
    temp = temp->prox;
  }
  
  temp->prox = no;
  no->prox = (*inicio);
}

void remover(struct Lista **inicio, int num){
  struct Lista *ptr = *inicio;
  struct Lista *ant = NULL;

  do{
    if(ptr->valor == num){
      if(ant == NULL){
        struct Lista *temp = (*inicio);
        while(temp->prox != (*inicio)){
          temp = temp->prox;
        }
        *inicio = ptr->prox;
        temp->prox = (*inicio);
      } else {
        ant->prox = ptr->prox;
      }
      free(ptr);
      return;
    }
    ant = ptr;
    ptr = ptr->prox;
  }while(ptr != (*inicio));
}

int main(){
  struct Lista *L = NULL;
  struct Lista *p;
  inserir(&L, 10);
  inserir(&L, 20);
  inserir(&L, 2);
  remover(&L, 10);
  remover(&L, 2);

  p = L;
  if(p != NULL){
    printf("%d -> ", p->valor);
    p = p->prox;
  }

  while(p != L){
    printf("%d -> ", p->valor);
    p = p->prox;
  }
  return 0;
}