#include <iostream>

using namespace std;

class circularDinamicList(){
  int *ptr;
  int front, back;
  unsigned blockSize;

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
};

int main(){

  return 0;
}