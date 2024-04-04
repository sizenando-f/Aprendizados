#include <iostream>

using namespace std;

class OrderedDinamicArray {
  unsigned size;  // Tamanho do vetor
  unsigned nElem; // Número de elementos
  int *_data; // Ponteiro para vetor

  public:
    OrderedDinamicArray(): size(2), _data(new int[size]), nElem(0){
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
      while(key < nElem){
        if(key == _data[index]){
          return true;
        }
        index++
      }

      return false;
    }

    bool search(int key){
      unsigned none;
      return search(key, none);
    }

    void insert(int elem){
      unsigned i;
      if(nElem < size){
        i = nElem;
        _data[nElem++] = elem;
        while(_data[i] < _data[i-1] && i > 0){
          swap(_data[i], _data[--i]); // Testar --i
        }
      } else {
        // Redimensionar o array
      }
    }

    void removeMax(){
      nElem = nElem ? nElem-1 : 0;
      // Tratar o redimensionamento
    }

    void removeMin(){
      unsigned i;
      i = 0;
      --nElem;
      while(i < nElem - 1){
        _data[i] =  _data[++i]; // Testar ++i
      }
      // Tratar o redimensionamento
      
    }

    void removeFromKey(int key){
      unsigned i;
      if(search(key, i)){
        --nElem;
        while(i < nElem - 1){
          _data[i] =  _data[++i]; // Testar ++i
        }
      }
      // Tratar o redimensionamento
    }

};

int main(){
  int i;
  OrderedDinamicArray vet(5);

  for(i = 0; i < 5; i++){
    vet.at(i) = i + 1;
  }

  for(i = 0; i < 5; i++){
    cout << vet.at(i) << ' ';
  }

  return 0;
}