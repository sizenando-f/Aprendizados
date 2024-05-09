#include <iostream>
#define MAX_MAP_SIZE 10;

using namespace std;

template <class K, class V>
class Map{
  K keyArray[MAX_MAP_SIZE];
  V valueArray[MAX_MAP_SIZE];
  unsigned nElem;

  bool findKey(K key, unsigned &index){
    index = 0;
    while(index < nElem){
      if(key == keyArray[index]){
        return true;
      }
      index++;
    }
    return false;
  }

  public:
    Map():nElem(0){};

    bool findKey(K key){
      unsigned i;
      return findKey(key, i);
    }

    bool insert(K key, V value){
      if(nElem >= MAX_MAP_SIZE){ // Mapa cheio
        return false;
      }
      if(findKey(key)){
        return false;
      }
      keyArray[nElem] = key;
      valueArray[nElem] = value;
      nElem++;
      return true;
    }

    bool deleteFromKey(K key){
      unsigned index;

      if(!findKey(key, index)){
        return false;
      }
      nElem--;
      if(index != nElem){
        keyArray[index] = keyArray[nElem];
        valueArray[index] = valueArray[nElem];
      }

      return true;
    }

    V& at(K key){
      unsigned index;
      if(findKey(key, index)){
        return valueArray[index];
      }
      throw "Map ERROR: key not found!!!";
    }

};

int main(){
  
  return 0;
}