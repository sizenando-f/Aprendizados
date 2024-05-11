#include <stdio.h>
#include <stdlib.h>

struct Lista {
  int valor;
  int info;
  struct Lista *prox;
};

void iniciliza(struct Lista **inicio){
  (*inicio) = (struct Lista *) malloc(sizeof(struct Lista));
  (*inicio)->prox = (*inicio);
}

void inserir(struct Lista **inicio, int num){
  struct Lista *no = (struct Lista *) malloc(sizeof(struct Lista));
  no->valor = num;

  if((*inicio)->prox == (*inicio)){
    (*inicio)->prox = no;
    no->prox = (*inicio);
    return;
  }

  struct Lista *temp = (*inicio)->prox;
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

// Algoritmo de alteração do campo info
void alteraInfo(struct Lista **inicio, int no, int novaInfo){
  struct Lista *p = (*inicio)->prox;
  while(p != (*inicio)){
    if(p->valor == no){
      p->info = novaInfo;
      return;
    }
    p = p->prox;
  }
}

int main(){
  struct Lista *L = NULL;
  iniciliza(&L);

  struct Lista *p;
  inserir(&L, 10);
  inserir(&L, 20);
  inserir(&L, 2);

  p = L->prox;

  while(p != L){
    printf("%d -> ", p->valor);
    p = p->prox;
  }
  return 0;
}