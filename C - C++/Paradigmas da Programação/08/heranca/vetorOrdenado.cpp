#include "vetorOrdenado.h"

void vetorOrdenado::insert(int n){
  unsigned i;
  int aux;

  push_back(n);
  i = size() - 1;

  while(i > 0){
    if(at(i) < at(i - 1)){
      aux = at(i);
      vector<int>::at(i) = at(i - 1);
      vector<int>::at(i - 1) = aux;
      --i;
    }
    else {
      i = 0;
    }
  }
}

int vetorOrdenado::at(unsigned int i){
    return vector<int>::at(i);
}