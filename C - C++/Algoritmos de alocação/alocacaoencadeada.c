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
  
}

int main(){
  struct Lista *L = NULL;
  struct Lista *p;

  inserir(&L, 1);
  inserir(&L, 2);
  inserir(&L, 3);

  p = L;
  while(p != NULL){
    printf("%d ", p->num);
    p = p->prox;
  }

  return 0;
}