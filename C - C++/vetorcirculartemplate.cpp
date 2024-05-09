#include <iostream>
#include <cstring>

using namespace std;

template <class T = int>
class circularDinamicList{
  T *ptr;
  int front;
  int back;
  unsigned blockSize;

  void resizeBlock(unsigned newSize){
    T *pAux = new T[newSize]; 
    if(front < back){
      memcpy(pAux, ptr + front, (back - front)*sizeof(T));
      back = back - front + 1;
      front = 0;
    } else if(front > back) {
      memcpy(pAux, ptr + front, (blockSize - front)*sizeof(T));
      memcpy(pAux + blockSize - front, ptr, (back)*sizeof(T));
      back = blockSize - front - back + 1;
      front = 0;
    }
    delete [] ptr;
    ptr = pAux;
    blockSize = newSize;
  }

  public:
    circularDinamicList():front(0), back(0), blockSize(2){
        ptr = new T[blockSize];
    };

    ~circularDinamicList(){
      delete [] ptr;
    }

    bool isEmpty() const {
      return front == back;
    }

    T getFront() const {
      return ptr[front];
    }

    T getBack() const {
      return ptr[back-1];
    }

    void pushFront(T elem){
      if((back+1) % blockSize == front){
        resizeBlock(blockSize*2);
      }
      // front = (front - 1 + blockSize) % blockSize;

      front = front == 0 ? blockSize - 1 : front - 1;
      
      ptr[front] = elem;
    }
    
    void pushBack(T elem){
      if((back+1) % blockSize == front){
        resizeBlock(blockSize*2);
      }

      ptr[back] = elem;

      back = (back + 1) % blockSize;
    }

    bool popFront(){
      int nElem = 0;
      if(front < back){ 
        nElem = back - front;
      } else if(front > back){
        nElem = blockSize - (front - back);
      } else {
        return false;
      }

      if((blockSize-1)/2 > nElem){
        resizeBlock(blockSize/2);
      }

      front = (front + 1) % blockSize;
      return true;
    }

    bool popBack(){
      int nElem = 0;
      if(front < back){ 
        nElem = back - front;
      } else if(front > back){
        nElem = blockSize - (front - back);
      } else {
        return false;
      }

      if((blockSize-1)/2 > nElem){
        resizeBlock(blockSize/2);
      }

      back = back == 0 ? blockSize - 1 : back - 1;
      return true;
    }

    void print(){
      cout << "F: " << front << ", B: " << back << ", blockSize: " << blockSize << endl;
      for(int i = 0; i < blockSize; i++){
        cout << ptr[i] << ", ";
      }
      cout << endl;
    }
};

int main(){
  // ! 5 sobrescreveu o 2
  circularDinamicList<int> cList;

  // cList.pushBack(1);
  // cList.pushBack(2);
  cList.pushBack(1);
  cList.pushFront(2);
  cList.pushFront(3);
  cList.pushFront(4);
  cList.pushBack(5);
  cList.print();

  return 0;
}