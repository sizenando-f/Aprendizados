#include <iostream>
#include <vector>

using namespace std;

class BigInt{
  vector<unsigned char> vNum;

  public:
  BigInt(unsigned char num = 0){
    vNum.clear();
    vNum.push_back(num % 10);
  }

  BigInt operator+(const BigInt &other) const {
    BigInt result;
    unsigned i = vNum.size();
    unsigned j = other.vNum.size();
    unsigned char transport = 0;

    while(i && j){
      --i; 
      --j;
      result.vNum.push_front((vNum[i] + other.vNum[j] + transport) % 10);
      transport = (vNum[i] + other.vNum[j]) / 10;
    }
    
    if(transport){
      result.push_front(transport);
    }

    return result;
  }
};

int main(){

  printf("%d", 'c' % '+');
  return 0;
}