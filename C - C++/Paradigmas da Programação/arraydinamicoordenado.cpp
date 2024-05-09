#include <iostream>
#include <cstring>

using namespace std;

class OrderedDinamicArray {
  unsigned size;  // Tamanho do vetor
  unsigned nElem; // Número de elementos
  int *_data; // Ponteiro para vetor
  int inicio;
  int fim;

  void resize(unsigned newSize){
    int *pAux = new int[newSize];
    memcpy(pAux, _data, nElem * sizeof(int));
    delete[] _data;
    _data = pAux;
    size = newSize;
  }
  
  void mySwap(int &a, int &b){
      register int aux;
      
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

public:
  OrderedDinamicArray(): size(2), _data(new int[size]), nElem(0), inicio(0), fim(1){
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

  int at(unsigned i) const {
    return _data[i];
  }

  bool search(int key, unsigned &index){
    index = 0;
    while(index < nElem){
      if(key == _data[index]){
        return true;
      }
      index++;
    }
    return false;
  }

  bool search(int key){
    unsigned none;
    return search(key, none);
  }

  void insert(int elem){
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

  void removeFromKey(int key){
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

  void insertBegin(int valor){
    if(nElem == 0){
      _data[inicio] = valor;
      nElem++;
      inicio--;
      return;
    }

    if(inicio < 0){
      inicio = size-1;
    }

    if(nElem == size) restartList();
    
    _data[inicio] = valor;
    inicio--;

    nElem++;
  }

  void insertEnd(int valor){
    if(nElem == 0){
      _data[inicio] = valor;
      nElem++;
      inicio--;
      return;
    }

    if(nElem == size) restartList();

    _data[fim] = valor;
    fim++;
    if(fim >= size){
      fim = 0;
    }
    
    nElem++;
  }

  void removeEnd(){
    fim--;
    _data[fim] = 0;

    while(inicio > fim){
      _data[fim] = _data[inicio];
      _data[inicio] = 0;
      inicio++;
      fim++;
      if(inicio >= size){
        inicio = 0;
      }
    }

    if(size-nElem > size/2){
      resize(size/2);
    }

    inicio = size-1;
  }

  void removeBegin(){
    int aux = 0;
    _data[inicio] = 0;
    inicio++;

    while(inicio != fim){
      _data[aux] = _data[inicio];
      _data[inicio] = 0;
      inicio++;
      aux++;
    }

    if(size-nElem > size/2){
      resize(size/2);
    }

    inicio = size-1;
    fim = nElem;
  }
};

int main(){
  int i;
  OrderedDinamicArray vet;

  // for(i = 5; i > 0; i--){
  //   vet.insert(i);
  // }
  
  // vet.removeMin();
  // vet.removeMin();

  


  cout << "Tamanho do vetor: " << vet.getSize() << endl;

  for(i = 0; i < vet.getSize(); i++){
    cout << vet.at(i) << ' ';
  }
  

  return 0;
}