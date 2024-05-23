#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class OrderedDinamicArray {
  unsigned size;  // Tamanho do vetor
  unsigned nElem; // Número de elementos
  T *_data; // Ponteiro para vetor
  int inicio;
  int fim;

  void resize(unsigned newSize){
    T *pAux = new T[newSize];
    memcpy(pAux, _data, nElem * sizeof(T));
    delete[] _data;
    _data = pAux;
    size = newSize;
  }
  
  void mySwap(T &a, T &b){
      register T aux;
      
      aux = a;
      a = b;
      b = aux;
  }

  void restartList(){
    fim = nElem;
    resize(size*2);
    inicio = size-1;
    for(int i = fim; i < size-1; i++){
      _data[i] = 0;
    }
  }

  T operator[](unsigned i) const {  // Faz a mesma coisa que a função at
    return _data[i];
  }

public:
  OrderedDinamicArray(): size(2), _data(new T[size]), nElem(0), inicio(0), fim(1){
  }

  ~OrderedDinamicArray(){
    if(_data) delete []_data;
  }

  unsigned getSize() const {
    return size;
  }

  unsigned getNElem() const {
    return nElem;
  }

  T at(unsigned i) const {
    return _data[i];
  }

  bool search(T key, unsigned &index){
    index = 0;
    while(index < nElem){
      if(key == _data[index]){
        return true;
      }
      index++;
    }
    return false;
  }

  bool search(T key){
    unsigned none;
    return search(key, none);
  }

  void insert(T elem){
    unsigned i;
    if(nElem == size){
      resize(size*2);
    }
      i = nElem;
      _data[nElem++] = elem;
      while(i > 0 && elem < _data[i-1]){
        mySwap(_data[i], _data[i-1]); // Trocar elementos para manter a ordem
        i--;
      }
  }

  void removeMax(){
    nElem = nElem ? nElem-1 : 0;
    if(size > 0 && size-nElem > size/2){
        resize(size/2);
    }
  }

  void removeMin(){
    if(nElem > 0){
      for(unsigned i = 0; i < nElem - 1; ++i){
        _data[i] =  _data[i + 1];
      }
      --nElem;
      if(size > 0 && size-nElem > size/2){
        resize(size/2);
    }
    }
  }

  void removeFromKey(T key){
    unsigned i;
    if(search(key, i)){
      for(i=key-1; i < nElem - 1; ++i){
        _data[i] =  _data[i + 1];
      }
      --nElem;
    if(size > 0 && size-nElem > size/2){
        resize(size/2);
    }
    }
  }
};

int main(){
  int i;
  OrderedDinamicArray<int> vet;

  return 0;
}