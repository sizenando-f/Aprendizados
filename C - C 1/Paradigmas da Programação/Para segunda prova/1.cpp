#include <iostream>

using namespace std;

class Veiculo{
  string marca;
  int ano;
public:
  Veiculo(string m, int a):marca(m), ano(a){};
  Veiculo(){};

  void setMarca(const string m){
    marca = m;
  }

  void setAno(const int a){
    if(ano >= 1886){
      ano = a;
    }
  }

  string getMarca() const {
    return marca;
  }

  int getAno() const {
    return ano;
  }
};

class Carro: public Veiculo{
  string cor1, cor2, cor3, cor4;
public:
  Carro(string m, int a): cor1("branco"), cor2("branco"), cor3("branco"), cor4("branco"){
    setAno(a);
    setMarca(m);
  };
  Carro(){};

  void setCor1(const string cor){
    cor1 = cor;
  }

  void setCor2(const string cor){
    cor2 = cor;
  }

  void setCor3(const string cor){
    cor3 = cor;
  }

  void setCor4(const string cor){
    cor4 = cor;
  }

  string getCor1() const {
    return cor1;
  }

  string getCor2() const {
    return cor2;
  }

  string getCor3() const {
    return cor3;
  }

  string getCor4() const {
    return cor4;
  }
};

int main(){
  Carro c1;
  Veiculo v1;
  c1.setAno(2011);
  c1.setMarca("Volkswagen");
  c1.setCor1("Branco");
  cout << c1.getAno() << c1.getMarca() << c1.getCor1();
  return 0;
}