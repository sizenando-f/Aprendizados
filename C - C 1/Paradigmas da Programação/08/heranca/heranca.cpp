#include <iostream>
#include "vetorOrdenado.h"

class Base{
  int seila;
  public:
    Base():seila(0){
      cout << "Base::Base()" << endl;
    }

    Base(int i):seila(i){
      cout << "Base::Base(int)" << endl;
    }

    int getSeila(){
      return seila;
    }
};

class Derivada : Base{  // Não é público por padrão
  public:
    Derivada(){
      cout << "Derivada::Derivada()" << endl;
    }
    Derivada(int i):Base(i){  // Chamou o construtor parametizado da base, precisa explicitar
      cout << "Derivada::Derivada(int)" << endl;
    }
};

int main(){
  Derivada obj(0);



  // vetorOrdenado obj;

  // obj.insert(3);
  // obj.insert(1);
  // obj.insert(5);
  // obj.insert(0);
  // obj.insert(2);

  // system("pause");
  return 0;
}
