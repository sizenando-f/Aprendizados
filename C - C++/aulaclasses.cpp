#include <iostream>

using namespace std;

class FacNumber{
  private:
    int num, den;

  public:
    // FacNumber() : num(0), den(1){
    // }

    FacNumber(const int num = 0, const int den = 1) : num(num), den(den){

    }

    ~FacNumber(){
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
};

int main(){
  FacNumber numfrac(5, 2), numfrac2, fracOther;

  cout << numfrac.getNum() << '/' << numfrac.getDen() << endl;
  // numfrac.setDen(2);
  // numfrac.setNum(1);
  // numfrac2.setDen(2);
  // numfrac2.setNum(1);

  // cout << numfrac.getNum() << "/" << numfrac.getDen() << endl;

  // fracOther = numfrac2.mult(numfrac); // Multiplica frações
  
  // cout << fracOther.getNum() << "/" << fracOther.getDen() << endl;
  return 0;
}