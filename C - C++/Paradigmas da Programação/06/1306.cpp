#include <iostream>

using namespace std;

template <class K, class V>
class Map{
  K keyArray[10];
  V valueArray[10];
  unsigned nElem;

  bool findKey(K key, unsigned &i) const {
    if(!nElem) return false;
    i = 0;
    for(auto k : keyArray){
      if(key == k){
        return true;
      }
      i++;
    }
    return false;
  }

  public:
    Map(): nElem(0){}; 

    bool findKey(K key) const {
      unsigned index;
      if(findKey(key, index)){
        return true;
      } else {
        return false;
      }
    }

    bool insert(K key, V value){
      if(nElem > 10) return false;

      if(!findKey(key)){
        keyArray[nElem] = key;
        valueArray[nElem] = value;
        nElem++;
        return true;
      } else {
        return false;
      }
    }

    bool deleteFromKey(K key){
      if(!nElem) return false;
      unsigned index;
      if(findKey(key, index)){
        for(unsigned i = index; i < nElem; i++){
          keyArray[i] = keyArray[i+1];
          valueArray[i] = valueArray[i+1];
        }
        return true;
      } else {
        return false;
      }
    }

    V& at(K key){
      unsigned index;
      if(findKey(key, index)){
        return valueArray[index];
      }
      throw "Key not found\n";
    }
};

int main(){
  Map<char, int> vetor;
  vetor.insert('S', 1);
  vetor.insert('I', 2);
  vetor.insert('Z', 3);
  vetor.insert('E', 4);
  vetor.insert('N', 5);
  vetor.insert('A', 6);
  vetor.insert('D', 7);
  vetor.insert('O', 8);

  cout << vetor.at('E');
  return 0;
}