#include <iostream>

using namespace std;

class FacNumber{
    int num, den;

  public:
    FacNumber(const int num = 0, const int den = 1) : num(num), den(den){
    }

    void setDen(const int den){
      this->den = den;
    }
    void setNum(const int num){
      this->num = num;
    }
    int getDen() const {
      return den;
    }
    int getNum() const {
      return num;
    }

    FacNumber operator=(FacNumber other){
      num = other.num;
      den = other.den;

      return FacNumber(num+1, den);
    }

    FacNumber operator*(FacNumber other) const {
      return FacNumber(num * other.num, den * other.den);
    }

    FacNumber operator+(FacNumber other) const {
      return FacNumber(num * other.den + other.num * den, den * other.den);
    }

    FacNumber operator++(){ // Pré-fixado
      num += den;
      return FacNumber(num, den);
    }

    FacNumber operator++(int){ // Pós-fixado
      num += den;
      return FacNumber(num-den, den);
    }

    bool operator==(FacNumber other) const {
      return num/den == other.num/other.den; 
    }

    bool operator!=(FacNumber other) const {
      return num/den != other.num/other.den; // return !operator ==(other) | return !(*this==other);
    }

    bool operator>(FacNumber other) const {
      return num/den > other.num/other.den;
    }

    bool operator<(FacNumber other) const {
      return num/den < other.num/other.den;
    }

    bool operator>=(FacNumber other) const {
      return num/den >= other.num/other.den;
    }

    bool operator<=(FacNumber other) const {
      return num/den <= other.num/other.den;
    }
};

int main(){
  FacNumber f1(1,2), f2(1, 2), f3;
  
  f3 = ++f1;

  cout << f3.getNum() << '/' << f3.getDen() << endl;
  return 0;
}