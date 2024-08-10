#include <stdio.h>
#include <stdlib.h>

struct No{
  int chave;
  struct No *dir;
  struct No *esq;
};

void inserir(int x, struct No **ptr){
  if((*ptr) == NULL){
    struct No *novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->chave = x;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    (*ptr) = novoNo;
    return;
  }
  if(x < (*ptr)->chave){
    inserir(x, &(*ptr)->esq);
  }else if(x > (*ptr)->chave){
    inserir(x, &(*ptr)->dir);
  }
}

void preOrdem(struct No *ptr){
  printf("%d -> ", ptr->chave);
  if(ptr->esq != NULL){
    preOrdem(ptr->esq);
  }
  if(ptr->dir != NULL){
    preOrdem(ptr->dir);
  }
  
}

void desalocaArvore(struct No **ptr){
  if((*ptr)->esq != NULL){
    desalocaArvore(&(*ptr)->esq);
  }
  if((*ptr)->dir != NULL){
    desalocaArvore(&(*ptr)->dir);
  }
  free((*ptr));
  (*ptr) = NULL;
}

int main(){
  struct No *ptr = NULL;
  inserir(10, &ptr);
  inserir(20, &ptr);
  inserir(8, &ptr);
  inserir(8, &ptr);
  desalocaArvore(&ptr);
  
  struct No *tmp = ptr;
  preOrdem(tmp);

  return 0;
}