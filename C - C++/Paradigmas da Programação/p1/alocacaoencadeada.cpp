#include <iostream>

using namespace std;

class No{
  public:
    int valor;
    No *prox;
    No(const int valor): valor(valor), prox(NULL){};
};

class Lista{
  No *head;
  public:
    Lista(): head(NULL){};

    ~Lista(){
      No *temp = head;
      while(head != NULL){
        temp = head;
        head = head->prox;
        delete temp;
      }
    }

    void insereNo(int valor){
      No* novoNo = new No(valor);
      if(head == NULL){
        head = novoNo;
      } else {
        No *temp = head;
        while(temp->prox != NULL){
          temp = temp->prox;
        }
        temp->prox = novoNo;
      }
    }

    int removeNo(int valor){
      if(head == NULL) return 0;
      No *temp = head, *temp2 = NULL;

      if(head->valor == valor){
        head = head->prox;
        delete temp;
        return 1;
      }


      while(temp != NULL){
        if(temp->valor == valor){
          temp2->prox = temp->prox;
          delete temp;
          return 1;
        }
        temp2 = temp;
        temp = temp->prox;
      }

      return 0;
    }

    void exibir(){
      No *temp = head;
      while(temp != NULL){
        cout << temp->valor << ' ';
        temp = temp->prox;
      }
    }
};

int main(){
  Lista l1;
  l1.insereNo(3);
  l1.insereNo(9);
  l1.insereNo(20);
  l1.removeNo(9);
  l1.removeNo(3);
  l1.insereNo(69);

  l1.exibir();
  return 0;
}