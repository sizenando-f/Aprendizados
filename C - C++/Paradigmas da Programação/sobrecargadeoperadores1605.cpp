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
    FacNumber mult(FacNumber other) const {
      FacNumber ret;

      ret.num = num * other.num;  // Faz parte da mesma classe, não precisa do this ou set/get
      ret.den = den * other.den;

      return ret;
    }

    FacNumber operator=(FacNumber other){
      num = other.num;
      den = other.den;

      return FacNumber(num+1, den);
    }
};

int main(){
  FacNumber f1(1,2), f2, f3;
  
  f3 = f2 = f1;

  cout << f3.getNum() << '/' << f3.getDen() << endl;
  return 0;
}