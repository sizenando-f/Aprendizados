#include <iostream>

using namespace std;

class circularDinamicList(){
  int *ptr;
  int front, back;
  unsigned blockSize;

  void resizeBlock(unsigned newSize){

  }

  public:
    circularDinamicList(): blockSize(2), front(0), back(0), ptr(new int(blockSize)){};

    bool isEmpty() const {
      return front == back;
    }

    int getFront() const {
      return ptr[front];
    }

    int getBack() const {
      return ptr[back];
    }

    void pushFront(int elem){
      if((back+1) % blockSize == front){
        resizeBlock(blockSize*2);
      }
      // front = (front - 1 + blockSize) % blockSize;

      front = front == 0 ? blockSize - 1 : front - 1;
      
      ptr[front] = elem;
    }
    
    void pushBack(int elem){
      if((back+1) % blockSize == front){
        resizeBlock(blockSize*2);
      }

      ptr[back] = elem;

      back = (back + 1) % blockSize; //! ERRO AQUI, SEMPRE VAI RESETAR O BACK QUANDO PUSHBACK FOR CHAMADO MESMO QUE NÃO ESTEJA NO FIM
    }

    bool popFront(){
      int nElem = 0;
      if(front < back){ 
        nElem = back - front
      } else if(front > back){
        nElem = blockSize - (front - back);
      }

      if(blockSize/4 > nElem){
        resizeBlock(blockSize/2);
      }
    }

    bool popBack(){

    }
};

int main(){

  return 0;
}