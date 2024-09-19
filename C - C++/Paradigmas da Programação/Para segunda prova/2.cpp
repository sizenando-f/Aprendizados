#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Reais{
  double valor;
  public:
  Reais():valor(0.0){};
  Reais(double r):valor(r){};

  virtual void setValor(const double n){
    valor = n;
  }

  double getValor() const {
    return valor;
  }
};

class Inteiros: public Reais{
  public:
  Inteiros(){setValor(0.0);};
  Inteiros(double n){
    if(modf(n, NULL) == 0.0){
      Reais::setValor(n);
    } else {
      throw invalid_argument("Valor nao eh inteiro\n");
    }
  };

  void setValor(const double n){
    if(modf(n, NULL) == 0.0){
      Reais::setValor(n);
    } else {
      throw invalid_argument("Valor nao eh inteiro\n");
    }
  }
};

class Naturais: public Reais{
  public:
  Naturais(){setValor(0);};
  Naturais(double n){
    if(modf(n, NULL) == 0.0 && n >= 0){
      Reais::setValor(n);
    } else {
      throw invalid_argument("Valor nao eh natural\n");
    }
  };

  void setValor(const double n){
    if(modf(n, NULL) == 0.0 && n >= 0){
      Reais::setValor(n);
    } else {
      throw invalid_argument("Valor nao eh natural\n");
    }
  }
};

int main(){
  Naturais n1(9);
  
  n1.setValor(-8);
  cout << n1.getValor();
  return 0;
}