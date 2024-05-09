#include <stdio.h>
#include <stdlib.h>

struct Lista{
  int num;
  struct Lista *prox;
};

void inserir(struct Lista **inicio, int num){
  struct Lista *ptr = malloc(sizeof(struct Lista));
  ptr->num = num;
  ptr->prox = *inicio;
  *inicio = ptr;
}

void remover(struct Lista **inicio, int num){
  struct Lista *ptr = *inicio;
  struct Lista *ant = NULL;

  while(ptr != NULL){
    if(ptr->num == num){
      if(ant == NULL){
        *inicio = ptr->prox;
      } else {
        ant->prox = ptr->prox;
      }
      free(ptr);
      return;
    }
    ant = ptr;
    ptr = ptr->prox;
  }
}

int main(){
  struct Lista *L = NULL;
  struct Lista *p;

  inserir(&L, 1);
  inserir(&L, 2);
  inserir(&L, 3);
  remover(&L, 1);

  p = L;
  while(p != NULL){
    printf("%d ", p->num);
    p = p->prox;
  }

  return 0;
}