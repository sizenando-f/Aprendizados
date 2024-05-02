#include <stdio.h>
#include <stdlib.h>

struct Lista {
  int chave;
  struct Lista *prox;
};

void inicializa(struct Lista **inicio){
  *inicio = (struct Lista *) malloc(sizeof(struct Lista));
  (*inicio)->prox = NULL;
}

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
      return;
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
  inicializa(&inicio);

  insereNo(1, &inicio);
  insereNo(4, &inicio);
  insereNo(2, &inicio);
  insereNo(3, &inicio);
  insereNo(1, &inicio);
  insereNo(3, &inicio);
  insereNo(6, &inicio);
  insereNo(5, &inicio);

  struct Lista *p = inicio->prox;

  while(p != NULL){
    printf("%d -> ", p->chave);
    p = p->prox;
  }

  free(inicio);
  return 0;
}