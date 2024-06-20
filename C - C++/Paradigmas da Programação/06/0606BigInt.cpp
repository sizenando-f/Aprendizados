#include <iostream>
#include <vector>

using namespace std;

namespace minhaAula{
  namespace seila{
  class BigInt{
    vector<unsigned char> vNum;

    public:
    BigInt(unsigned num = 0){
      vNum.clear();
      vNum.reserve(3000);
      if(num == 0){
        vNum.push_back(0);
      }
      while(num != 0){
        vNum.push_back(num % 10);
        num /= 10;
      }
    }

    BigInt operator+(const BigInt &other) const {
      BigInt result;
      unsigned i = vNum.size();
      unsigned j = other.vNum.size();
      unsigned char transport = 0;

      i = j = 0;

      result.vNum.clear();
      while(i < vNum.size() && j < other.vNum.size()){
        result.vNum.push_back((vNum[i] + other.vNum[j] + transport) % 10);
        transport = (vNum[i] + other.vNum[j] + transport) / 10;
        ++i; 
        ++j;
      }
      
      while(i < vNum.size()){
        result.vNum.push_back((vNum[i] + transport) % 10);
        transport = (vNum[i] + transport) / 10;
        ++i;
      }

      while(j < other.vNum.size()){
        result.vNum.push_back((other.vNum[j] + transport) % 10);
        transport =(other.vNum[j] + transport) / 10;
        ++j;
      }

      if(transport){
        result.vNum.push_back(transport);
      }

      return result;
    }

    operator string() const {
      string str;
      int i;

      for(i = vNum.size() - 1; i >= 0; i--){
        str += '0' + vNum[i];
      }

      return str;
    }

    bool operator== (const unsigned &num) const {
      BigInt other(num);
      return *this == other;
    }

    bool operator== (const BigInt &other) const {
      if(this->vNum.size() != other.vNum.size()){
        return false;
      }
      for(unsigned i = 0; i < vNum.size(); i++){
        if(vNum[i] != other.vNum[i]){
          return false;
        }
      }
      return true;
    }

    BigInt operator*(const unsigned &num){
      BigInt result(0);

      for(unsigned i = 0; i < num; i++){
        result = result + (*this);
      }

      return result;
    }

    static BigInt fat(const unsigned &num) {
      BigInt myInt(1);

      for(unsigned i = 1; i <= num; i++){
        myInt = myInt * i;
      }

      return myInt;
    }

    };
  }
  class minhaClasse{};  // Dentro do MinhaAula mas fora de SeiLa
}

using namespace minhaAula::seila;
using namespace minhaAula;

int main(){
  // BigInt myInt;

  // myInt = myInt.fat(10000);

  // cout << (string) myInt;
  minhaClasse abc;
  cout << (string)(BigInt::fat(5));
  return 0;
}