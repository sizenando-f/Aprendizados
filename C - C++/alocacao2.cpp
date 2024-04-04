#include <iostream>

using namespace std;

class FixedSizeArray {
  unsigned size;
  int *_data;

  public:
    FixedSizeArray(unsigned size = 10): size(size), _data(new int[size]){
    }

    ~FixedSizeArray(){
      if(_data) delete []_data;
    }

    unsigned getSize() const {
      return size;
    }

    int& at(unsigned i) const {
      return _data[i];
    }

};

int main(){
  int i;
  FixedSizeArray vet(5);

  for(i = 0; i < 5; i++){
    vet.at(i) = i + 1;
  }

  for(i = 0; i < 5; i++){
    cout << vet.at(i) << ' ';
  }

  return 0;
}