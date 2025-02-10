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

void minimo(struct No **ptr){
  while((*ptr)->esq != NULL){
    (*ptr) = (*ptr)->esq;
  }
}

void maximo(struct No **ptr){
  if((*ptr)->dir != NULL){
    maximo(&(*ptr)->dir);
  }
}

void remover(int x, struct No **ptr){
  if((*ptr) == NULL){
    return;
  }
  if((*ptr)->chave == x){
    if((*ptr)->esq == NULL && (*ptr)->dir == NULL){
      free((*ptr));
      (*ptr) = NULL;
    } else if((*ptr)->esq == NULL && (*ptr)->dir != NULL){
      struct No *temp = (*ptr);
      (*ptr) = (*ptr)->dir;
      free(temp);
    } else if((*ptr)->esq != NULL && (*ptr)->dir == NULL){
      struct No *temp = (*ptr);
      (*ptr) = (*ptr)->esq;
      free(temp);
    } else {
      struct No *temp = (*ptr)->dir;
      struct No *min = NULL;

      // Encontrar o mínimo na subárvore direita
      while (temp->esq != NULL) {
          min = temp;
          temp = temp->esq;
      }

      // Substituir o valor do nó atual
      (*ptr)->chave = temp->chave;

      // Desconectar o nó mínimo da árvore
      if (min != NULL) {
          min->esq = temp->dir;
      } else {
          (*ptr)->dir = temp->dir;
      }

      free(temp);
    }
  }


  if(x < (*ptr)->chave){
    remover(x, &(*ptr)->esq);
  } else if(x > (*ptr)->chave){
    remover(x, &(*ptr)->dir);
  }
}

int main(){
  struct No *ptr = NULL;
  inserir(20, &ptr);
  inserir(6, &ptr);
  inserir(2, &ptr);
  inserir(9, &ptr);
  inserir(8, &ptr);


  remover(6, &ptr);
  
  struct No *tmp = ptr;
  preOrdem(tmp);

  desalocaArvore(&ptr);
  return 0;
}