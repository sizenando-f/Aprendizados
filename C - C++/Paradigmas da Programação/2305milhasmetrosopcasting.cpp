#include <iostream>
#define METROS_POR_MILHAS 1609.34

using namespace std;


class Metro{
  float medida;
  public:
    Metro(float medida = 0.0): medida(medida){}
    operator float() const { // Sobrecarga de casting
      return medida;
    }
};

class Milhas{
  float medida;
  public:
    Milhas(float medida = 0.0): medida(medida){};

    Milhas(const Metro &metro){
      medida = (float) metro/METROS_POR_MILHAS;
    }

    operator Metro(){
      return Metro(medida * METROS_POR_MILHAS);
    }
};

int main(){
  Metro me(100);
  Milhas mi;

  mi = me;
  me = mi;

  cout << me << endl;

  // me = 200;   // Construtor identifica float
  // cout << me << endl; // Operador de casting convertendo para float

  return 0;
}