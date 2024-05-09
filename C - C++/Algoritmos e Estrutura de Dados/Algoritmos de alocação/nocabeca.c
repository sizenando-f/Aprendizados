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

void finaliza(struct Lista **inicio){
  struct Lista *ptr = *inicio;
  struct Lista *no;

  while(ptr != NULL){
    no = ptr;
    ptr = ptr->prox;
    free(no);
  }
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

void removeNo(int x, struct Lista **L){
  struct Lista *ant, *pont;
  buscaEnc(x, L, &ant, &pont);

  if(pont != NULL){
    ant->prox = pont->prox;
    free(pont);
  } else {
    printf("Elemento nao esta na tabela\n");
  }
}

void imprimeNo(struct Lista **L){
  struct Lista *ptr = *L;
  if((*L) == NULL){
    return;
  }

  printf("%d -> ", (*L)->chave);

  imprimeNo(&ptr->prox);
}

int main(){
  struct Lista *ptr1, *ptr2;
  inicializa(&ptr1);
  inicializa(&ptr2);


  insereNo(1, &ptr1);
  insereNo(4, &ptr1);
  insereNo(2, &ptr1);
  insereNo(3, &ptr1);
  insereNo(1, &ptr1);
  insereNo(3, &ptr1);
  insereNo(6, &ptr1);
  insereNo(5, &ptr1);
  removeNo(6, &ptr1);
  removeNo(4, &ptr1);
  insereNo(4, &ptr1);
  removeNo(9, &ptr1);

  insereNo(7, &ptr2);
  insereNo(5, &ptr2);
  insereNo(9, &ptr2);
  insereNo(1, &ptr2);

  struct Lista *p1 = ptr1->prox;
  imprimeNo(&p1);
  printf("\n\n");

  // struct Lista *p2 = ptr2->prox;

  finaliza(&ptr1);
  finaliza(&ptr2);
  return 0;
}