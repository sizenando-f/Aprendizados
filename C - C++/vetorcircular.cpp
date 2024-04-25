#include <iostream>

using namespace std;

class circularDinamicList(){
  int *ptr;
  int head, tail;
  unsigned blockSize;

  public:
    circularDinamicList(): blockSize(2), head(0), tail(0), ptr(new int(blockSize));
};

int main(){

  return 0;
}