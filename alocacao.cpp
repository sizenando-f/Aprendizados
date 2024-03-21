#include <iostream>

using namespace std;

// class ComplexNumber{
//     float a, b;

//     public:
//     ComplexNumber() : a(0), b(0){   // Construtor Padrão
//     }

//     ComplexNumber(const float a, const float b) : a(a), b(b){   // Construtor Parametrizado
//     }

//     float getA() const {
//         return a;
//     }

//     float getB() const {
//         return b;
//     }

//     void setA(const float a){
//         this->a = a;
//     }

//     void setB(const float b){
//         this->b = b;
//     }


//     ComplexNumber soma(const ComplexNumber other) const {
//         return ComplexNumber(a + other.a, b + other.b);
//     }

// };

class FixSizeIntArray{
  int *ptr;
  unsigned size;

  public:
    FixSizeIntArray(unsigned size = 10): size(size), ptr(new int[size]){
    }
    unsigned getSize() const {
      return size;
    }

    void setElem(const int elem, unsigned i) const {
        ptr[i] = elem;
    }

    int getElem (unsigned i) const {
      return ptr[i];
    }

    int& at(unsigned i) const {
      return ptr[i];  // retorna endereço da posição
    }


    ~FixSizeIntArray(){
      delete []ptr;
    }

};

int main(){
  // ComplexNumber *ptr;
  // // ptr = (ComplexNumber*) malloc(sizeof(ComplexNumber));
  // ptr = new ComplexNumber(2.0, 3.0);
  // cout << ptr->getA() << endl;

  // // free(ptr);
  // delete ptr;

  FixSizeIntArray myArray;
  myArray.at(0) = 20;
  cout << myArray.at(0);

  return 0;
}