#include <iostream>

// (n°C × 9/5) + 32 grau -> fahreheint
// (n°F − 32) × 5/9 fahreheint -> grau

using namespace std;

class Celsius{
  float grau;
  public:
    Celsius(const float grau = 0): grau(grau){};

    operator float() const {
      return grau;
    }

    float getGrau() const {
      return grau;
    }

    void setGrau(float grau) {
      this->grau = grau;
    }
};

class Fahrenheit{
  float grau;
  public:
    Fahrenheit(const float grau = 0): grau(grau){};

    operator float() const {
      return grau;
    }

    Fahrenheit(const Celsius grau){
      this->grau = (float) (grau * 9/5) + 32;
    }

    operator Celsius() const {
      return Celsius((grau - 32) * 5/9);
    }

    float getGrau() const {
      return grau;
    }

    void setGrau(float grau) {
      this->grau = grau;
    }
};

int main(){
  Celsius ce(145);
  Fahrenheit fe(145), fe2;

  fe2 = ce;

  cout << fe2;

  return 0;
}