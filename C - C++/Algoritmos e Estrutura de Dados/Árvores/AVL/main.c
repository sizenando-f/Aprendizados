#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura do nó.
 * @param chave Chave
 * @param bal Balanço
 * @param esq Ponteiro para nó esquerdo
 * @param esq Ponteiro para nó direito
 */
struct No{
  int chave;
  int bal;
  struct No *esq;
  struct No*dir;
};

/**
 * @brief Procedimento auxiliar para inserção do nó.
 * 
 * Aloca um novo nó e inicializa tanto a chave quanto os nós filhos e o balanço.
 * @param ptr Ponteiro para o onde deseja inserir o nó
 * @param x Valor da chave
 */
void inicioNo(struct No **ptr, int x){
  (*ptr) = (struct No*) malloc(sizeof(struct No));
  (*ptr)->chave = x;
  (*ptr)->dir = NULL;
  (*ptr)->esq = NULL;
  (*ptr)->bal = 0;
}

/**
 * @brief Procedimento auxiliar para rotação a direita
 * ou rotação dupla a direita.
 * 
 * @param pt Ponteiro para nó de rotação
 * @param h Controle para analisar nós
 */
void caso1(struct No **pt, int *h){
  struct No *ptu = (*pt)->esq;
  struct No *ptv;
  if(ptu->bal == -1){
    (*pt)->esq = ptu->dir;
    ptu->dir = (*pt);
    (*pt)->bal = 0;
    (*pt) = ptu;
  } else {
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    (*pt)->esq = ptv->dir;
    ptv->dir = (*pt);
    if(ptv->bal == -1){
      (*pt)->bal = 1;
    } else {
      (*pt)->bal = 0;
    }
    if(ptv->bal == 1){
      ptu->bal = -1;
    } else {
      ptu->bal = 0;
    }
  }
  (*pt)->bal = 0;
  *h = 0;
}

/**
 * @brief Procedimento auxiliar para rotação a esquerda
 * ou rotação dupla a esquerda.
 * 
 * @param pt Ponteiro para nó de rotação
 * @param h Controle para analisar nós
 */
void caso2(struct No **pt, int *h){
  struct No *ptu = (*pt)->dir;
  struct No *ptv;
  if(ptu->bal == 1){
    (*pt)->dir = ptu->esq;
    ptu->esq = (*pt);
    (*pt)->bal = 0;
    (*pt) = ptu;
  } else {
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    (*pt)->dir = ptv->esq;
    ptv->esq = (*pt);
    if(ptv->bal == 1){
      (*pt)->bal = -1;
    } else {
      (*pt)->bal = 0;
    }
    if(ptv->bal == -1){
      ptu->bal = 1;
    } else {
      ptu->bal = 0;
    }
  }
  (*pt)->bal = 0;
  *h = 0;
}

/**
 * @brief Faz a busca e inserção de um nó na árvore. 
 * 
 * Busca pela chave X e durante a busca é conhecido o caminho do novo nó ptr até a raíz.
 * Se X não existir então um novo nó é alocado.
 * Após a inserção, o caminho inverso é feito (volta da recursão):
 * O balanço (campo bal) é acertado; se necessário a rotação será feita.
 * 
 * @param x Chave a ser inserida.
 * @param ptr Ponteiro para nó raíz.
 * @param h Indica se nós ancestrais devem ser analisados.
 *
 * #### Exemplo de chamada externa
 * 
 * insAVL(10, &raiz, altura);
 * 
 * Isso insere o valor 10 na árvore AVL.
 */
void insAVL(int x, struct No **ptr, int *h){
  if((*ptr) == NULL){
    inicioNo(&(*ptr), x);
    *h = 1;
  } else if(x == (*ptr)->chave) return;

  if(x < (*ptr)->chave){
    insAVL(x, &(*ptr)->esq, h);
    if(*h){
      switch ((*ptr)->bal){
      case 1:
        (*ptr)->bal = 0; *h = 0;
        break;
      case 0:
        (*ptr)->bal = -1;
        break;
      case -1:
        caso1(&(*ptr), h);  // Rebalanceamento
        break;
      default:
        break;
      }
    }
  } else {
    insAVL(x, &(*ptr)->dir, h);
    if(*h){
      switch((*ptr)->bal){
      case -1:
        (*ptr)->bal = 0; *h = 0;
        break;
      case 0:
        (*ptr)->bal = 1;
        break;
      case 1:
        caso2(&(*ptr), h);  // Rebalanceamento
      default:
        break;
      }
    }
  }
}

int main(){
  return 0;
}