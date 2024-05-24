
#include <iostream>
using namespace std;

template <class T = int>
class DPilha{
  T vet[5];
  unsigned topo;

  public:
  DPilha(): topo(0){
  }

  DPilha(const T &val): topo(5){
    for(unsigned i = 0; i < topo; i++){
      vet[i] = val;
    }
  }

  bool push(const T &val){
    if(topo >= 5){
      return false;
    }
    vet[topo++] = val;
    return true;
  }

  bool pop(){
    if(topo == 0){
      return false;
    }
    topo--;
    return true;
  }

  T top() const{
    return vet[topo-1];
  }

  DPilha& operator<<(const T &val){
    push(val);
    return *this;
  }

  DPilha& operator>>(T &val){
    val = top();
    pop();
    return *this;
  }

};

int main(){
  DPilha<int> iPilha;
  int num1, num2, num3;
  
  iPilha << 10 << 8 << 5;
  iPilha >> num1 >> num2 >> num3;
  cout << num1 << ' ' << num2 << ' ' << num3 << endl;
  return 0;
}